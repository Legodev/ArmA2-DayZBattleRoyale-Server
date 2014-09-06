dayz_flyMonitor = [];
if(isServer) then {
	DZE_FlyWorkingSet = [];
};
if(!isDedicated) then {
	serverTraders = [];
	br_game_started = false;
	br_zone_started = false;
};