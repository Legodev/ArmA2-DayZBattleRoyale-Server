initialized = false;
dayz_previousID = 0;
dayZ_instance =	1;
dayZ_serverName="DZEBR";
dayz_MapArea = 5000;
// Battle Royal Options
END_TIME = 4500;
numberOfPlayersToStart = 3;
DZEBR_DynamicVehicleSpawn = false;
DZEBR_RandomVehiclePosition = false;
DZEBR_RandomVehicleLoot = false;
DZEBR_VehicleSpawnExcludedArea = [[[1150,8950],1000]];
// Epoch Options
DZE_MissionLootTable = true;

if (isServer) then {
	call compile preprocessFileLineNumbers "\z\addons\dayz_server\init\server_mission_init.sqf";
};

if (isLocked) then {
	startLoadingScreen ["You can't join the mission because the round has already started - you will be kicked in 10 seconds. See you later!","RscDisplayLoadCustom"];
	_seconds = 0.0;
	while {_seconds < 1.0} do {
		_seconds = _seconds + 0.1;
		progressLoadingScreen _seconds;
		sleep 1;
	};
	endLoadingScreen;
	call compile ('endMission "END1";');
	call compile ('forceEnd;');
} else {
	/*	
		INITILIZATION
	*/
	startLoadingScreen ["","RscDisplayLoadCustom"];
	cutText ["","BLACK OUT"];
	enableSaving [false, false];

	CBA_display_ingame_warnings = false; 
	publicVariable "CBA_display_ingame_warnings";

	//REALLY IMPORTANT VALUES
	dayzHiveRequest = [];

	//disable greeting menu
	player setVariable ["BIS_noCoreConversations", true];
	//disable radio messages to be heard and shown in the left lower corner of the screen
	enableRadio false;

	//Load in compiled functions
	call compile preprocessFileLineNumbers "\z\addons\dayz_code\init\variables.sqf";				//Initilize the Variables (IMPORTANT: Must happen very early)
	call compile preprocessFileLineNumbers "variables.sqf";
	progressLoadingScreen 0.1;
	call compile preprocessFileLineNumbers "\z\addons\dayz_code\init\publicEH.sqf";					//Initilize the publicVariable event handlers
	progressLoadingScreen 0.2;
	call compile preprocessFileLineNumbers "\z\addons\dayz_code\medical\setup_functions_med.sqf";	//Functions used by CLIENT for medical
	progressLoadingScreen 0.4;
	call compile preprocessFileLineNumbers "\z\addons\dayz_code\init\compiles.sqf";					//Compile regular functions
	player_dumpBackpack = {
		sleep 100;
	};
	progressLoadingScreen 1.0;
	call compile preprocessFileLineNumbers "\z\addons\br_assets\scripts\shk_pos\shk_pos_init.sqf";					//Compile random marker position


	/* BIS_Effects_* fixes from Dwarden */
	BIS_Effects_EH_Killed = compile preprocessFileLineNumbers "\z\addons\dayz_code\system\BIS_Effects\killed.sqf";
	BIS_Effects_AirDestruction = compile preprocessFileLineNumbers "\z\addons\dayz_code\system\BIS_Effects\AirDestruction.sqf";
	BIS_Effects_AirDestructionStage2 = compile preprocessFileLineNumbers "\z\addons\dayz_code\system\BIS_Effects\AirDestructionStage2.sqf";

	BIS_Effects_globalEvent = {
		BIS_effects_gepv = _this;
		publicVariable "BIS_effects_gepv";
		_this call BIS_Effects_startEvent;
	};

	BIS_Effects_startEvent = {
		switch (_this select 0) do {
			case "AirDestruction": {
					[_this select 1] spawn BIS_Effects_AirDestruction;
			};
			case "AirDestructionStage2": {
					[_this select 1, _this select 2, _this select 3] spawn BIS_Effects_AirDestructionStage2;
			};
			case "Burn": {
					[_this select 1, _this select 2, _this select 3, false, true] spawn BIS_Effects_Burn;
			};
		};
	};

	"BIS_effects_gepv" addPublicVariableEventHandler {
		(_this select 1) call BIS_Effects_startEvent;
	};

	if ((!isServer) && (isNull player) ) then
	{
		waitUntil {!isNull player};
		waitUntil {time > 3};
	};

	if ((!isServer) && (player != player)) then
	{
		waitUntil {player == player};
		waitUntil {time > 3};
	};

	if (isServer) then {
		hiveInUse	=	true;
		_serverMonitor = [] execVM "\z\addons\dayz_code\system\server_monitor.sqf";
		// "PVDZ_sec_atp" addPublicVariableEventHandler { diag_log format["%1", _this select 1];};
	};

	if (!isDedicated) then {
		"filmic" setToneMappingParams [0.153, 0.357, 0.231, 0.1573, 0.011, 3.750, 6, 4];
		setToneMapping "Filmic";
		setviewdistance 2500;
		//Conduct map operations
		0 fadeSound 0;
		waitUntil {!isNil "dayz_loadScreenMsg"};
		dayz_loadScreenMsg = (localize "STR_AUTHENTICATING");
		
		//Run the player monitor
		_id = player addEventHandler ["Respawn", {_id = [] spawn player_death;}];
		_playerMonitor = [] execVM "\z\addons\dayz_code\system\player_monitor.sqf";
		
		[] spawn {
			waitUntil {!isNil "Dayz_logonTime"};
			[] execVM "\z\addons\br_assets\scripts\fn_startlock.sqf";
			[] execVM "fn_startZombieProtection.sqf";
			player addAction [("<t color=""#585858"">" + ("Disconnect") +"</t>"),"disconnect.sqf","",5,false,true,"","!isLocked"];
		};
	};

	// Logo watermark: adding a logo in the bottom left corner of the screen with the server name in it
	if (!isNil "dayZ_serverName") then {
		[] spawn {
			waitUntil {(!isNull Player) and (alive Player) and (player == player)};
			waituntil {!(isNull (findDisplay 46))};
			5 cutRsc ["wm_disp","PLAIN"];
			((uiNamespace getVariable "wm_disp") displayCtrl 1) ctrlSetText dayZ_serverName;
		};
	};

	if (!isDedicated) then {	
		call compile preProcessFileLineNumbers "\z\addons\br_assets\scripts\fn_playercheck.sqf";	
		call compile preProcessFileLineNumbers "\z\addons\br_assets\scripts\fn_punish.sqf";
	};
};
0 fadesound 0;
Sleep 5;
0 fadesound 1;
