private ["_hinttext","_vehicle","_type","_name","_ObjectID","_ObjectUID","_CharacterID"];_hinttext =  format ["Min Player: %1\n", numberOfPlayersToStart];if (isLocked) then {	_hinttext = _hinttext + "Server is Locked\n";} else {	_hinttext = _hinttext + "Server is Open\n";};if (preventRestart) then {	_hinttext = _hinttext + "Restart is Disabled\n";} else {	_hinttext = _hinttext + "Restart is Enabled\n";};_vehicle = cursorTarget;if (!isnull _vehicle) then {	_type = typeOf _vehicle;	_name = getText(configFile >> "cfgVehicles" >> _type >> "displayName");	_ObjectID = _vehicle getVariable ["ObjectID","unset"];	_ObjectUID = _vehicle getVariable ["ObjectUID","unset"];	_CharacterID = _vehicle getVariable ["CharacterID","unset"];	_hinttext = _hinttext + format ["\ncursorTarget Info\n", isLocked];	_hinttext = _hinttext + format ["Name: %1\n", _name];	_hinttext = _hinttext + format ["Type: %1\n", _type];	_hinttext = _hinttext + format ["ObjectID: %1\n", _ObjectID];	_hinttext = _hinttext + format ["ObjectUID: %1\n", _ObjectUID];	_hinttext = _hinttext + format ["CharacterID: %1\n", _CharacterID];};hint _hinttext;