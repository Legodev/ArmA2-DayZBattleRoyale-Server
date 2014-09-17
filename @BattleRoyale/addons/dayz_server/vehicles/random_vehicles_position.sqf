/*
	DayZ Epoch Battle Royal Random Vehicle Position Generator
	Usage: vehicle call random_vehicles_position;
	Based on server_spawnVehicles of DayZ Epoch.
	Modified for DayZ Epoch Battle Royal by Legodev.
*/
waitUntil{!isNil "BIS_fnc_findSafePos"};

private ["_vehicle","_isAir","_isShip","_position","_spawnNearRoad","_spawnNearBuilding","_istoomany","_rounds","_index","_lastIndex"];
_vehicle = _this;
_position = [0,0,0];
_rounds = 0;
_istoomany = [0];

// Find Vehicle Type to better control spawns
_isAir = _vehicle isKindOf "Air";
_isShip = _vehicle isKindOf "Ship";
_isMotorcycle = _vehicle isKindOf "Motorcycle";

while {(count _istoomany) > 0 && _rounds < 5} do {
	if(_isShip || _isAir) then {
		if(_isShip) then {
			// Spawn anywhere on coast on water
			_position = [MarkerPosition,0,DynamicVehicleArea,10,1,2000,1] call BIS_fnc_findSafePos;
		} else {
			// Spawn air anywhere that is flat
			_position = [MarkerPosition,0,DynamicVehicleArea,10,0,2000,0] call BIS_fnc_findSafePos;
		};
	} else {
		// Spawn around buildings && 75% near roads
		//_spawnNearRoad = (random 1) > 0.25 && !_isMotorcycle && count VehicleSpawnRoadList > 0;
		_spawnNearRoad = (random 1) > 0.25 && count VehicleSpawnRoadList > 0;
		_spawnNearBuilding = !_spawnNearRoad && count VehicleSpawnBuildingList > 0;
		
		if (_spawnNearRoad) then {
			_index = floor random count VehicleSpawnRoadList;
			_position = VehicleSpawnRoadList select _index;
			
			_lastIndex = (count VehicleSpawnRoadList) - 1;
			if (_lastIndex != _index) then {
				VehicleSpawnRoadList set [_index, VehicleSpawnRoadList select _lastIndex];
			};
			VehicleSpawnRoadList resize _lastIndex;
			
			_position = _position modelToWorld [0,0,0];
			_position = [_position,0,10,10,0,2000,0] call BIS_fnc_findSafePos;
		};
		
		if (_spawnNearBuilding) then {
			_index = floor random count VehicleSpawnBuildingList;
			_position = VehicleSpawnBuildingList select _index;
			
			_lastIndex = (count VehicleSpawnBuildingList) - 1;
			if (_lastIndex != _index) then {
				VehicleSpawnBuildingList set [_index, VehicleSpawnBuildingList select _lastIndex];
			};
			VehicleSpawnBuildingList resize _lastIndex;
		
			_position = _position modelToWorld [0,0,0];
			_position = [_position,0,40,5,0,2000,0] call BIS_fnc_findSafePos;
		};
		
		if (!(_spawnNearRoad || _spawnNearBuilding)) then {
			_position = [MarkerPosition,0,DynamicVehicleArea,10,0,2000,0] call BIS_fnc_findSafePos;
		};
	};
	_istoomany = _position nearObjects ["AllVehicles",50];
	_rounds = _rounds + 1;
};

_position
