#include "script_component.hpp"
/*
 * Author: Javasparrow
 * Local callback for checking the player temperature.
 *
 * Arguments:
 * 0: Medic <OBJECT>
 * 1: Patient <OBJECT>
 *
 * Return Value:
 * None
 *
 * Example:
 * call kat_breathing_fnc_checkTemperatureLocal
 *
 * Public: No
 */
 
params ["_player", "_target"];

private _Temp = 0;
private _showTemp = 0;
private _offset = 0;

if (alive _target) then {
    _Temp = _patient getVariable [GVAR(Temperature), 100];
};

if (GVAR(enable_Temperature_offset)) then {
    switch (_medic getVariable ["ace_medical_medicClass",0]) do {
        case 0: {
            _offset = GVAR(Temperature_offset_Default);
            _showTemp = random [(_Temp - _offset), _Temp, (_Temp + _offset)];
        };
        case 1: {
            _offset = GVAR(Temperature_offset_RegularMedic);
            _showTemp = random [(_Temp - _offset), _Temp, (_Temp + _offset)];
        };
        case 2: {
            _offset = GVAR(Temperature_offset_Doctor);
            _showTemp = random [(_Temp - _offset), _Temp, (_Temp + _offset)];
        };
    };
};

private _message = format ["%1",_showTemp];
[_message, 2, _player] call ace_common_fnc_displayTextStructured;

[_target, "quick_view", LSTRING(CheckTemperature_Log), [_showTemp]] call ace_medical_treatment_fnc_addToLog;
