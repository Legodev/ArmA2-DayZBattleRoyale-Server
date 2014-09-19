AdminList = [];
if ((preProcessFileLineNumbers ("super_admins.sqf")) != "") then {
	_tmpAdmin = call compile preProcessFileLineNumbers "super_admins.sqf";
	AdminList = AdminList + _tmpAdmin;
};

DebugToolsServerAction = [];
"DebugToolsServerAction" addPublicVariableEventHandler {
	private ["_Player","_PlayerUID","_Action"];
	_Player = DebugToolsServerAction select 0;
	_PlayerUID = getPlayerUID _Player;
	_Action = DebugToolsServerAction select 1;

	diag_log(format["Player %1 wants to execute %2", _PlayerUID, _Action]);

	if (_PlayerUID in AdminList) then { 
		diag_log(format["Player %1 is an Admin, going to execute %2", _PlayerUID, _Action]);
		switch (_Action) do { 
			case "RestartServer": {
				[] spawn {
					[nil, nil, rTitleText, "The server is forced to restart in 10 seconds!", "PLAIN"] call RE;
					sleep 5;
					[nil, nil, rTitleText, "The server is forced to restart in 5 seconds!", "PLAIN"] call RE;
					sleep 5;
					//[nil,nil, rENDMISSION, "End1"] call RE;
					[nil, nil, rSPAWN, [], {endMission 'END1'; forceEnd;}] call RE;
					sleep 2;
					[] spawn server_restart;
				};
			}; 
			case "StartRound": { 
				numberOfPlayersToStart = 1;
				publicVariable "numberOfPlayersToStart"; 
			};
			case "LockServer": { 
				[] spawn server_lock; 
			}; 
			case "UnLockServer": { 
				[] spawn server_unlock;
			};
			case "preventRestart": { 
				preventRestart = true;
				publicVariable "preventRestart"; 
			};
			case "allowRestart": { 
				preventRestart = false;
				publicVariable "preventRestart"; 
			};
			case "disconnect": {
				[objNull, _Player, rSPAWN, [], {endMission 'END1'; forceEnd;}] call RE;
			};
			default { diag_log(format["%1 does not exist", _Action]); }; 
		};
	} else {
		diag_log(format["Player %1 is not an Admin, will not execute %2", _PlayerUID, _Action]);
	};
};