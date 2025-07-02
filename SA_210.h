#pragma once 

#pragma once 
// declaration of some classes

class CVector {
public:
    float x, y, z;
};

class CVector2D {
public:
    float x, y;
};

class CMatrix // sizeof=0x48
{       
public:                              
    float xx;
    float yx;
    float zx;
    float pad1;
    float xy;
    float yy;
    float zy;
    float pad2;
    float xz;
    float yz;
    float zz;
    float pad3;
    float tx;
    float ty;
    float tz;
    float pad4;
    void *m_pRwMat; // RwMatrix
    unsigned int m_owner;
};

class CSimpleTransform // sizeof=0x10
{          
public:                            
    CVector m_translate;
    float m_heading;
};

class CPlaceable {        
public:                             
    int (**_vptr$CPlaceable)(void);
    CSimpleTransform m_transform;
    CMatrix *m_pMat;
};

class CEntity : public CPlaceable {     
public:                                  
    void *m_pRwObject; // RwObject
    //CFlags m_nFlags;
    class CFlags
    {                                      
        unsigned int bUsesCollision : 1;
        unsigned int bCollisionProcessed : 1;
        unsigned int bIsStatic : 1;
        unsigned int bHasContacted : 1;
        unsigned int bIsStuck : 1;
        unsigned int bIsInSafePosition : 1;
        unsigned int bWasPostponed : 1;
        unsigned int bIsVisible : 1;
        unsigned int bIsBIGBuilding : 1;
        unsigned int bRenderDamaged : 1;
        unsigned int bStreamingDontDelete : 1;
        unsigned int bRemoveFromWorld : 1;
        unsigned int bHasHitWall : 1;
        unsigned int bImBeingRendered : 1;
        unsigned int bDrawLast : 1;
        unsigned int bDistanceFade : 1;
        unsigned int bDontCastShadowsOn : 1;
        unsigned int bOffscreen : 1;
        unsigned int bIsStaticWaitingForCollision : 1;
        unsigned int bDontStream : 1;
        unsigned int bUnderwater : 1;
        unsigned int bHasPreRenderEffects : 1;
        unsigned int bIsTempBuilding : 1;
        unsigned int bDontUpdateHierarchy : 1;
        unsigned int bHasRoadsignText : 1;
        unsigned int bDisplayedSuperLowLOD : 1;
        unsigned int bIsProcObject : 1;
        unsigned int bBackfaceCulled : 1;
        unsigned int bLightObject : 1;
        unsigned int bUnimportantStream : 1;
        unsigned int bTunnel : 1;
        unsigned int bTunnelTransition : 1;
        unsigned int bdummy;
    } m_nFlags;
    unsigned short RandomSeed;
    short m_nModelIndex;
    char pad[4];
    void *pReferences; // CReference
    void *m_pLastRenderedLink; // CLink_CEntity
    unsigned short m_nScanCode;
    unsigned char m_iplIndex;
    unsigned char m_areaCode;
    char pad1[4];
    CEntity *m_pLod;
    unsigned char numLodChildren;
    char numLodChildrenRendered;
    class CEntityInfo 
    {                                      
        unsigned char nType : 3;
        unsigned char nStatus : 5;
    } m_info;
    char pad2[5];
};

enum eCamMode : short {
	MODE_NONE = 0x0,
	MODE_TOPDOWN = 0x1,
	MODE_GTACLASSIC = 0x2,
	MODE_BEHINDCAR = 0x3,
	MODE_FOLLOWPED = 0x4,
	MODE_AIMING = 0x5,
	MODE_DEBUG = 0x6,
	MODE_SNIPER = 0x7,
	MODE_ROCKETLAUNCHER = 0x8,
	MODE_MODELVIEW = 0x9,
	MODE_BILL = 0xA,
	MODE_SYPHON = 0xB,
	MODE_CIRCLE = 0xC,
	MODE_CHEESYZOOM = 0xD,
	MODE_WHEELCAM = 0xE,
	MODE_FIXED = 0xF,
	MODE_1STPERSON = 0x10,
	MODE_FLYBY = 0x11,
	MODE_CAM_ON_A_STRING = 0x12,
	MODE_REACTION = 0x13,
	MODE_FOLLOW_PED_WITH_BIND = 0x14,
	MODE_CHRIS = 0x15,
	MODE_BEHINDBOAT = 0x16,
	MODE_PLAYER_FALLEN_WATER = 0x17,
	MODE_CAM_ON_TRAIN_ROOF = 0x18,
	MODE_CAM_RUNNING_SIDE_TRAIN = 0x19,
	MODE_BLOOD_ON_THE_TRACKS = 0x1A,
	MODE_IM_THE_PASSENGER_WOOWOO = 0x1B,
	MODE_SYPHON_CRIM_IN_FRONT = 0x1C,
	MODE_PED_DEAD_BABY = 0x1D,
	MODE_PILLOWS_PAPS = 0x1E,
	MODE_LOOK_AT_CARS = 0x1F,
	MODE_ARRESTCAM_ONE = 0x20,
	MODE_ARRESTCAM_TWO = 0x21,
	MODE_M16_1STPERSON = 0x22,
	MODE_SPECIAL_FIXED_FOR_SYPHON = 0x23,
	MODE_FIGHT_CAM = 0x24,
	MODE_TOP_DOWN_PED = 0x25,
	MODE_LIGHTHOUSE = 0x26,
	MODE_SNIPER_RUNABOUT = 0x27,
	MODE_ROCKETLAUNCHER_RUNABOUT = 0x28,
	MODE_1STPERSON_RUNABOUT = 0x29,
	MODE_M16_1STPERSON_RUNABOUT = 0x2A,
	MODE_FIGHT_CAM_RUNABOUT = 0x2B,
	MODE_EDITOR = 0x2C,
	MODE_HELICANNON_1STPERSON = 0x2D,
	MODE_CAMERA = 0x2E,
	MODE_ATTACHCAM = 0x2F,
	MODE_TWOPLAYER = 0x30,
	MODE_TWOPLAYER_IN_CAR_AND_SHOOTING = 0x31,
	MODE_TWOPLAYER_SEPARATE_CARS = 0x32,
	MODE_ROCKETLAUNCHER_HS = 0x33,
	MODE_ROCKETLAUNCHER_RUNABOUT_HS = 0x34,
	MODE_AIMWEAPON = 0x35,
	MODE_TWOPLAYER_SEPARATE_CARS_TOPDOWN = 0x36,
	MODE_AIMWEAPON_FROMCAR = 0x37,
	MODE_DW_HELI_CHASE = 0x38,
	MODE_DW_CAM_MAN = 0x39,
	MODE_DW_BIRDY = 0x3A,
	MODE_DW_PLANE_SPOTTER = 0x3B,
	MODE_DW_DOG_FIGHT = 0x3C,
	MODE_DW_FISH = 0x3D,
	MODE_DW_PLANECAM1 = 0x3E,
	MODE_DW_PLANECAM2 = 0x3F,
	MODE_DW_PLANECAM3 = 0x40,
	MODE_AIMWEAPON_ATTACHED = 0x41
};

class CCam {       
public:                             
    bool bBelowMinDist;
    bool bBehindPlayerDesired;
    bool m_bCamLookingAtVector;
    bool m_bCollisionChecksOn;
    bool m_bFixingBeta;
    bool m_bTheHeightFixerVehicleIsATrain;
    bool LookBehindCamWasInFront;
    bool LookingBehind;
    bool LookingLeft;
    bool LookingRight;
    bool ResetStatics;
    bool ResetKeyboardStatics;
    bool Rotating;

    char pad; 

    eCamMode Mode;
    unsigned int m_uiFinishTime;
    int m_iDoCollisionChecksOnFrameNum;
    int m_iDoCollisionCheckEveryNumOfFrames;
    int m_iFrameNumWereAt;
    int DirectionWasLooking;
    float m_fSyphonModeTargetZOffSet;
    float m_fAlphaSpeedOverOneFrame;
    float m_fBetaSpeedOverOneFrame;
    float m_fCamBufferedHeight;
    float m_fCamBufferedHeightSpeed;
    float m_fCloseInPedHeightOffset;
    float m_fCloseInPedHeightOffsetSpeed;
    float m_fCloseInCarHeightOffset;
    float m_fCloseInCarHeightOffsetSpeed;
    float m_fDimensionOfHighestNearCar;
    float m_fDistanceBeforeChanges;
    float m_fFovSpeedOverOneFrame;
    float m_fMinDistAwayFromCamWhenInterPolating;
    float m_fPedBetweenCameraHeightOffset;
    float m_fPlayerInFrontSyphonAngleOffSet;
    float m_fRadiusForDead;
    float m_fRealGroundDist;
    float m_fTimeElapsedFloat;
    float m_fTilt;
    float m_fTiltSpeed;
    float m_fTransitionBeta;
    float m_fTrueBeta;
    float m_fTrueAlpha;
    float m_fInitialPlayerOrientation;
    float m_fVerticalAngle;
    float AlphaSpeed;
    float FOV;
    float FOVSpeed;
    float m_fHorizontalAngle;
    float BetaSpeed;
    float Distance;
    float DistanceSpeed;
    float CA_MIN_DISTANCE;
    float CA_MAX_DISTANCE;
    float SpeedVar;
    float m_fCameraHeightMultiplier;
    float m_fTargetZoomGroundOne;
    float m_fTargetZoomGroundTwo;
    float m_fTargetZoomGroundThree;
    float m_fTargetZoomOneZExtra;
    float m_fTargetZoomTwoZExtra;
    float m_fTargetZoomTwoInteriorZExtra;
    float m_fTargetZoomThreeZExtra;
    float m_fTargetZoomZCloseIn;
    float m_fMinRealGroundDist;
    float m_fTargetCloseInDist;
    float Beta_Targeting;
    float X_Targetting;
    float Y_Targetting;
    int CarWeAreFocussingOn;
    float CarWeAreFocussingOnI;
    float m_fCamBumpedHorz;
    float m_fCamBumpedVert;
    int m_nCamBumpedTime;
    CVector m_cvecSourceSpeedOverOneFrame;
    CVector m_cvecTargetSpeedOverOneFrame;
    CVector m_cvecUpOverOneFrame;
    CVector m_cvecTargetCoorsForFudgeInter;
    CVector m_cvecCamFixedModeVector;
    CVector m_cvecCamFixedModeSource;
    CVector m_cvecCamFixedModeUpOffSet;
    CVector m_vecLastAboveWaterCamPosition;
    CVector m_vecBufferedPlayerBodyOffset;
    CVector Front;
    CVector Source;
    CVector SourceBeforeLookBehind;
    CVector Up;
    CVector m_arrPreviousVectors[2];
    CVector m_aTargetHistoryPos[4];
    unsigned int m_nTargetHistoryTime[4];
    int m_nCurrentHistoryPoints;
    char pad1[4];
    CEntity *CamTargetEntity;
    float m_fCameraDistance;
    float m_fIdealAlpha;
    float m_fPlayerVelocity;
    char pad2[4];
    void *m_pLastCarEntered; // CAutomobile
    void *m_pLastPedLookedAt; // CPed
    bool m_bFirstPersonRunAboutActive;
    char pad3[7];
};

class CEntryInfoNode;
class CPtrNodeDoubleLink;
class CRealTimeShadow;

class CEntryInfoList {
public:
    CEntryInfoNode *m_pHead;
};


class RtQuat 
{                    
public:                 
    CVector imag;
    float real;
};

class CPhysical : public CEntity {      
public:                               
    float m_fPrevDistFromCam;
    unsigned int m_LastCollisionTime;
    //CPhysical::CPhysicalFlags m_nPhysicalFlags;
    class CPhysicalFlags {
    public:
        unsigned int bExtraHeavy : 1;
        unsigned int bDoGravity : 1;
        unsigned int bInfiniteMass : 1;
        unsigned int bInfiniteMassFixed : 1;
        unsigned int bPedPhysics : 1;
        unsigned int bDoorPhysics : 1;
        unsigned int bHangingPhysics : 1;
        unsigned int bPoolBallPhysics : 1;
        unsigned int bIsInWater : 1;
        unsigned int bCollidedThisFrame : 1;
        unsigned int bUnFreezable : 1;
        unsigned int bTrainForceCol : 1;
        unsigned int bSkipLineCol : 1;
        unsigned int bCoorsFrozenByScript : 1;
        unsigned int bDontLoadCollision : 1;
        unsigned int bHalfSpeedCollision : 1;
        unsigned int bForceHitReturnFalse : 1;
        unsigned int bDontProcessCollisionOurSelves : 1;
        unsigned int bNotDamagedByBullets : 1;
        unsigned int bNotDamagedByFlames : 1;
        unsigned int bNotDamagedByCollisions : 1;
        unsigned int bNotDamagedByMelee : 1;
        unsigned int bOnlyDamagedByPlayer : 1;
        unsigned int bIgnoresExplosions : 1;
        unsigned int bFlyer : 1;
        unsigned int bNeverGoStatic : 1;
        unsigned int bUsingSpecialColModel : 1;
        unsigned int bForceFullWaterCheck : 1;
        unsigned int bUsesCollisionRecords : 1;
        unsigned int bRenderScorched : 1;
        unsigned int bDoorHitEndStop : 1;
        unsigned int bCarriedByRope : 1;
    } m_nPhysicalFlags;
    CVector m_vecMoveSpeed;
    CVector m_vecTurnSpeed;
    CVector m_vecMoveFriction;
    CVector m_vecTurnFriction;
    CVector m_vecAverageMoveSpeed;
    CVector m_vecAverageTurnSpeed;
    float m_fMass;
    float m_fTurnMass;
    float m_fMassMultiplier;
    float m_fAirResistance;
    float m_fElasticity;
    float m_fBuoyancyConstant;
    CVector m_vecCOM;
    char pad[4];
    CEntryInfoList m_listEntryInfo;
    CPtrNodeDoubleLink *m_pMovingListNode;
    unsigned char m_nNoOfStaticFrames;
    unsigned char m_nNoOfCollisionRecords;
    unsigned char m_LastMaterialToHaveBeenStandingOn;
    char pad1[5];
    CEntity *m_aCollisionRecordPtrs[6];
    float m_fTrueDistanceTravelled;
    float m_fDamageImpulseMagnitude;
    CEntity *m_pDamageEntity;
    CVector m_vecDamageNormal;
    CVector m_vecDamagePos;
    unsigned short m_nDamagedPieceType;
    char pad2[6];
    CEntity *m_pAttachToEntity;
    CVector m_vecAttachPosnOffset;
    CVector m_vecAttachTiltOffset;
    RtQuat m_AttachQuat;
    CEntity *m_pNOCollisionVehicle;
    float m_lightingFromCollision;
    float m_lightingFromPointLights;
    CRealTimeShadow *m_pRealTimeShadow;
};

typedef unsigned short Bool16;
typedef int tAudioEvent;

class CAESound 
{                 
public:   
    short m_BankSlotID;
    short m_SoundID;
    char pad[4];
    void *m_pAudioEntity; // CAEAudioEntity
    CEntity *m_pPhysicalEntity;
    tAudioEvent m_AudioEvent;
    float m_ClientVariable;
    float m_EmittedVolume;
    float m_RollOffFactor;
    float m_RelativeFrequency;
    float m_FrequencyVariance;
    CVector m_Position;
    CVector m_PositionLastFrame;
    unsigned int m_FramePositionLastUpdated;
    unsigned int m_TimePositionUpdated;
    unsigned int m_TimeLastPositionUpdated;
    float m_fDistanceFromCamera;
    float m_fDistanceFromCameraLastFrame;
    float m_Doppler;
    unsigned char m_FrameDelay;
    char pad1;
    unsigned short m_Environment;
    Bool16 m_bCurrentlyInUse;
    Bool16 m_bAudioHardwareAware;
    short m_nPlayTime;
    Bool16 m_bPhysicallyPlaying;
    float m_ListenerVolume;
    float m_RelativePlaybackFrequency;
    Bool16 m_bRequestedStopped;
    short pad2;
    float m_fHeadroom;
    short m_nLength;
    short pad3;
};

class CAEAudioEntity // sizeof=0x7C
{  
public:
    int (**_vptr$CAEAudioEntity)(void);
    CEntity *m_pGameEntity;
    CAESound ScratchSound;
};

class CAETwinLoopSoundEntity : public CAEAudioEntity 
{           
public:                          
    short m_BankSlotID;
    short m_FirstSoundID;
    short m_SecondSoundID;
    short pad;
    CAEAudioEntity *m_pAudioEntity;
    Bool16 m_bCurrentlyInUse;
    short m_nFirstLength;
    short m_nSecondLength;
    unsigned short m_MinSwapTime;
    unsigned short m_MaxSwapTime;
    short pad2;
    unsigned int m_SwapTime;
    bool m_bPlayingFirst;
    char pad3;
    short m_StartPercentFirst;
    short m_StartPercentSecond;
    short pad4;
    CAESound *m_pFirstSoundPtr;
    CAESound *m_pSecondSoundPtr;
};

class CAEPedAudioEntity : public CAEAudioEntity // sizeof=0x15C
{                                     
public:
    bool m_bInitialised;
    char pad098;
    short m_nLastSwimSplashSoundID;
    unsigned int m_nLastSwimWakeTriggerTimeMs;
    float m_fCurrentJetPackThrustVolume;
    float m_fCurrentJetPackGasVolume;
    float m_fCurrentJetPackRoarVolume;
    float m_fCurrentJetPackRoarFrequency;
    void *m_pParentPed; // CPed
    bool m_bJetPackOn;
    char pad98[7];
    CAESound *m_pJetPackThrustSound;
    CAESound *m_pJetPackGasSound;
    CAESound *m_pJetPackRoarSound;
    CAETwinLoopSoundEntity m_ShirtFlapTwinLoopSound;
    CAESound *m_pWindRushSound;
    float m_fCurrentWindRushVolume;
    float m_fCurrentShirtFlapVolume;
};

class CAEPedSpeechAudioEntity : public CAEAudioEntity
{                                       
public:
    CAESound *SoundPtrs[5];
    bool b_Initialised;

    char pad;

    short m_PedType;
    short m_VoiceID;
    short m_bFemale;
    bool m_bPlayingSpeech;
    bool m_bSpeechDisabled;
    bool m_bSpeechDisabledForScriptSpeech;
    bool m_bFrontEnd;
    bool m_bForceAudible;
    char pad1[3];
    CAESound *m_pSound;
    short m_SoundID;
    short m_BankID;
    short m_PedSpeechSlotID;

    short pad2;

    float m_fEventVolume;
    short m_LastUsedGlobalSpeechContext;

    short pad3;

    unsigned int m_NextTimeCanSayPain[19];

    char pad4[4];
};

class CAEWeaponAudioEntity : public CAEAudioEntity 
{                          
public:             
    bool m_bMiniGunSpinActive;
    bool m_bMiniGunFireActive;
    char m_nLastWeaponPlaneFrequencyIndex;
    char m_nMiniGunState;
    char m_nChainsawState;
    char pad[3];
    unsigned int m_nLastFlameThrowerFireTimeMs;
    unsigned int m_nLastSprayCanFireTimeMs;
    unsigned int m_nLastFireExtFireTimeMs;
    unsigned int m_nLastMiniGunFireTimeMs;
    unsigned int m_nLastChainsawEventTimeMs;
    unsigned int m_nLastGunFireTimeMs;
    CAESound *m_pFlameThrowerIdleGasLoopSound;
};

class CAEPedWeaponAudioEntity : public CAEWeaponAudioEntity
{                       
public:              
    bool m_bInitialised;
    char pad[7];
    void *m_pParentPed; // CPed*
};

enum ePedState : int
{                                       
    PED_NONE                = 0x0,
    PED_IDLE                = 0x1,
    PED_LOOK_ENTITY         = 0x2,
    PED_LOOK_HEADING        = 0x3,
    PED_WANDER_RANGE        = 0x4,
    PED_WANDER_PATH         = 0x5,
    PED_SEEK_POSITION       = 0x6,
    PED_SEEK_ENTITY         = 0x7,
    PED_FLEE_POSITION       = 0x8,
    PED_FLEE_ENTITY         = 0x9,
    PED_PURSUE              = 0xA,
    PED_FOLLOW_PATH         = 0xB,
    PED_SNIPER_MODE         = 0xC,
    PED_ROCKETLAUNCHER_MODE = 0xD,
    PED_DUMMY               = 0xE,
    PED_PAUSE               = 0xF,
    PED_ATTACK              = 0x10,
    PED_FIGHT               = 0x11,
    PED_FACE_PHONE          = 0x12,
    PED_MAKE_PHONECALL      = 0x13,
    PED_CHAT                = 0x14,
    PED_MUG                 = 0x15,
    PED_AIMGUN              = 0x16,
    PED_AI_CONTROL          = 0x17,
    PED_SEEK_CAR            = 0x18,
    PED_SEEK_BOAT_POSITION  = 0x19,
    PED_FOLLOW_ROUTE        = 0x1A,
    PED_CPR                 = 0x1B,
    PED_SOLICIT             = 0x1C,
    PED_BUY_ICE_CREAM       = 0x1D,
    PED_INVESTIGATE_EVENT   = 0x1E,
    PED_EVADE_STEP          = 0x1F,
    PED_ON_FIRE             = 0x20,
    PED_SUNBATHE            = 0x21,
    PED_FLASH               = 0x22,
    PED_JOG                 = 0x23,
    PED_ANSWER_MOBILE       = 0x24,
    PED_HANG_OUT            = 0x25,
    PED_STATES_NO_AI        = 0x26,
    PED_ABSEIL_FROM_HELI    = 0x27,
    PED_SIT                 = 0x28,
    PED_JUMP                = 0x29,
    PED_FALL                = 0x2A,
    PED_GETUP               = 0x2B,
    PED_STAGGER             = 0x2C,
    PED_EVADE_DIVE          = 0x2D,
    PED_STATES_CAN_SHOOT    = 0x2E,
    PED_ENTER_TRAIN         = 0x2F,
    PED_EXIT_TRAIN          = 0x30,
    PED_ARREST_PLAYER       = 0x31,
    PED_DRIVING             = 0x32,
    PED_PASSENGER           = 0x33,
    PED_TAXI_PASSENGER      = 0x34,
    PED_OPEN_DOOR           = 0x35,
    PED_DIE                 = 0x36,
    PED_DEAD                = 0x37,
    PED_DIE_BY_STEALTH      = 0x38,
    PED_CARJACK             = 0x39,
    PED_DRAGGED_FROM_CAR    = 0x3A,
    PED_ENTER_CAR           = 0x3B,
    PED_STEAL_CAR           = 0x3C,
    PED_EXIT_CAR            = 0x3D,
    PED_HANDS_UP            = 0x3E,
    PED_ARRESTED            = 0x3F,
    PED_DEPLOY_STINGER      = 0x40,
    PED_NUM_STATES          = 0x41,
};
enum eMoveState : int
{                                       
    PEDMOVE_NONE   = 0x0,
    PEDMOVE_STILL  = 0x1,
    PEDMOVE_TURN_L = 0x2,
    PEDMOVE_TURN_R = 0x3,
    PEDMOVE_WALK   = 0x4,
    PEDMOVE_JOG    = 0x5,
    PEDMOVE_RUN    = 0x6,
    PEDMOVE_SPRINT = 0x7,
};

class CStoredCollPoly
{                     
public:                  
    CVector V1;
    CVector V2;
    CVector V3;
    bool bValidPolyStored;
    char pad[3];
    unsigned int lighting;
};

enum AssocGroupId : int
{                                     
    ANIM_STD_PED                    = 0x0,
    ANIM_STD_DOOR                   = 0x1,
    ANIM_BIKE_PED                   = 0x2,
    ANIM_BIKEV_PED                  = 0x3,
    ANIM_BIKEH_PED                  = 0x4,
    ANIM_BIKED_PED                  = 0x5,
    ANIM_BIKEW_PED                  = 0x6,
    ANIM_BMX_PED                    = 0x7,
    ANIM_MTB_PED                    = 0x8,
    ANIM_CHOPPA_PED                 = 0x9,
    ANIM_QUAD_PED                   = 0xA,
    ANIM_ATTACK_PYTHON              = 0xB,
    ANIM_ATTACK_PYTHON_POOR         = 0xC,
    ANIM_ATTACK_COLT45              = 0xD,
    ANIM_ATTACK_COLT45_COP          = 0xE,
    ANIM_ATTACK_COLT45_PRO          = 0xF,
    ANIM_ATTACK_SAWNOFF             = 0x10,
    ANIM_ATTACK_SAWNOFF_PRO         = 0x11,
    ANIM_ATTACK_SILENCED            = 0x12,
    ANIM_ATTACK_SHOTGUN             = 0x13,
    ANIM_ATTACK_SHOTGUN_POOR        = 0x14,
    ANIM_ATTACK_BUDDYSGUN           = 0x15,
    ANIM_ATTACK_BUDDY_POOR          = 0x16,
    ANIM_ATTACK_UZI                 = 0x17,
    ANIM_ATTACK_UZI_POOR            = 0x18,
    ANIM_ATTACK_RIFLE               = 0x19,
    ANIM_ATTACK_RIFLE_POOR          = 0x1A,
    ANIM_ATTACK_SNIPER              = 0x1B,
    ANIM_ATTACK_GRENADE             = 0x1C,
    ANIM_ATTACK_FLAME               = 0x1D,
    ANIM_ATTACK_ROCKET              = 0x1E,
    ANIM_ATTACK_SPRAYCAN            = 0x1F,
    ANIM_ATTACK_GOGGLES             = 0x20,
    ANIM_MELEE_UNARMED_1            = 0x21,
    ANIM_MELEE_UNARMED_2            = 0x22,
    ANIM_MELEE_UNARMED_3            = 0x23,
    ANIM_MELEE_UNARMED_4            = 0x24,
    ANIM_MELEE_BBBAT_1              = 0x25,
    ANIM_MELEE_GOLFCLUB_1           = 0x26,
    ANIM_MELEE_KNIFE_1              = 0x27,
    ANIM_MELEE_SWORD_1              = 0x28,
    ANIM_MELEE_DILDO                = 0x29,
    ANIM_MELEE_FLOWERS              = 0x2A,
    ANIM_MELEE_CHAINSAW             = 0x2B,
    ANIM_MELEE_KICK_STD             = 0x2C,
    ANIM_MELEE_PISTOLWHIP           = 0x2D,
    ANIM_MEDIC_PED                  = 0x2E,
    ANIM_BEACH_PED                  = 0x2F,
    ANIM_SUNBATHE_PED               = 0x30,
    ANIM_PLAYER_IDLES_PED           = 0x31,
    ANIM_RIOT_PED                   = 0x32,
    ANIM_STRIPPER_PED               = 0x33,
    ANIM_GANG_PED                   = 0x34,
    ANIM_ATTR_PED                   = 0x35,
    ANIM_PLAYER_PED                 = 0x36,
    ANIM_PLAYER_FAT_PED             = 0x37,
    ANIM_PLAYER_MUSCLE_PED          = 0x38,
    ANIM_PLAYER_ROCKET_PED          = 0x39,
    ANIM_PLAYER_FAT_ROCKET_PED      = 0x3A,
    ANIM_PLAYER_MUSCLE_ROCKET_PED   = 0x3B,
    ANIM_PLAYER_2ARMED_PED          = 0x3C,
    ANIM_PLAYER_FAT_2ARMED_PED      = 0x3D,
    ANIM_PLAYER_MUSCLE_2ARMED_PED   = 0x3E,
    ANIM_PLAYER_BBBAT_PED           = 0x3F,
    ANIM_PLAYER_FAT_BBBAT_PED       = 0x40,
    ANIM_PLAYER_MUSCLE_BBBAT_PED    = 0x41,
    ANIM_PLAYER_CHAINSAW_PED        = 0x42,
    ANIM_PLAYER_FAT_CHAINSAW_PED    = 0x43,
    ANIM_PLAYER_MUSCLE_CHAINSAW_PED = 0x44,
    ANIM_PLAYER_SNEAK_PED           = 0x45,
    ANIM_PLAYER_JETPACK_PED         = 0x46,
    ANIM_SWIM_PED                   = 0x47,
    ANIM_GANG_DRIVEBY               = 0x48,
    ANIM_BIKE_DRIVEBY               = 0x49,
    ANIM_COP_DRIVEBY                = 0x4A,
    ANIM_QUAD_DRIVEBY               = 0x4B,
    ANIM_PLAYER_FAT_TIRED_PED       = 0x4C,
    ANIM_HANDSIGNAL_PED             = 0x4D,
    ANIM_HANDSIGNAL_PEDL            = 0x4E,
    ANIM_HANDSIGNAL_LHAND           = 0x4F,
    ANIM_HANDSIGNAL_RHAND           = 0x50,
    ANIM_CARRY_BOX                  = 0x51,
    ANIM_CARRY_BOX_05               = 0x52,
    ANIM_CARRY_BOX_105              = 0x53,
    ANIM_INT_HOUSE_PED              = 0x54,
    ANIM_INT_OFFICE_PED             = 0x55,
    ANIM_INT_SHOP_PED               = 0x56,
    ANIM_STEALTH_KNIFE              = 0x57,
    ANIM_VEH_STD                    = 0x58,
    ANIM_VEH_LOW                    = 0x59,
    ANIM_VEH_TRK                    = 0x5A,
    ANIM_VEH_BIKESTD                = 0x5B,
    ANIM_VEH_BIKESPORT              = 0x5C,
    ANIM_VEH_BIKEVESPA              = 0x5D,
    ANIM_VEH_BIKEHARLEY             = 0x5E,
    ANIM_VEH_BIKEDIRT               = 0x5F,
    ANIM_VEH_BIKEWAYF               = 0x60,
    ANIM_VEH_BIKEBMX                = 0x61,
    ANIM_VEH_BIKEMTB                = 0x62,
    ANIM_VEH_BIKECHOPPA             = 0x63,
    ANIM_VEH_BIKEQUAD               = 0x64,
    ANIM_VEH_VAN                    = 0x65,
    ANIM_VEH_RUSTLER                = 0x66,
    ANIM_VEH_COACH                  = 0x67,
    ANIM_VEH_BUS                    = 0x68,
    ANIM_VEH_DOZER                  = 0x69,
    ANIM_VEH_KART                   = 0x6A,
    ANIM_VEH_CONVERTIBLE            = 0x6B,
    ANIM_VEH_MTRUCK                 = 0x6C,
    ANIM_VEH_TRAINCARRIAGE          = 0x6D,
    ANIM_VEH_STD_HIGH               = 0x6E,
    ANIM_VEH_STD_VORTEX             = 0x6F,
    ANIM_VEH_TANK                   = 0x70,
    ANIM_VEH_BFINJ                  = 0x71,
    ANIM_VEH_LEAR                   = 0x72,
    ANIM_VEH_HARRIER                = 0x73,
    ANIM_VEH_STD_UPRIGHT            = 0x74,
    ANIM_VEH_NEVADA                 = 0x75,
    ANIM_NUM_ASSOCGROUPS            = 0x76,
};

class CAcquaintance 
{     
public:                              
    unsigned int m_nAcquaintances[5];
};

class LimbOrientation 
{             
public:                         
    float yaw;
    float pitch;
};

class CPedIK
{           
public:                            
    void *m_pPed; // CPed
    LimbOrientation m_torsoOrien;
    float m_fSlopePitch;
    float m_fSlopePitchLimitMult;
    float m_fSlopeRoll;
    float m_fBodyRoll;
    unsigned int m_flags;
    char pad[4];
};

enum eWeaponType : int
{                                       // XREF: public CWeapon/r CPed/r ...
    WEAPONTYPE_UNARMED               = 0x0,
    WEAPONTYPE_BRASSKNUCKLE          = 0x1,
    WEAPONTYPE_GOLFCLUB              = 0x2,
    WEAPONTYPE_NIGHTSTICK            = 0x3,
    WEAPONTYPE_KNIFE                 = 0x4,
    WEAPONTYPE_BASEBALLBAT           = 0x5,
    WEAPONTYPE_SHOVEL                = 0x6,
    WEAPONTYPE_POOL_CUE              = 0x7,
    WEAPONTYPE_KATANA                = 0x8,
    WEAPONTYPE_CHAINSAW              = 0x9,
    WEAPONTYPE_DILDO1                = 0xA,
    WEAPONTYPE_DILDO2                = 0xB,
    WEAPONTYPE_VIBE1                 = 0xC,
    WEAPONTYPE_VIBE2                 = 0xD,
    WEAPONTYPE_FLOWERS               = 0xE,
    WEAPONTYPE_CANE                  = 0xF,
    WEAPONTYPE_GRENADE               = 0x10,
    WEAPONTYPE_TEARGAS               = 0x11,
    WEAPONTYPE_MOLOTOV               = 0x12,
    WEAPONTYPE_ROCKET                = 0x13,
    WEAPONTYPE_ROCKET_HS             = 0x14,
    WEAPONTYPE_FREEFALL_BOMB         = 0x15,
    WEAPONTYPE_PISTOL                = 0x16,
    WEAPONTYPE_PISTOL_SILENCED       = 0x17,
    WEAPONTYPE_DESERT_EAGLE          = 0x18,
    WEAPONTYPE_SHOTGUN               = 0x19,
    WEAPONTYPE_SAWNOFF_SHOTGUN       = 0x1A,
    WEAPONTYPE_SPAS12_SHOTGUN        = 0x1B,
    WEAPONTYPE_MICRO_UZI             = 0x1C,
    WEAPONTYPE_MP5                   = 0x1D,
    WEAPONTYPE_AK47                  = 0x1E,
    WEAPONTYPE_M4                    = 0x1F,
    WEAPONTYPE_TEC9                  = 0x20,
    WEAPONTYPE_COUNTRYRIFLE          = 0x21,
    WEAPONTYPE_SNIPERRIFLE           = 0x22,
    WEAPONTYPE_ROCKETLAUNCHER        = 0x23,
    WEAPONTYPE_ROCKETLAUNCHER_HS     = 0x24,
    WEAPONTYPE_FLAMETHROWER          = 0x25,
    WEAPONTYPE_MINIGUN               = 0x26,
    WEAPONTYPE_REMOTE_SATCHEL_CHARGE = 0x27,
    WEAPONTYPE_DETONATOR             = 0x28,
    WEAPONTYPE_SPRAYCAN              = 0x29,
    WEAPONTYPE_EXTINGUISHER          = 0x2A,
    WEAPONTYPE_CAMERA                = 0x2B,
    WEAPONTYPE_NIGHTVISION           = 0x2C,
    WEAPONTYPE_INFRARED              = 0x2D,
    WEAPONTYPE_PARACHUTE             = 0x2E,
    WEAPONTYPE_LAST_WEAPONTYPE       = 0x2F,
    WEAPONTYPE_ARMOUR                = 0x30,
    WEAPONTYPE_RAMMEDBYCAR           = 0x31,
    WEAPONTYPE_RUNOVERBYCAR          = 0x32,
    WEAPONTYPE_EXPLOSION             = 0x33,
    WEAPONTYPE_UZI_DRIVEBY           = 0x34,
    WEAPONTYPE_DROWNING              = 0x35,
    WEAPONTYPE_FALL                  = 0x36,
    WEAPONTYPE_UNIDENTIFIED          = 0x37,
    WEAPONTYPE_ANYMELEE              = 0x38,
    WEAPONTYPE_ANYWEAPON             = 0x39,
    WEAPONTYPE_FLARE                 = 0x3A,
};
enum eWeaponState : int
{                                     
    WEAPONSTATE_READY             = 0x0,
    WEAPONSTATE_FIRING            = 0x1,
    WEAPONSTATE_RELOADING         = 0x2,
    WEAPONSTATE_OUT_OF_AMMO       = 0x3,
    WEAPONSTATE_MELEE_MADECONTACT = 0x4,
};

class CWeapon
{      
public:                                 
    eWeaponType m_eWeaponType;
    eWeaponState m_eState;
    int m_nAmmoInClip;
    int m_nAmmoTotal;
    unsigned int m_nTimer;
    bool m_bFirstPersonWeaponModeSelected;
    bool m_bDontPlaceInHand;
    short pad;
    void *m_pWeaponFxSys; // FxSystem_c
};

class CPed : public CPhysical {    
public:                   
    CAEPedAudioEntity m_PedAudioEntity;
    CAEPedSpeechAudioEntity m_PedSpeechAudioEntity;
    CAEPedWeaponAudioEntity m_PedWeaponAudioEntity;
    void *m_pPedIntelligence; // CPedIntelligence
    void *m_pPlayerData; // CPlayerPedData
    unsigned char CharCreatedBy;
    char pad[3];
    ePedState m_nPedState;
    eMoveState m_eMoveState;
    CStoredCollPoly m_storedCollPoly;
    float m_distTravelledSinceLastHeightCheck;
    //CPedFlags m_nPedFlags;
    class CPedFlags {  
    public:                                     
        unsigned int bIsStanding : 1;
        unsigned int bWasStanding : 1;
        unsigned int bIsLooking : 1;
        unsigned int bIsRestoringLook : 1;
        unsigned int bIsAimingGun : 1;
        unsigned int bIsRestoringGun : 1;
        unsigned int bCanPointGunAtTarget : 1;
        unsigned int bIsTalking : 1;
        unsigned int bInVehicle : 1;
        unsigned int bIsInTheAir : 1;
        unsigned int bIsLanding : 1;
        unsigned int bHitSomethingLastFrame : 1;
        unsigned int bIsNearCar : 1;
        unsigned int bRenderPedInCar : 1;
        unsigned int bUpdateAnimHeading : 1;
        unsigned int bRemoveHead : 1;
        unsigned int bFiringWeapon : 1;
        unsigned int bHasACamera : 1;
        unsigned int bPedIsBleeding : 1;
        unsigned int bStopAndShoot : 1;
        unsigned int bIsPedDieAnimPlaying : 1;
        unsigned int bStayInSamePlace : 1;
        unsigned int bKindaStayInSamePlace : 1;
        unsigned int bBeingChasedByPolice : 1;
        unsigned int bNotAllowedToDuck : 1;
        unsigned int bCrouchWhenShooting : 1;
        unsigned int bIsDucking : 1;
        unsigned int bGetUpAnimStarted : 1;
        unsigned int bDoBloodyFootprints : 1;
        unsigned int bDontDragMeOutCar : 1;
        unsigned int bStillOnValidPoly : 1;
        unsigned int bAllowMedicsToReviveMe : 1;
        unsigned int bResetWalkAnims : 1;
        unsigned int bOnBoat : 1;
        unsigned int bBusJacked : 1;
        unsigned int bFadeOut : 1;
        unsigned int bKnockedUpIntoAir : 1;
        unsigned int bHitSteepSlope : 1;
        unsigned int bCullExtraFarAway : 1;
        unsigned int bTryingToReachDryLand : 1;
        unsigned int bCollidedWithMyVehicle : 1;
        unsigned int bRichFromMugging : 1;
        unsigned int bChrisCriminal : 1;
        unsigned int bShakeFist : 1;
        unsigned int bNoCriticalHits : 1;
        unsigned int bHasAlreadyBeenRecorded : 1;
        unsigned int bUpdateMatricesRequired : 1;
        unsigned int bFleeWhenStanding : 1;
        unsigned int bMiamiViceCop : 1;
        unsigned int bMoneyHasBeenGivenByScript : 1;
        unsigned int bHasBeenPhotographed : 1;
        unsigned int bIsDrowning : 1;
        unsigned int bDrownsInWater : 1;
        unsigned int bHeadStuckInCollision : 1;
        unsigned int bDeadPedInFrontOfCar : 1;
        unsigned int bStayInCarOnJack : 1;
        unsigned int bDontFight : 1;
        unsigned int bDoomAim : 1;
        unsigned int bCanBeShotInVehicle : 1;
        unsigned int bPushedAlongByCar : 1;
        unsigned int bNeverEverTargetThisPed : 1;
        unsigned int bThisPedIsATargetPriority : 1;
        unsigned int bCrouchWhenScared : 1;
        unsigned int bKnockedOffBike : 1;
        unsigned int bDonePositionOutOfCollision : 1;
        unsigned int bDontRender : 1;
        unsigned int bHasBeenAddedToPopulation : 1;
        unsigned int bHasJustLeftCar : 1;
        unsigned int bIsInDisguise : 1;
        unsigned int bDoesntListenToPlayerGroupCommands : 1;
        unsigned int bIsBeingArrested : 1;
        unsigned int bHasJustSoughtCover : 1;
        unsigned int bKilledByStealth : 1;
        unsigned int bDoesntDropWeaponsWhenDead : 1;
        unsigned int bCalledPreRender : 1;
        unsigned int bBloodPuddleCreated : 1;
        unsigned int bPartOfAttackWave : 1;
        unsigned int bClearRadarBlipOnDeath : 1;
        unsigned int bNeverLeavesGroup : 1;
        unsigned int bTestForBlockedPositions : 1;
        unsigned int bRightArmBlocked : 1;
        unsigned int bLeftArmBlocked : 1;
        unsigned int bDuckRightArmBlocked : 1;
        unsigned int bMidriffBlockedForJump : 1;
        unsigned int bFallenDown : 1;
        unsigned int bUseAttractorInstantly : 1;
        unsigned int bDontAcceptIKLookAts : 1;
        unsigned int bHasAScriptBrain : 1;
        unsigned int bWaitingForScriptBrainToLoad : 1;
        unsigned int bHasGroupDriveTask : 1;
        unsigned int bCanExitCar : 1;
        unsigned int CantBeKnockedOffBike : 2;
        unsigned int bHasBeenRendered : 1;
        unsigned int bIsCached : 1;
        unsigned int bPushOtherPeds : 1;
        unsigned int bHasBulletProofVest : 1;
        unsigned int bUsingMobilePhone : 1;
        unsigned int bUpperBodyDamageAnimsOnly : 1;
        unsigned int bStuckUnderCar : 1;
        unsigned int bKeepTasksAfterCleanUp : 1;
        unsigned int bIsDyingStuck : 1;
        unsigned int bIgnoreHeightCheckOnGotoPointTask : 1;
        unsigned int bForceDieInCar : 1;
        unsigned int bCheckColAboveHead : 1;
        unsigned int bIgnoreWeaponRange : 1;
        unsigned int bDruggedUp : 1;
        unsigned int bWantedByPolice : 1;
        unsigned int bSignalAfterKill : 1;
        unsigned int bCanClimbOntoBoat : 1;
        unsigned int bPedHitWallLastFrame : 1;
        unsigned int bIgnoreHeightDifferenceFollowingNodes : 1;
        unsigned int bMoveAnimSpeedHasBeenSetByTask : 1;
        unsigned int bGetOutUpsideDownCar : 1;
        unsigned int bJustGotOffTrain : 1;
        unsigned int bDeathPickupsPersist : 1;
        unsigned int bTestForShotInVehicle : 1;
        unsigned int pad : 1;
        unsigned int pad1 : 1;
        unsigned int pad2 : 1;
        unsigned int pad3 : 1;
        unsigned int pad4 : 1;
        unsigned int pad5 : 1;
        unsigned int pad6 : 1;
        unsigned int pad7 : 1;
        unsigned int pad8 : 1;
        unsigned int pad9 : 1;
        unsigned int pad10 : 1;
    } m_nPedFlags;
    char pad1[4];
    void *m_aPedFrames[19]; // AnimBlendFrameData
    AssocGroupId m_motionAnimGroup;
    CVector2D m_extractedVelocity;
    CAcquaintance m_acquaintances;
    void *m_pWeaponClump; // RpClump_0
    void *m_pWeaponFlashFrame; // RwFrame_0
    void *m_pGogglesClump; // RpClump_0
    bool *m_pbGogglesEffect;
    short m_nGunFlashBlendAmount;
    short m_nGunFlashBlendOutRate;
    short m_nGunFlashBlendAmount2;
    short m_nGunFlashBlendOutRate2;
    CPedIK m_ik;
    unsigned int m_nAntiSpazTimer;
    eMoveState m_eMoveStateAnim;
    eMoveState m_eStoredMoveState;
    float m_nHealth;
    float m_nMaxHealth;
    float m_nArmour;
    unsigned int DontUseSmallerRemovalRange;
    CVector2D m_vecCurrentVelocity;
    float m_fCurrentHeading;
    float m_fDesiredHeading;
    float m_fHeadingChangeRate;
    float m_fHeadingChangeRateAccel;
    char pad2[4];
    CPhysical *m_pGroundPhysical;
    CVector m_vecGroundOffset;
    CVector m_vecGroundNormal;
    CEntity *m_pEntityStandingOn;
    float m_fHitHeadHeight;
    char pad3[4];
    void *m_pMyVehicle; // CVehicle
    void *m_pMyAccidentVehicle; // CVehicle
    void *m_pAccident; // CAccident
    int m_nPedType;
    char pad4[4];
    void *m_pPedStats; // CPedStats
    CWeapon m_WeaponSlots[13];
    eWeaponType m_eStoredWeapon;
    eWeaponType m_eDelayedWeapon;
    unsigned int m_delayedAmmo;
    char m_nCurrentWeapon;
    unsigned char m_nShootRate;
    unsigned char m_nShootingAccuracy;

    char pad5;

    CEntity *m_pEntLockOnTarget;
    CEntity *m_pEntMagnetizeTarget;
    CVector m_vecWeaponPrevPos;
    unsigned char m_nWeaponSkill;
    unsigned char m_nExtraMeleeCombo;
    unsigned char m_nExtraMeleeComboFlags;
    unsigned char BleedingFrames;
    void *m_pFire; // CFire
    float FireDamageMultiplier;
    char pad6[4];
    CEntity *m_pEntLookEntity;
    float m_fLookHeading;
    int WeaponModelInHand;
    unsigned int m_nUnconsciousTimer;
    unsigned int m_nLookTimer;
    unsigned int m_nAttackTimer;
    unsigned int m_nTimeOfDeath;
    char m_nLimbRemoveIndex;

    char pad7;

    unsigned short m_MoneyCarried;
    float m_wobble;
    float m_wobbleSpeed;
    char LastDamagedWeaponType;

    char pad8[3];

    CEntity *pLastDamageEntity;
    unsigned int LastDamagedTime;
    CVector m_vecAttachOffset;
    unsigned short m_nAttachLookDirn;

    short pad9;

    float m_fAttachHeadingLimit;
    float m_fAttachVerticalLimit;
    int m_nOriginalWeaponAmmo;
    void *m_pCoverPoint; // CCoverPoint
    void *m_pLastEntryExit;// CEntryExit
    float fRemoveRangeMultiplier;
    short StreamedScriptBrainToLoad;

    short pad10;

    unsigned int LastTalkSfx;
    char pad11[4];
};

class CQueuedMode
{                  
public:                    
    short Mode;
    short pad;
    float Duration;
    short MinZoom;
    short MaxZoom;
};

class CCamPathSplines 
{                 
public:                      
    float *m_arr_PathData;
};

class CCamera : public CPlaceable {
public:
    bool m_bAboveGroundTrainNodesLoaded;
    bool m_bBelowGroundTrainNodesLoaded;
    bool m_bCamDirectlyBehind;
    bool m_bCamDirectlyInFront;
    bool m_bCameraJustRestored;
    bool m_bcutsceneFinished;
    bool m_bCullZoneChecksOn;
    bool m_bIdleOn;
    bool m_bInATunnelAndABigVehicle;
    bool m_bInitialNodeFound;
    bool m_bInitialNoNodeStaticsSet;
    bool m_bIgnoreFadingStuffForMusic;
    bool m_bPlayerIsInGarage;
    bool m_bPlayerWasOnBike;
    bool m_bJustCameOutOfGarage;
    bool m_bJustInitalised;
    bool m_bJust_Switched;
    bool m_bLookingAtPlayer;
    bool m_bLookingAtVector;
    bool m_bMoveCamToAvoidGeom;
    bool m_bObbeCinematicPedCamOn;
    bool m_bObbeCinematicCarCamOn;
    bool m_bRestoreByJumpCut;
    bool m_bUseNearClipScript;
    bool m_bStartInterScript;
    bool m_bStartingSpline;
    bool m_bTargetJustBeenOnTrain;
    bool m_bTargetJustCameOffTrain;
    bool m_bUseSpecialFovTrain;
    bool m_bUseTransitionBeta;
    bool m_bUseScriptZoomValuePed;
    bool m_bUseScriptZoomValueCar;
    bool m_bWaitForInterpolToFinish;
    bool m_bItsOkToLookJustAtThePlayer;
    bool m_bWantsToSwitchWidescreenOff;
    bool m_WideScreenOn;
    bool m_1rstPersonRunCloseToAWall;
    bool m_bHeadBob;
    bool m_bVehicleSuspenHigh;
    bool m_bEnable1rstPersonCamCntrlsScript;
    bool m_bAllow1rstPersonWeaponsCamera;
    bool m_bCooperativeCamMode;
    bool m_bAllowShootingWith2PlayersInCar;
    bool m_bDisableFirstPersonInCar;
    short m_ModeForTwoPlayersSeparateCars;
    short m_ModeForTwoPlayersSameCarShootingAllowed;
    short m_ModeForTwoPlayersSameCarShootingNotAllowed;
    short m_ModeForTwoPlayersNotBothInCar;
    bool m_bGarageFixedCamPositionSet;
    bool m_vecDoingSpecialInterPolation;
    bool m_bScriptParametersSetForInterPol;
    bool m_bFading;
    bool m_bMusicFading;
    bool m_bMusicFadedOut;
    bool m_bFailedCullZoneTestPreviously;
    bool m_FadeTargetIsSplashScreen;
    bool WorldViewerBeingUsed;
    unsigned char m_uiTransitionJUSTStarted;
    unsigned char m_uiTransitionState;
    unsigned char ActiveCam;
    unsigned int m_uiCamShakeStart;
    unsigned int m_uiFirstPersonCamLastInputTime;
    unsigned int m_uiLongestTimeInMill;
    unsigned int m_uiNumberOfTrainCamNodes;
    unsigned int m_uiTimeLastChange;
    unsigned int m_uiTimeWeLeftIdle_StillNoInput;
    unsigned int m_uiTimeWeEnteredIdle;
    unsigned int m_uiTimeTransitionStart;
    unsigned int m_uiTransitionDuration;
    unsigned int m_uiTransitionDurationTargetCoors;
    int m_BlurBlue;
    int m_BlurGreen;
    int m_BlurRed;
    int m_BlurType;
    int m_iWorkOutSpeedThisNumFrames;
    int m_iNumFramesSoFar;
    int m_iCurrentTrainCamNode;
    int m_motionBlur;
    int m_imotionBlurAddAlpha;
    int m_iCheckCullZoneThisNumFrames;
    int m_iZoneCullFrameNumWereAt;
    int WhoIsInControlOfTheCamera;
    int m_nCarZoom;
    float m_fCarZoomBase;
    float m_fCarZoomTotal;
    float m_fCarZoomSmoothed;
    float m_fCarZoomValueScript;
    int m_nPedZoom;
    float m_fPedZoomBase;
    float m_fPedZoomTotal;
    float m_fPedZoomSmoothed;
    float m_fPedZoomValueScript;
    float CamFrontXNorm;
    float CamFrontYNorm;
    float DistanceToWater;
    float HeightOfNearestWater;
    float FOVDuringInter;
    float LODDistMultiplier;
    float GenerationDistMultiplier;
    float m_fAlphaSpeedAtStartInter;
    float m_fAlphaWhenInterPol;
    float m_fAlphaDuringInterPol;
    float m_fBetaDuringInterPol;
    float m_fBetaSpeedAtStartInter;
    float m_fBetaWhenInterPol;
    float m_fFOVWhenInterPol;
    float m_fFOVSpeedAtStartInter;
    float m_fStartingBetaForInterPol;
    float m_fStartingAlphaForInterPol;
    float m_PedOrientForBehindOrInFront;
    float m_CameraAverageSpeed;
    float m_CameraSpeedSoFar;
    float m_fCamShakeForce;
    float m_fFovForTrain;
    float m_fFOV_Wide_Screen;
    float m_fNearClipScript;
    float m_fOldBetaDiff;
    float m_fPositionAlongSpline;
    float m_ScreenReductionPercentage;
    float m_ScreenReductionSpeed;
    float m_AlphaForPlayerAnim1rstPerson;
    float Orientation;
    float PlayerExhaustion;
    float SoundDistUp;
    float SoundDistUpAsRead;
    float SoundDistUpAsReadOld;
    float m_fAvoidTheGeometryProbsTimer;
    short m_nAvoidTheGeometryProbsDirn;
    short pad;
    float m_fWideScreenReductionAmount;
    float m_fStartingFOVForInterPol;
    CCam Cams[3];
    void *pToGarageWeAreIn; // CGarage
    void *pToGarageWeAreInForHackAvoidFirstPerson; // CGarage
    CQueuedMode m_PlayerMode;
    CQueuedMode PlayerWeaponMode;
    CVector m_PreviousCameraPosition;
    CVector m_RealPreviousCameraPosition;
    CVector m_cvecAimingTargetCoors;
    CVector m_vecFixedModeVector;
    CVector m_vecFixedModeSource;
    CVector m_vecFixedModeUpOffSet;
    CVector m_vecCutSceneOffset;
    CVector m_cvecStartingSourceForInterPol;
    CVector m_cvecStartingTargetForInterPol;
    CVector m_cvecStartingUpForInterPol;
    CVector m_cvecSourceSpeedAtStartInter;
    CVector m_cvecTargetSpeedAtStartInter;
    CVector m_cvecUpSpeedAtStartInter;
    CVector m_vecSourceWhenInterPol;
    CVector m_vecTargetWhenInterPol;
    CVector m_vecUpWhenInterPol;
    CVector m_vecClearGeometryVec;
    CVector m_vecGameCamPos;
    CVector SourceDuringInter;
    CVector TargetDuringInter;
    CVector UpDuringInter;
    CVector m_vecAttachedCamOffset;
    CVector m_vecAttachedCamLookAt;
    float m_fAttachedCamAngle;
    void *m_pRwCamera; // RwCamera_0
    CEntity *pTargetEntity;
    CEntity *pAttachedEntity;
    CCamPathSplines m_arrPathArray[4];
    bool m_bMirrorActive;
    bool m_bResetOldMatrix;
    short pad0;
    float m_sphereMapRadius;
    CMatrix m_cameraMatrix;
    CMatrix m_cameraMatrixOld;
    CMatrix m_viewMatrix;
    CMatrix m_matInverse;
    CMatrix m_matMirrorInverse;
    CMatrix m_matMirror;
    CVector m_vecFrustumNormals[4];
    CVector m_vecFrustumWorldNormals[4];
    CVector m_vecFrustumWorldNormals_Mirror[4];
    float m_fFrustumPlaneOffsets[4];
    float m_fFrustumPlaneOffsets_Mirror[4];
    CVector m_vecOldSourceForInter;
    CVector m_vecOldFrontForInter;
    CVector m_vecOldUpForInter;
    float m_vecOldFOVForInter;
    float m_fFloatingFade;
    float m_fFloatingFadeMusic;
    float m_fTimeToFadeOut;
    float m_fTimeToFadeMusic;
    float m_fTimeToWaitToFadeMusic;
    float m_fFractionInterToStopMoving;
    float m_fFractionInterToStopCatchUp;
    float m_fFractionInterToStopMovingTarget;
    float m_fFractionInterToStopCatchUpTarget;
    float m_fGaitSwayBuffer;
    float m_fScriptPercentageInterToStopMoving;
    float m_fScriptPercentageInterToCatchUp;
    unsigned int m_fScriptTimeForInterPolation;
    short m_iFadingDirection;
    short pad90;
    int m_iModeObbeCamIsInForCar;
    short m_iModeToGoTo;
    short m_iMusicFadingDirection;
    short m_iTypeOfSwitch;
    short pad1;
    unsigned int m_uiFadeTimeStarted;
    unsigned int m_uiFadeTimeStartedMusic;
    int m_numExtrasEntitysToIgnore;
    CEntity *m_pExtrasEntitysToIgnore[2];
    float m_duckZMod;
    float m_duckZMod_Aim;
    float m_vectorTrackStartTime;
    float m_vectorTrackEndTime;
    CVector m_vectorTrackFrom;
    CVector m_vectorTrackTo;
    bool m_bVectorTrackSmoothEnds;
    char pad3[3];
    CVector m_VectorTrackScript;
    bool m_bVectorTrackScript;
    char pad4[3];
    float m_DegreeHandShake;
    float m_shakeStartTime;
    float m_shakeEndTime;
    bool m_bShakeScript;
    char pad5[3];
    int m_CurShakeCam;
    float m_FOVLerpStartTime;
    float m_FOVLerpEndTime;
    float m_FOVLerpStart;
    float m_FOVLerpEnd;
    bool m_bFOVLerpSmoothEnds;
    bool m_bFOVScript;
    short pad6;
    float m_MyFOV;
    float m_vectorMoveStartTime;
    float m_vectorMoveEndTime;
    CVector m_vectorMoveFrom;
    CVector m_vectorMoveTo;
    bool m_bVectorMoveSmoothEnds;
    char pad7[3];
    CVector m_VectorMoveScript;
    bool m_bVectorMoveScript;
    bool m_bPersistFOV;
    bool m_bPersistCamPos;
    bool m_bPersistCamLookAt;
    bool m_bForceCinemaCam;
    char pad8[3];
    class CVehicleCamTweak 
    {                                      
        int m_ModelId;
        float m_LenMod;
        float m_TargetZMod;
        float m_PitchMod;
    } m_VehicleTweaks[5];
    bool m_bInitedVehicleCamTweaks;
    char pad9[3];
    float m_VehicleTweakLenMod;
    float m_VehicleTweakTargetZMod;
    float m_VehicleTweakPitchMod;
    int m_VehicleTweakLastModelId;
    float m_TimeStartFOVLO;
    float m_TimeEndFOVLO;
    float m_FOVStartFOVLO;
    CVector m_StartPositionFOVLO;
    float m_FOVTargetFOVLO;
    bool m_bSmoothLerpFOVLO;
    bool m_bInitLockOnCam;
    char pad10[6];
};

struct CControllerState // sizeof=0x30
{                                       // XREF: CPad/r CPad/r ...
    short LeftStickX;
    short LeftStickY;
    short RightStickX;
    short RightStickY;
    short LeftShoulder1;
    short LeftShoulder2;
    short RightShoulder1;
    short RightShoulder2;
    short DPadUp;
    short DPadDown;
    short DPadLeft;
    short DPadRight;
    short Start;
    short Select;
    short ButtonSquare;
    short ButtonTriangle;
    short ButtonCross;
    short ButtonCircle;
    short ShockButtonL;
    short ShockButtonR;
    short m_bChatIndicated;
    short m_bPedWalk;
    short m_bVehicleMouseLook;
    short m_bRadioTrackSkip;
};

struct CPad // sizeof=0x158
{                                       // XREF: .bss:Pads/r
    CControllerState NewState;
    CControllerState OldState;
    int currentPadId;
    short SteeringLeftRightBuffer[10];
    int DrunkDrivingBufferUsed;
    CControllerState PCTempKeyState;
    CControllerState PCTempJoyState;
    CControllerState PCTempMouseState;
    unsigned char Phase;
    char pad;
    short ShakeDur;
    unsigned short DisablePlayerControls;
    unsigned char ShakeFreq;
    unsigned char JustOutOfFrontEnd;
    float fCruisingSpeed;
    bool bRhythm;
    bool bWheelie;
    bool bStoppie;
    bool bApplyGas;
    bool bApplyBrake;
    bool bLaneCorrection;
    bool bUsingDebugCamera;
    bool bUsingDebugPlayerFreeze;
    bool bHasCheated;
    bool bDisableForbiddenTerr;
    bool bStopRhythmSprites;
    bool bDoorsLocked;
    bool bRegainControl;
    char pad1[3];
    float fBikeStickY;
    bool bApplyBrakes;
    bool bDisablePlayerEnterCar;
    bool bDisablePlayerDuck;
    bool bDisablePlayerFireWeapon;
    bool bDisablePlayerFireWeaponWithL1;
    bool bDisablePlayerCycleWeapon;
    bool bDisablePlayerJump;
    bool bDisablePlayerDisplayVitalStats;
    unsigned int LastTimeTouched;
    int AverageWeapon;
    int AverageEntries;
    unsigned int NoShakeBeforeThis;
    unsigned char NoShakeFreq;
    bool bHasJetPack;
    bool bRocketLocked;
    bool bTrainPassenger;
    bool bSavedForTrain;
    bool bSetSteeringMode;
    bool bSetTouchLayout;
    char pad2;
    float m_fAccelX;
    float m_fAccelY;
    float m_fAccelZ;
};

//extern unsigned int pGTASA;
//extern CCamera* TheCamera;