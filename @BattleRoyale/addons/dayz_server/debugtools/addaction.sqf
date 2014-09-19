private ["_veh","_idx"];

RunOnServer = {
	DebugToolsServerAction = [player,_this]; 
	publicVariable "DebugToolsServerAction";
};

ActionMenu = [
	["",true],
		["Lock Server", [2],  "", -5, [["expression", '"LockServer" call RunOnServer']], "1", "1"],
		["UnLock Server", [3],  "", -5, [["expression", '"UnLockServer" call RunOnServer']], "1", "1"],
		["StartRound", [4],  "", -5, [["expression", '"StartRound" call RunOnServer']], "1", "1"],
		["Restart Server", [5],  "", -5, [["expression", '"RestartServer" call RunOnServer']], "1", "1"],
		["Prevent Restart", [6],  "", -5, [["expression", '"preventRestart" call RunOnServer']], "1", "1"],
		["Read Variables", [7],  "", -5, [["expression", 'call readVariables']], "1", "1"],
		["List Objects", [8],  "", -5, [["expression", 'call listObjects']], "1", "1"],
		["Disconnect", [9],  "", -5, [["expression", 'endMission "END1"; forceEnd;']], "1", "1"],
		["Disconnect (S)", [10],  "", -5, [["expression", '"disconnect" call RunOnServer']], "1", "1"],
		["", [-1], "", -5, [["expression", ""]], "1", "0"],
		["Exit", [13], "", -3, [["expression", ""]], "1", "1"]
];

ActionMenu_helper = {showCommandingMenu "#USER:ActionMenu";};

if (isnil "tracker") then {tracker = true;};

if (tracker) then {
	[]spawn	{
		private["_veh", "_idx"];
		_idx = -1;
		while {true} do	{
			if (_idx == -1) then {
				_idx = (vehicle player) addaction [("<t color=""#585858"">" + ("Debug Menu") +"</t>"),"ca\modules\MP\data\scriptCommands\moveIn.sqf","Driver (call ActionMenu_helper);",5,false,false,"",""];
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