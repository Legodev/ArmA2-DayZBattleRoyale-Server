private ["_class","_uid","_charID","_object","_worldspace","_key"];
//[dayz_characterID,_tent,[_dir,_location],"TentStorage"]
_charID =		_this select 0;
_object = 		_this select 1;
_worldspace = 	_this select 2;
_class = 		_this select 3;
//_squad = 		_this select 4;
_squad = 0;

#include "\z\addons\dayz_server\compile\server_toggle_debug.hpp"
_combination = 0;
if (!(_object isKindOf "Building")) exitWith {
	deleteVehicle _object;
};
_allowed = [_object, "Server"] call check_publishobject;
if (!_allowed) exitWith { };

diag_log ("DSPO: Attempt " + str(_object));

//get UID
_uid = _worldspace call dayz_objectUID2;

_key = format["CHILD:308:%1:%2:%3:%4:%5:%6:%7:%8:%9:",dayZ_instance, _class, 0 , _charID, _worldspace, [], [], 0,_uid];


//diag_log ("HIVE: WRITE: "+ str(_key));
_key call server_hiveWrite;

_object setVariable ["ObjectUID", _uid,true];

if (_object isKindOf "TentStorage") then {
	_object addMPEventHandler ["MPKilled",{_this call vehicle_handleServerKilled;}];
};

PVDZE_serverObjectMonitor set [count PVDZE_serverObjectMonitor,_object];

#ifdef OBJECT_DEBUG
diag_log ("DSPO: Created " + (_class) + " with ID " + _uid + " and a combination of " + str(_combination) );
#endif
