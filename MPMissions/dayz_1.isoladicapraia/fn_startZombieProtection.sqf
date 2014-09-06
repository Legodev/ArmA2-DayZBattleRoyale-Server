private ["_initialPos","_zombies"];

_initialPos = position player;

while{!br_game_started} do {
	sleep 5;
	_zombies = _initialPos nearEntities ["zZombie_Base",250];
	{deletevehicle _x;} forEach _zombies;
};