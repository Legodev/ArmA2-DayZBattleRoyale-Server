/*
	DayZ Epoch Battle Royal Random Vehicle Array Generator
	Usage: length call ramdom_vehicles_array;
	Based on server_spawnVehicles of DayZ Epoch.
	Modified for DayZ Epoch Battle Royal by Legodev.
*/
private ["_vehCount","_vehArray","_carCount","_carLimit","_other","_bikes","_cars","_allowedVehiclesList","_random","_lastIndex","_index","_vehicle","_vehLimit","_isCar","_qty","_position","_dir","_veh","_objPosition","_marker"];


_vehCount = _this;
_vehArray = [];

_carCount = 0;
// only 25% are cars
_carLimit = floor(_vehCount * 0.25);

_other = [
  // Ships
  ["RHIB",1],
  // Helis
  ["AH6X_DZ",1]
];

_bikes = [
  ["Old_bike_TK_INS_EP1",50],
  // Motocycle
  ["M1030_US_DES_EP1",8],
  ["Old_moto_TK_Civ_EP1",8],
  ["TT650_Civ",8],
  ["TT650_Ins",8],
  ["TT650_TK_CIV_EP1",8],
  ["ATV_CZ_EP1",5],
  ["ATV_US_EP1",5]
];

_cars = [
  // Cars
  ["car_hatchback",1],
  ["car_sedan",1],
  ["datsun1_civil_1_open",1],
  ["datsun1_civil_2_covered",1],
  ["datsun1_civil_3_open",1],
  ["GLT_M300_LT",1],
  ["GLT_M300_ST",1],
  ["hilux1_civil_1_open",1],
  ["hilux1_civil_2_covered",1],
  ["hilux1_civil_3_open_EP1",1],
  ["HMMWV_Ambulance",1],
  ["HMMWV_Ambulance_CZ_DES_EP1",1],
  ["HMMWV_DZ",1],
  ["Kamaz",1],
  ["Lada1",1],
  ["Lada1_TK_CIV_EP1",1],
  ["Lada2",1],
  ["Lada2_TK_CIV_EP1",1],
  ["LadaLM",1],
  ["LandRover_TK_CIV_EP1",1],
  ["S1203_ambulance_EP1",1],
  ["S1203_TK_CIV_EP1",1],
  ["Skoda",1],
  ["SkodaBlue",1],
  ["SkodaGreen",1],
  ["SkodaRed",1],
  ["SUV_Blue",1],
  ["SUV_Camo",1],
  ["SUV_Charcoal",1],
  ["SUV_Green",1],
  ["SUV_Orange",1],
  ["SUV_Pink",1],
  ["SUV_Red",1],
  ["SUV_Silver",1],
  ["SUV_TK_CIV_EP1",1],
  ["SUV_White",1],
  ["SUV_Yellow",1],
  ["tractor",4],
  ["UAZ_CDF",1],
  ["UAZ_INS",1],
  ["UAZ_RU",1],
  ["UAZ_Unarmed_TK_CIV_EP1",1],
  ["UAZ_Unarmed_TK_EP1",1],
  ["UAZ_Unarmed_UN_EP1",1],
  ["Ural_CDF",1],
  ["Ural_TK_CIV_EP1",1],
  ["Ural_UN_EP1",1],
  ["VolhaLimo_TK_CIV_EP1",1],
  ["Volha_1_TK_CIV_EP1",1],
  ["Volha_2_TK_CIV_EP1",1],
  ["VWGolf",2]
];

_allowedVehiclesList = _other + _bikes + _cars;

while {count _allowedVehiclesList > 0 && count _vehArray < _vehCount} do {
	// BIS_fnc_selectRandom replaced because the index may be needed to remove the element
	_index = floor random count _allowedVehiclesList;
	_random = _allowedVehiclesList select _index;

	_vehicle = _random select 0;
	_vehLimit = _random select 1;
	
	
	_isCar = {(_x select 0) == _vehicle} count _cars;
	if (_isCar > 0) then {
		if (_carCount >= _carLimit) then {
			_vehLimit = -1;
		} else {
			_carCount = _carCount + 1;
		};
	};

	_qty = {(_x select 0) == _vehicle} count _vehArray;

	// If under limit allow to proceed
	if (_qty >= _vehLimit) then {
		// vehicle limit reached, remove vehicle from list
		// since elements cannot be removed from an array, overwrite it with the last element && cut the last element of (as long as order is not important)
		_lastIndex = (count _allowedVehiclesList) - 1;
		if (_lastIndex != _index) then {
			_allowedVehiclesList set [_index, _allowedVehiclesList select _lastIndex];
		};
		_allowedVehiclesList resize _lastIndex;
	} else {
		_vehArray set [count _vehArray,[_vehicle,0,[0,0,0]]];
	};
};

diag_log(format ["Created Random Vehicle Array with %1 of %2 Vehicles containing %3 of %4 possible Cars.", count _vehArray, _vehCount, _carCount, _carLimit]);

_vehArray