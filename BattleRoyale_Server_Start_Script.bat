:: Arma Server Starter by lazyink (PLAYERUNKNOWN) : modified by @Pwnoz0r, Legodev

@echo off

:: MAKE SURE TO CHANGE THESE BEFORE STARTING THE SERVER!
:: Directory Settings
:: Example: C:\Users\Administrator\Desktop\ArmA2OA
set ARMADIR=<PATH TO THE ROOT OF YOUR GAME SERVER>
:: Example: C:\Program Files\MySQL\MySQL Server 5.6\bin
set MYSQLDIR=<PATH TO THE BIN FOLDER OF YOUR MYSQL SERVER DIRECTORY>
:: Database Settings
set MYSQLHOST=127.0.0.1
set MYSQLUSER=dayz
set MYSQLPASS=dayz
SET MYSQLDB=battleroyale

cls
title Lazy's DayZ Battle Royale Server Starter

:brstart

"%MYSQLDIR%\mysql.exe" -h %MYSQLHOST% --user=%MYSQLUSER% --password=%MYSQLPASS% --database=%MYSQLDB% --execute="delete from object_data;"
"%MYSQLDIR%\mysql.exe" -h %MYSQLHOST% --user=%MYSQLUSER% --password=%MYSQLPASS% --database=%MYSQLDB% --execute="UPDATE character_data SET Inventory='[[],[]]';"
"%MYSQLDIR%\mysql.exe" -h %MYSQLHOST% --user=%MYSQLUSER% --password=%MYSQLPASS% --database=%MYSQLDB% --execute="UPDATE character_data SET Backpack='["",[],[]]';"
"%MYSQLDIR%\mysql.exe" -h %MYSQLHOST% --user=%MYSQLUSER% --password=%MYSQLPASS% --database=%MYSQLDB% --execute="UPDATE character_data SET Worldspace='[]';"
"%MYSQLDIR%\mysql.exe" -h %MYSQLHOST% --user=%MYSQLUSER% --password=%MYSQLPASS% --database=%MYSQLDB% --execute="UPDATE character_data SET Model='"Survivor2_DZ"';"
"%MYSQLDIR%\mysql.exe" -h %MYSQLHOST% --user=%MYSQLUSER% --password=%MYSQLPASS% --database=%MYSQLDB% --execute="UPDATE character_data SET Humanity='4500';"
"%MYSQLDIR%\mysql.exe" -h %MYSQLHOST% --user=%MYSQLUSER% --password=%MYSQLPASS% --database=%MYSQLDB% --execute="UPDATE character_data SET currentState='[]';"
"%MYSQLDIR%\mysql.exe" -h %MYSQLHOST% --user=%MYSQLUSER% --password=%MYSQLPASS% --database=%MYSQLDB% --execute="UPDATE character_data SET Medical='[]';"
echo (%time%)DayZ Battle Royale Charater Data Reset
timeout 1

if exist brmissionfiles\dayz_server.pbo copy /Y brmissionfiles\dayz_server.pbo @BattleRoyale\addons\dayz_server.pbo

set /a brmap=%random% %%4
goto %brmap%

:0
echo (%time%) DayZ Battle Royale Kulima Server was started...
timeout 1
cd "%ARMADIR%"
set mission=dayz_1.kulima
if exist %mission%\Arma2OAserver.RPT move /Y %mission%\Arma2OAserver.RPT %mission%\Arma2OAserver_old.RPT
if exist %mission%\HiveExt.log move /Y %mission%\HiveExt.log %mission%\HiveExt_old.log
if exist brmissionfiles\%mission%.pbo copy /Y brmissionfiles\%mission%.pbo MPMissions\%mission%.pbo
start /wait .\arma2oaserver.exe -port=8033 -mod=@DayZBattleRoyale;@DayZ_Epoch;@DayZ_Epoch_BattleRoyale;@BattleRoyale;Expansion\beta\Expansion; -name=%mission% -config=%mission%\config_stable.cfg -cfg=%mission%\basic.cfg -profiles=%mission% cpuCount=4 -world=kulima -exThreads=1 -bandwidthAlg=2 -maxMem=2047
timeout 1
goto brstart
:1
echo (%time%) DayZ Battle Royale Isola di Capraia Server was started...
timeout 1
cd "%ARMADIR%"
set mission=dayz_1.isoladicapraia
if exist %mission%\Arma2OAserver.RPT move /Y %mission%\Arma2OAserver.RPT %mission%\Arma2OAserver_old.RPT
if exist %mission%\HiveExt.log move /Y %mission%\HiveExt.log %mission%\HiveExt_old.log
if exist brmissionfiles\%mission%.pbo copy /Y brmissionfiles\%mission%.pbo MPMissions\%mission%.pbo
start /wait .\arma2oaserver.exe -port=8033 -mod=@DayZBattleRoyale;@DayZ_Epoch;@DayZ_Epoch_BattleRoyale;@BattleRoyale;Expansion\beta;Expansion\beta\Expansion; -name=%mission% -config=%mission%\config_stable.cfg -cfg=%mission%\basic.cfg -profiles=%mission% cpuCount=4 -world=isoladicapraia -exThreads=1 -bandwidthAlg=2 -maxMem=2047
timeout 1
goto brstart
:2
echo (%time%) DayZ Battle Royale Emita Server was started...
timeout 1
cd "%ARMADIR%"
set mission=dayz_1.emita
if exist %mission%\Arma2OAserver.RPT move /Y %mission%\Arma2OAserver.RPT %mission%\Arma2OAserver_old.RPT
if exist %mission%\HiveExt.log move /Y %mission%\HiveExt.log %mission%\HiveExt_old.log
if exist brmissionfiles\%mission%.pbo copy /Y brmissionfiles\%mission%.pbo MPMissions\%mission%.pbo
start /wait .\arma2oaserver.exe -port=8033 -mod=@DayZBattleRoyale;@DayZ_Epoch;@DayZ_Epoch_BattleRoyale;@BattleRoyale;Expansion\beta;Expansion\beta\Expansion; -name=%mission% -config=%mission%\config_stable.cfg -cfg=%mission%\basic.cfg -profiles=%mission% cpuCount=4 -world=emita -exThreads=1 -bandwidthAlg=2 -maxMem=2047
timeout 1
goto brstart
:3
echo (%time%) DayZ Battle Royale F.A.T.A Server was started...
timeout 1
cd "%ARMADIR%"
set mission=dayz_1.fata
if exist %mission%\Arma2OAserver.RPT move /Y %mission%\Arma2OAserver.RPT %mission%\Arma2OAserver_old.RPT
if exist %mission%\HiveExt.log move /Y %mission%\HiveExt.log %mission%\HiveExt_old.log
if exist brmissionfiles\%mission%.pbo copy /Y brmissionfiles\%mission%.pbo MPMissions\%mission%.pbo
start /wait .\arma2oaserver.exe -port=8033 -mod=@DayZBattleRoyale;@DayZ_Epoch;@DayZ_Epoch_BattleRoyale;@BattleRoyale;Expansion\beta;Expansion\beta\Expansion; -name=%mission% -config=%mission%\config_stable.cfg -cfg=%mission%\basic.cfg -profiles=%mission% cpuCount=4 -world=fata -exThreads=1 -bandwidthAlg=2 -maxMem=2047
timeout 1
goto brstart