#pragma once

#include "GUI.h"
#include "Controls.h"

class CRageBotTab : public CTab
{
public:
	void Setup();

	CLabel ActiveLabel;
	CCheckBox Active;

	CGroupBox AimbotGroup;
	CCheckBox AimbotEnable;
	CCheckBox AimbotAutoFire;
	CSlider  AimbotFov;
	CCheckBox AimbotSilentAim;
	CCheckBox PVSFix;
	CComboBox AimbotResolver;
	CCheckBox AdvancedResolver;
	CCheckBox AutoRevolver;
	CSlider AddFakeYaw;
	CSlider CustomPitch;
	CCheckBox LBY;
	CComboBox FakeYaw;
	CCheckBox LowerbodyFix;
	CCheckBox PreferBodyAim;
	CCheckBox AWPAtBody;
	CSlider BaimIfUnderXHealth;
	CSlider XShots;
	CCheckBox EnginePrediction;
	CCheckBox AimbotAimStep;
	CCheckBox AimbotKeyPress;
	CKeyBind  AimbotKeyBind;
	CKeyBind  AimbotStopKey;
	CComboBox TargetSelection;
	CCheckBox TargetFriendlyFire;
	CComboBox TargetHitbox;
	CComboBox TargetHitscan;
	CCheckBox TargetMultipoint;
	CSlider   TargetPointscale;
	CCheckBox AccuracyRecoil;
	CCheckBox AccuracyAutoWall;
	CSlider AccuracyMinimumDamage;
	CCheckBox AccuracyAutoStop;
	CCheckBox AccuracyAutoCrouch;
	CCheckBox AccuracyAutoScope;
	CSlider   AccuracyHitchance;
	CComboBox AccuracyResolver;
	CCheckBox LBYCorrection;
	CCheckBox Override;
	CSlider OverrideCount;
	CKeyBind OverrideKey;
	CComboBox OverrideMode;

	CGroupBox AntiAimGroup;
	CCheckBox AntiAimEnable;
	CComboBox AntiAimPitch;
	CComboBox AntiAimYaw;
	CSlider YawAdd;
	CSlider FakeYawAdd;
	CCheckBox ManualBox;
	CKeyBind ManualKey;
	CCheckBox FlipAA;
	CCheckBox AntiAimEdge;
	CSlider AntiAimOffset;
	CCheckBox ManualAAEnable;
	CKeyBind ManualAASwitch;
	CKeyBind ManualLeft;
	CKeyBind ManualRight;
	CKeyBind ManualBack;
	CCheckBox AntiAimKnife;
	CCheckBox AntiAimTarget;
};

/*class CLegitBotTab : public CTab
{
public:
	void Setup();

	// Master Switch
	CLabel ActiveLabel;
	CCheckBox Active;

	CGroupBox AimbotGroup;

	CCheckBox AimbotEnable;
	CCheckBox AimbotAutoFire;
	CCheckBox AimbotFriendlyFire;
	CCheckBox AimbotKeyPress;
	CKeyBind  AimbotKeyBind;
	CCheckBox AimbotSmokeCheck;
	CCheckBox BackTrack;

	CGroupBox TriggerGroup;
	CCheckBox TriggerEnable;
	CCheckBox TriggerKeyPress;
	CKeyBind  TriggerKeyBind;
	CCheckBox TriggerHitChance;
	CSlider   TriggerHitChanceAmmount;
	CSlider   TriggerDelay;
	CSlider   TriggerBurst;
	CSlider   TriggerBreak;
	CCheckBox TriggerRecoil;

	CGroupBox TriggerFilterGroup;
	CCheckBox TriggerHead;
	CCheckBox TriggerChest;
	CCheckBox TriggerStomach;
	CCheckBox TriggerArms;
	CCheckBox TriggerLegs;
	CCheckBox TriggerTeammates;
	CCheckBox TriggerFlashCheck;
	CCheckBox TriggerSmokeCheck;

	CGroupBox WeaponMainGroup;
	CSlider   WeaponMainSpeed;
	CSlider   WeaponMainFoV;
	CSlider WeaponMainRecoil;
	CComboBox WeaponMainHitbox;
	CSlider WeaponMainAimtime;
	CSlider WeaoponMainStartAimtime;

	CGroupBox WeaponPistGroup;
	CSlider   WeaponPistSpeed;
	CSlider   WeaponPistFoV;
	CSlider WeaponPistRecoil;
	CComboBox WeaponPistHitbox;
	CSlider WeaponPistAimtime;
	CSlider WeaoponPistStartAimtime;

	CGroupBox WeaponSnipGroup;
	CSlider   WeaponSnipSpeed;
	CSlider   WeaponSnipFoV;
	CSlider WeaponSnipRecoil;
	CComboBox WeaponSnipHitbox;
	CSlider WeaponSnipAimtime;
	CSlider WeaoponSnipStartAimtime;

	CGroupBox WeaponMpGroup;
	CSlider   WeaponMpSpeed;
	CSlider   WeaponMpFoV;
	CSlider WeaponMpRecoil;
	CComboBox WeaponMpHitbox;
	CSlider WeaponMpAimtime;
	CSlider WeaoponMpStartAimtime;

	CGroupBox WeaponShotgunGroup;
	CSlider   WeaponShotgunSpeed;
	CSlider   WeaponShotgunFoV;
	CSlider WeaponShotgunRecoil;
	CComboBox WeaponShotgunHitbox;
	CSlider WeaponShotgunAimtime;
	CSlider WeaoponShotgunStartAimtime;

	CGroupBox WeaponMGGroup;
	CSlider   WeaponMGSpeed;
	CSlider   WeaponMGFoV;
	CSlider WeaponMGRecoil;
	CComboBox WeaponMGHitbox;
	CSlider WeaponMGAimtime;
	CSlider WeaoponMGStartAimtime;
}; */

class CVisualTab : public CTab
{
public:
	void Setup();

	CLabel ActiveLabel;
	CCheckBox Active;

	CGroupBox OptionsGroup;
	CComboBox OptionsBox;
	CCheckBox OptionsName;
	CCheckBox HitmarkerSound;
	CCheckBox OtherHitmarker;
	CCheckBox OptionsHealth;
	CCheckBox OptionsWeapon;
	CCheckBox OptionsInfo;
	CCheckBox AAIndicators;
	CCheckBox BulletTrace;
	CCheckBox Barrels;
	CCheckBox ChamsVisibleOnly;
	CCheckBox Ammo;
	CCheckBox Clock;
	CCheckBox HostageGlow;
	CCheckBox Watermark;
	CCheckBox LBYIndicator;
	CCheckBox GrenadePrediction;
	CCheckBox LocalPlayerESP;
	CCheckBox CanHit;
	CCheckBox OptionsHelmet;
	CCheckBox NightMode;
	CCheckBox OptionsKit;
	CCheckBox SpecList;
	CCheckBox IsScoped;
	CCheckBox CompRank;
	CCheckBox HasDefuser;
	CCheckBox GrenadeTrace;
	CCheckBox Distance;
	CCheckBox DiscoLights;
	CCheckBox Money;
	CCheckBox OptionsDefuse;
	CComboBox OptionsChams;
	CCheckBox OptionsArmor;
	CCheckBox OptionsDefusing;
	CCheckBox SniperCrosshair;
	CSlider  GlowZ;
	CCheckBox OptionsSkeleton;
	CCheckBox NightSky;
	CCheckBox OptionsAimSpot;
	CCheckBox WeaponChams;
	CCheckBox OtherNoScope;
	CCheckBox OptionsCompRank;

	CGroupBox FiltersGroup;
	CCheckBox FiltersAll;
	CCheckBox FiltersPlayers;
	CCheckBox FiltersEnemiesOnly;
	CCheckBox FiltersWeapons;
	CCheckBox FiltersChickens;
	CCheckBox FiltersNades;
	CCheckBox FiltersC4;

	CGroupBox OtherGroup;
	CComboBox OtherCrosshair;
	CComboBox OtherRecoilCrosshair;
	CCheckBox OptionsGlow;
	CCheckBox EntityGlow;
	CCheckBox DisablePostProcess;
	CCheckBox OtherRadar;
	CCheckBox OtherNoVisualRecoil;
	CCheckBox OtherNoSky; 
	CCheckBox OtherNoFlash; 
	CCheckBox OtherNoSmoke;
	CCheckBox OtherAsusWalls;
	CComboBox OtherNoHands;
	CSlider OtherViewmodelFOV;
	CSlider OtherFOV;
};

class CColorTab : public CTab
{
public:
	void Setup();

	CGroupBox ControlGroup;
	CComboBox ControlColor;

	CGroupBox RGBGroup;
	CSlider   MenuR;
	CSlider   MenuG;
	CSlider   MenuB;


	CGroupBox ColorsGroup;
	CSlider CTColorVisR;
	CSlider CTColorVisG;
	CSlider CTColorVisB;

	CSlider TChams;
	CSlider CTChams;
	CSlider CTChamsR;
	CSlider CTChamsG;
	CSlider CTChamsB;
	CSlider TChamsR;
	CSlider TChamsB;
	CSlider TChamsG;

	CGroupBox Gloves;
	CCheckBox EnableGloves;
	CComboBox GloveSkin;
	CComboBox GloveModel;
	CButton GlovesApply;

	CComboBox KnifeModel;
	CCheckBox SkinEnable;
	CTextField KnifeSkin;
	CGroupBox KnifeGroup;
	CButton KnifeApply;

	CSlider CTColorNoVisR;
	CSlider CTColorNoVisG;
	CSlider CTColorNoVisB;

	CLabel ColorSpacer;

	CSlider TColorVisR;
	CSlider TColorVisG;
	CSlider TColorVisB;

	CSlider TColorNoVisR;
	CSlider TColorNoVisG;
	CSlider TColorNoVisB;

	CGroupBox Colors2Group;

	CSlider GlowR;
	CSlider GlowG;
	CSlider GlowB;
};

class CMiscTab : public CTab
{
public:
	void Setup();

	CGroupBox OtherGroup;
	CCheckBox OtherAutoJump;
	CCheckBox OtherEdgeJump;
	CComboBox OtherAutoStrafe;
	CCheckBox OtherSafeMode;
	CCheckBox ChatSpam;
	CKeyBind OtherCircleButton;
	CCheckBox OtherCircleStrafe;
	CKeyBind OtherCircle;
	CTextField CustomClantag;
	CCheckBox CheatsByPass;
	CCheckBox AutoAccept;
	CCheckBox BuyBotKevlar;
	CCheckBox BuyBotDefuser;
	CComboBox BuyBotGrenades;
	CSlider CircleAmount;
	CKeyBind OtherSlowMotion;
	CKeyBind FakeWalk;
	CComboBox FakeLagTyp;
	CCheckBox OtherTeamChat;
	CSlider ClanTagSpeed;
	CSlider	  OtherChatDelay;
	CComboBox NameChanger;
	CCheckBox AutoPistol;
	CCheckBox ClanTag;
	CCheckBox TrashTalk;
	CKeyBind  OtherAirStuck;
	CCheckBox OtherSpectators;
	CCheckBox OtherThirdperson;
	CComboBox OtherClantag;
	CCheckBox EnableBuyBot;
	CComboBox BuyBot;
	CGroupBox BuyBotGroup;
	CSlider WalkBotDistance;
	CSlider WalkBotEdge;
	CCheckBox WalkBot;
	CGroupBox WalkBotGroup;
	CCheckBox MoonWalk;

	CGroupBox FakeLagGroup;
	CCheckBox FakeLagEnable;
	CSlider   FakeLagChoke;

	CGroupBox ConfigGroup;
	CGroupBox Settings;
	CComboBox ConfigBox;
	CButton SettingsSave;
	CButton SettingsLoad;
};

class GreatnessWindow : public CWindow
{
public:
	void Setup();

	CRageBotTab RageBotTab;
	//CLegitBotTab LegitBotTab;
	CVisualTab VisualsTab;
	CMiscTab MiscTab;
	CColorTab ColorsTab;

	CButton SaveButton1;
	CButton LoadButton1;
	CButton SaveButton;
	CButton LoadButton;
	CButton UnloadButton;
	CButton PanicButton;
	CButton ThirdButton;
	CButton ByPass;
	CButton FirstButton;
	CComboBox ConfigBox;
};

namespace Menu
{
	void SetupMenu();
	void DoUIFrame();

	extern GreatnessWindow Window;
};