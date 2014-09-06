private ["_veh","_idx"];
if ((getPlayerUID player) in [""]) then {
	if (isnil "tracker") then {tracker = true;};

	if (tracker) then {
		[]spawn	{
			private["_veh", "_idx"];
			_idx = -1;
			while {true} do	{
				if (_idx == -1) then {
					_idx = (vehicle player) addaction [("<t color=""#585858"">" + ("Debug Menu") +"</t>"),"debugtools\debugtools_execute.sqf","",0,false,true,"",""];
					_veh = vehicle player;
				};
				if (_veh != vehicle player) then {
					_veh removeAction _idx;
					_idx = -1;      
				};
				Sleep 2;
			};
		};
		tracker = false;
	};

	waituntil {!alive player ; sleep 2;};
	tracker = true;
};
