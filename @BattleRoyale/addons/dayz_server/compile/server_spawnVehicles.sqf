/*
	DayZ Epoch Battle Royal Vehicle Spawner
	Usage: call server_spawnVehicles;
	Based on server_spawnVehicles of DayZ Epoch.
	Modified for DayZ Epoch Battle Royal by Legodev.
*/
if (!isDedicated) exitWith { }; //Be sure the run this

private ["_map","_vehArray","_vehcount","_maplength","_mapX","_mapY","_inExcludedArea","_roadList","_random","_lastIndex","_index","_vehicle","_velimit","_qty","_position","_dir","_veh","_objPosition","_marker"];
_map = worldName;

_vehArray = [];

if ((preprocessFileLineNumbers format ["\z\addons\dayz_server\vehicles\%1_vehicles_array.sqf",_map]) != "") then {
	_vehArray = call compile preProcessFileLineNumbers format ["\z\addons\dayz_server\vehicles\%1_vehicles_array.sqf",_map];
} else {
	diag_log format ["Did not find static vehicle spawn file for Map %1",_map];
};

_vehcount = count _vehArray;

if(DZEBR_DynamicVehicleSpawn || _vehcount == 0) then {
	// need to apply an random position
	DZEBR_RandomVehiclePosition = true;
	if (_vehcount == 0) then {
		if(isnil "MaxVehicleLimit") then {
			MaxVehicleLimit = 50;
		};
		_vehcount = MaxVehicleLimit;
	};
	_vehArray = _vehcount call compile preProcessFileLineNumbers "\z\addons\dayz_server\vehicles\random_vehicles_array.sqf";
};

if(DZEBR_RandomVehiclePosition) then {
	/**************************************************/
	/*** Begin of Epoch Variables for Vehicle Spawn ***/
	/**************************************************/
	if(isnil "dayz_MapArea") then {
		dayz_MapArea = 10000;
	};
	if(isnil "DynamicVehicleArea") then {
		DynamicVehicleArea = dayz_MapArea / 2;
	};

	// Get all buildings && roads only once TODO: set variables to nil after done if necessary 
	MarkerPosition = getMarkerPos "center";
	//RoadList = MarkerPosition nearRoads DynamicVehicleArea;

	// Very taxing !!! but only on first startup
	/*
	BuildingList = [];
	{
		if (DZE_MissionLootTable) then {
			if (isClass (missionConfigFile >> "CfgBuildingLoot" >> (typeOf _x))) then
			{
					BuildingList set [count BuildingList,_x];
			};
		} else {
			if (isClass (configFile >> "CfgBuildingLoot" >> (typeOf _x))) then
			{
				BuildingList set [count BuildingList,_x];
			};
		};
	} count (MarkerPosition nearObjects ["building",DynamicVehicleArea]);
	*/
	/**************************************************/
	/**** End of Epoch Variables for Vehicle Spawn ****/
	/**************************************************/
	
	VehicleSpawnRoadList = [];
	VehicleSpawnBuildingList = [];
	
	waitUntil{!isNil "BIS_fnc_selectRandom"};
	if(isnil "DZEBR_VehicleSpawnMinX") then {
		DZEBR_VehicleSpawnMinX = (MarkerPosition select 0) - DynamicVehicleArea + 100;
	};
	if(isnil "DZEBR_VehicleSpawnMaxX") then {
		DZEBR_VehicleSpawnMaxX = (MarkerPosition select 0) + DynamicVehicleArea + 100;
	};
	if(isnil "DZEBR_VehicleSpawnMinY") then {
		DZEBR_VehicleSpawnMinY = (MarkerPosition select 1) - DynamicVehicleArea + 100;
	};
	if(isnil "DZEBR_VehicleSpawnMaxY") then {
		DZEBR_VehicleSpawnMaxY = (MarkerPosition select 1) + DynamicVehicleArea + 100;
	};
	if(isnil "DZEBR_VehicleSpawnExcludedArea") then {
		DZEBR_VehicleSpawnExcludedArea = [];
	};

	for [{_mapX=DZEBR_VehicleSpawnMinX},{_mapX<=DZEBR_VehicleSpawnMaxX},{_mapX=_mapX+200}] do {
		for [{_mapY=DZEBR_VehicleSpawnMinY},{_mapY<=DZEBR_VehicleSpawnMaxY},{_mapY=_mapY+200}] do {
			 _inExcludedArea = false;
			{
				_areaCenter = _x select 0;
				_areaRadius = _x select 1;
				
				if ([_mapX,_mapY] distance _areaCenter < _areaRadius) then {
					_inExcludedArea = true;
				};
			} forEach DZEBR_VehicleSpawnExcludedArea;

			if (!_inExcludedArea) then {
				_roadList = [_mapX,_mapY] nearRoads 100;
				if (count _roadList > 0) then {
					VehicleSpawnRoadList set [count VehicleSpawnRoadList,_roadList call BIS_fnc_selectRandom];
				};

				_buildingList = [];
				{
					if (DZE_MissionLootTable) then {
						if (isClass (missionConfigFile >> "CfgBuildingLoot" >> (typeOf _x))) then
						{
								_buildingList set [count _buildingList,_x];
						};
					} else {
						if (isClass (configFile >> "CfgBuildingLoot" >> (typeOf _x))) then
						{
							_buildingList set [count _buildingList,_x];
						};
					};
				} count ([_mapX,_mapY] nearObjects ["building",100]);
				if (count _buildingList > 0) then {
					VehicleSpawnBuildingList set [count VehicleSpawnBuildingList,_buildingList call BIS_fnc_selectRandom];
				};

				// show scan area
				if (DZEdebug) then {
					_marker = createMarker [str [_mapX,_mapY], [_mapX,_mapY]];
					_marker setMarkerColor "ColorRed";
					_marker setMarkerShape "ELLIPSE";
					_marker setMarkerBrush "Grid";
					_marker setMarkerSize [100,100];
					_marker setMarkerText str [_mapX,_mapY];
				};
			};
		};
	};

	random_vehicles_position = compile preprocessFileLineNumbers "\z\addons\dayz_server\vehicles\random_vehicles_position.sqf";
};

add_random_vehicle_loot = compile preprocessFileLineNumbers "\z\addons\dayz_server\vehicles\add_random_vehicle_loot.sqf";

_vehcount = 0;
{
	_vehicleClass = _x select 0;
	_dir = _x select 1;
	_position = _x select 2;

	if(DZEBR_RandomVehiclePosition) then {
		_dir = round(random 360);
		_position = _vehicleClass call random_vehicles_position;
	};
	
	//place vehicle 
	_veh = createVehicle [_vehicleClass, _position, [], 0, "CAN_COLLIDE"];
	_vehcount = _vehcount + 1;
	_veh setdir _dir;
	_veh setpos _position;
	_veh setVariable ["ObjectID", (str _vehcount), true];
	_veh setVariable ["lastUpdate", time];
	_veh setVariable ["CharacterID", "0", true];

	if(DZEdebug) then {
		_marker = createMarker [str(_position) , _position];
		_marker setMarkerShape "ICON";
		_marker setMarkerType "DOT";
		_marker setMarkerText _vehicleClass;
	};

	if(DZEBR_RandomVehicleLoot) then {
			_veh spawn add_random_vehicle_loot;
	};
} forEach _vehArray;