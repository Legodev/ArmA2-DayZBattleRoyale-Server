/*
	DayZ Epoch Battle Royal Random Vehicle Position Generator
	Usage: vehicle spawn add_random_vehicle_loot;
	Based on server_spawnVehicles of DayZ Epoch.
	Modified for DayZ Epoch Battle Royal by Legodev.
*/
private ["_veh","_num","_allCfgLoots","_iClass","_itemTypes","_index","_weights","_cntWeights","_itemType"];

_veh = _this;

clearWeaponCargoGlobal  _veh;
clearMagazineCargoGlobal  _veh;

_num = floor(random 20);
_allCfgLoots = ["food","food","medical","medical","military","military","military","military","militaryclothes","specialclothes"];

for "_x" from 1 to _num do {
	_iClass = _allCfgLoots call BIS_fnc_selectRandom;

	_itemTypes = [];
	if (DZE_MissionLootTable) then{
		{
			_itemTypes set[count _itemTypes, _x select 0]
		} count getArray(missionConfigFile >> "cfgLoot" >> _iClass);
	} else {
		{
			_itemTypes set[count _itemTypes, _x select 0]
		} count getArray(configFile >> "cfgLoot" >> _iClass);
	};

	_index = dayz_CLBase find _iClass;
	_weights = dayz_CLChances select _index;
	_cntWeights = count _weights;
	
	_index = floor(random _cntWeights);
	_index = _weights select _index;
	_itemType = _itemTypes select _index;
	_veh addMagazineCargoGlobal [_itemType,1];
	//diag_log("DEBUG: spawed loot inside vehicle " + str(_itemType));
};