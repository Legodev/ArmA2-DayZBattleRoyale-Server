pathtoscripts = "debugtools\tools\";
EXECscript1 = 'player execVM "'+pathtoscripts+'%1"';

debugtools =
[
	["",true],
		["Lock Server", [2],  "", -5, [["expression", format[EXECscript1,"lock.sqf"]]], "1", "1"],
		["UnLock Server", [3],  "", -5, [["expression", format[EXECscript1,"unlock.sqf"]]], "1", "1"],
		["Force Start", [4],  "", -5, [["expression", format[EXECscript1,"forcestart.sqf"]]], "1", "1"],
		["Force Restart", [5],  "", -5, [["expression", format[EXECscript1,"forcerestart.sqf"]]], "1", "1"],
		["Prevent Restart", [6],  "", -5, [["expression", format[EXECscript1,"preventrestart.sqf"]]], "1", "1"],
		["Read Variables", [7],  "", -5, [["expression", format[EXECscript1,"readVariables.sqf"]]], "1", "1"],
		["List Objects", [8],  "", -5, [["expression", format[EXECscript1,"listObjects.sqf"]]], "1", "1"],
		["Disconnect", [9],  "", -5, [["expression", format[EXECscript1,"disconnect.sqf"]]], "1", "1"],
		["", [-1], "", -5, [["expression", ""]], "1", "0"],
			["Exit", [13], "", -3, [["expression", ""]], "1", "1"]
];

showCommandingMenu "#USER:debugtools";