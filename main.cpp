#include <mod/amlmod.h>
#include <mod/config.h>
#include <mod/logger.h>
#define CCamera_VerticalAngle TheCamera->Cams[TheCamera->ActiveCam].m_fVerticalAngle
#define CCamera_HorizontalAngle TheCamera->Cams[TheCamera->ActiveCam].m_fHorizontalAngle

MYMODCFG(net.KillerSA.AimForTheCamera, AimForTheCamera, 2.1, KillerSA)
uintptr_t pGTASA = aml->GetLib("libGTASA.so");

// ------------- //

#ifdef AML32
    #include <SA_200.h>
#else 
    #include <SA_210.h>
#endif 

uintptr_t pTheCamera = (uintptr_t)BYBIT(0x951FA8, 0xBBA8D0);
CCamera* TheCamera = (CCamera*)(pTheCamera + pGTASA);

bool bVertAngleOnOW = true, bVertAngleInSniper = true;

bool bAimed = false;
float fVerticalAngle, fHorizontalAngle;

void SetAngles(float verticalAngle, float horizontalAngle) {
    if(TheCamera->Cams[TheCamera->ActiveCam].Mode == MODE_SNIPER) {
        if(bVertAngleInSniper) {
            CCamera_VerticalAngle = verticalAngle;
        }
    } else { 
        if(bVertAngleOnOW) {
            CCamera_VerticalAngle = verticalAngle;
        }
    }
    
    CCamera_HorizontalAngle = horizontalAngle;
}

DECL_HOOKv(ProcessScriptsHook)  {
    ProcessScriptsHook();

    switch(TheCamera->Cams[TheCamera->ActiveCam].Mode) {
        case MODE_SNIPER:
        case MODE_ROCKETLAUNCHER:
        case MODE_CAMERA:
        case MODE_ROCKETLAUNCHER_HS:
        case MODE_AIMWEAPON:
            if(!bAimed) {
                SetAngles(fVerticalAngle, fHorizontalAngle);
                bAimed = true;
            } else {
                fVerticalAngle = CCamera_VerticalAngle;
                fHorizontalAngle = CCamera_HorizontalAngle;
            }
            break;
        default: 
            if(bAimed) {
                SetAngles(fVerticalAngle, fHorizontalAngle);
                bAimed = false;
            } else {
                fVerticalAngle = CCamera_VerticalAngle;
                fHorizontalAngle = CCamera_HorizontalAngle;
            }
            break;
    }
}

extern "C" void OnModLoad() {
    logger->SetTag("AimForTheCamera");
    cfg->Bind("Author", "", "About")->SetString("KillerSA and Yuna"); cfg->ClearLast();
    cfg->Bind("GitHub", "", "About")->SetString("https://github.com/KillerSAA/AimForTheCamera"); cfg->ClearLast();
    bVertAngleOnOW = cfg->GetBool("VerticalAngleOnOW", true, "configs");
    bVertAngleInSniper = cfg->GetBool("VertAngleInSniper", true, "configs");

    if(pGTASA) {
        HOOKPLT(ProcessScriptsHook, pGTASA + BYBIT(0x672AAC, 0x844948));
    }
    else {
        logger->Error("This game is unsupported");
        return;
    }
    cfg->Save();
}
