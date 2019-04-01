#define QQPATHTOF(var1) QUOTE(QPATHTOF(var1))

class CfgVehicles {
    class WeaponHolder_Single_limited_item_F;
    //class adv_aceCPR_AEDItem;
    class NATO_Box_Base;
    class ACE_medicalSupplyCrate: NATO_Box_Base {
        class TransportItems;
        class TransportMagazines;
    };

    class kat_PainkillerItem: WeaponHolder_Single_limited_item_F {
        scope = 2;
        scopeCurator = 2;
        displayName= CSTRING(Painkillers_Box_Display);
        author = "Katalam";
        vehicleClass = "Magazines";
        class TransportItems {
            MACRO_ADDITEM(kat_Painkiller,1);
        };
    };
    /*
    class kat_X_AEDItem: adv_aceCPR_AEDItem {
        scope = 2;
        scopeCurator = 2;
        displayName = CSTRING(X_Display);
        author = "Katalam";
        class TransportItems {
            MACRO_ADDITEM(kat_X_AED,1);
        };
    };
    */


    class ACE_medicalSupplyCrate_advanced: ACE_medicalSupplyCrate {
        /*
        class TransportItems: TransportItems {
            MACRO_ADDITEM(kat_X_AED,1);
        };
        */
        class TransportMagazines: TransportMagazines {
            MACRO_ADDMAGAZINE(kat_painkiller,10);
        };
    };
    class kat_medicalSupplyCrate: ACE_medicalSupplyCrate {
        displayName = CSTRING(bloodbank);
        class TransportItems: TransportItems {
            MACRO_ADDITEM(kat_crossPanel,5);
            MACRO_ADDITEM(kat_bloodIV_O,5);
            MACRO_ADDITEM(kat_bloodIV_A,10);
            MACRO_ADDITEM(kat_bloodIV_B,10);
            MACRO_ADDITEM(kat_bloodIV_AB,10);
            MACRO_ADDITEM(kat_bloodIV_O_500,5);
            MACRO_ADDITEM(kat_bloodIV_A_500,10);
            MACRO_ADDITEM(kat_bloodIV_B_500,10);
            MACRO_ADDITEM(kat_bloodIV_AB_500,10);
            MACRO_ADDITEM(kat_bloodIV_O_250,5);
            MACRO_ADDITEM(kat_bloodIV_A_250,10);
            MACRO_ADDITEM(kat_bloodIV_B_250,10);
            MACRO_ADDITEM(kat_bloodIV_AB_250,10);
        };
    };

    class Man;
    class CAManBase: Man {
        class ACE_Actions {
            class ACE_Dogtag {
                condition = "[_player, _target] call ace_dogtags_fnc_canCheckDogtag";
            };
        };
        class ACE_SelfActions {
            class ACE_Equipment {
                /*
                class removeSound {
                    displayName = CSTRING(X_Action_removeSound);
                    condition = QUOTE('kat_X_AED' in (items _player) && !((_player getVariable QQGVAR(X_sound1)) isEqualTo ''));
                    statement = QUOTE(_player setVariable [ARR_3(QQGVAR(X_sound1), '', true)]; _player setVariable [ARR_3(QQGVAR(X_sound2), '', true)];);
                    showDisabled = 0;
                    exceptions[] = {"isNotInside", "isNotSitting"};
                    icon = "";
                };
                class addSound {
                    displayName = CSTRING(X_Action_addSound);
                    condition = QUOTE('kat_X_AED' in (items _player) && ((_player getVariable QQGVAR(X_sound1)) isEqualTo ''));
                    statement = QUOTE(_player setVariable [ARR_3(QQGVAR(X_sound1), QQPATHTOF_SOUND(sounds\noheartrate.wav), true)]; _player setVariable [ARR_3(QQGVAR(X_sound2), QQPATHTOF_SOUND(sounds\heartrate.wav), true)];);
                    showDisabled = 0;
                    exceptions[] = {"isNotInside", "isNotSitting"};
                    icon = "";
                };
                */
                class openCrossPanel {
                    displayName = CSTRING(open_crosspanel);
                    condition = "('kat_crossPanel' in (uniformItems _player)) || ('kat_crossPanel' in (vestItems _player))";
                    statement = QUOTE(createDialog QQGVAR(CrossPanel_Dialog));
                    showDisabled = 0;
                    exceptions[] = {"isNotInside", "isNotSitting"};
                    icon = "";
                };
            };
        };
    };
};