:IsAiming
    // weapon modes
    const AIMING_STATE = 53, SNIPER_MODE = 7, RPG_MODE = 8, ROCKET_MODE = 51, CAMERA_MODE = 46

    int pPlayerWeaponMode = 0x951FA8, iPlayerWea, iIb

    pPlayerWeaponMode += 0x7B4
    get_image_base iIb
    pPlayerWeaponMode += iIb

    int pAiming = False

    Memory.Read(iPlayerWea, pPlayerWeaponMode, 4, false)

    if or
        iPlayerWea == SNIPER_MODE {Sniper}
        iPlayerWea == RPG_MODE {RPG}
        iPlayerWea == ROCKET_MODE {Heat Seeking Rocket}
        iPlayerWea == CAMERA_MODE {Camera}
    then
        pAiming = True
    end

    if iPlayerWea == AIMING_STATE
    then
        pAiming = True
        Memory.Write(pPlayerWeaponMode, 0, 4, false, false)
    end

if pAiming == True
return