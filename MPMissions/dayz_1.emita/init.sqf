dayZ_instance =	1;
dayZ_serverName="DayZBR";
END_TIME = 4500;
if (isServer) then {
        RoundStarted = false;
        publicVariable "RoundStarted";
} else {
        waitUntil {!isNil RoundStarted};
        if (RoundStarted) then {
                cutText ["round already started\nyou cannot join","PLAIN",2];
                sleep 5;
                call compile ('endMission ''END1'';');
                call compile ('forceEnd;');
        };
};
#include "\z\addons\dayz_code\system\mission\init.sqf"
0 fadesound 0;
Sleep 5;
0 fadesound 1;
