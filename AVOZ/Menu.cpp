#include "Menu.h"
#include "Controls.h"
#include "Hooks.h" 
#include "Interfaces.h"
#include "CRC32.h"

#define WINDOW_WIDTH 933
#define WINDOW_HEIGHT 585

GreatnessWindow Menu::Window;

void SaveLegitCallbk()
{
	switch (Menu::Window.MiscTab.ConfigBox.GetIndex())
	{
	case 0:
		GUI.SaveWindowState(&Menu::Window, "legit.cfg");
		break;
	case 1:
		GUI.SaveWindowState(&Menu::Window, "rage.cfg");
		break;
	case 2:
		GUI.SaveWindowState(&Menu::Window, "mmhvh.cfg");
		break;
	case 3:
		GUI.SaveWindowState(&Menu::Window, "casual.cfg");
		break;
	}
}

void LoadLegitCallbk()
{
	switch (Menu::Window.MiscTab.ConfigBox.GetIndex())
	{
	case 0:
		GUI.LoadWindowState(&Menu::Window, "legit.cfg");
		break;
	case 1:
		GUI.LoadWindowState(&Menu::Window, "rage.cfg");
		break;
	case 2:
		GUI.LoadWindowState(&Menu::Window, "mmhvh.cfg");
		break;
	case 3:
		GUI.LoadWindowState(&Menu::Window, "casual.cfg");
		break;
	}
}

void SaveRageCallbk()
{
	GUI.SaveWindowState(&Menu::Window, "rage.cfg");
}

void LoadRageCallbk()
{
	GUI.LoadWindowState(&Menu::Window, "rage.cfg");
}

void UnLoadCallbk()
{
	DoUnload = true;
}

void KnifeApplyCallbk()
{
	static ConVar* Meme = Interfaces::CVar->FindVar("cl_fullupdate");
	Meme->nFlags &= ~FCVAR_CHEAT;
	Interfaces::Engine->ClientCmd_Unrestricted("cl_fullupdate");
	bGlovesNeedUpdate = true;
}

void GlovesApplyCallbk()
{
	static ConVar* Meme = Interfaces::CVar->FindVar("cl_fullupdate");
	Meme->nFlags &= ~FCVAR_CHEAT;
	Interfaces::Engine->ClientCmd_Unrestricted("cl_fullupdate");
	bGlovesNeedUpdate = true;
}

void GreatnessWindow::Setup()
{
	SetPosition(350, 50);
	SetSize(WINDOW_WIDTH, WINDOW_HEIGHT);
	SetTitle("                                                                       Greatness");

	RegisterTab(&RageBotTab);
	//RegisterTab(&LegitBotTab);
	RegisterTab(&VisualsTab);
	RegisterTab(&MiscTab);
	RegisterTab(&ColorsTab);

	RECT Client = GetClientArea();
	Client.bottom -= 29;

	RageBotTab.Setup();
	//LegitBotTab.Setup();
	VisualsTab.Setup();
	MiscTab.Setup();
	ColorsTab.Setup();

#pragma region Bottom Buttons

	SaveButton.SetText("Save");
	SaveButton.SetCallback(SaveLegitCallbk);
	SaveButton.SetPosition(150, Client.bottom - 200);

	LoadButton.SetText("Load");
	LoadButton.SetCallback(LoadLegitCallbk);
	LoadButton.SetPosition(100, Client.bottom - 200);

	ColorsTab.RegisterControl(&SaveButton);
	ColorsTab.RegisterControl(&ConfigBox);
	ColorsTab.RegisterControl(&LoadButton);

#pragma endregion
}

void CRageBotTab::Setup()
{
	SetTitle("b");


#pragma region Aimbot

	AimbotGroup.SetPosition(14, 71);
	AimbotGroup.SetText("Aimbot");
	AimbotGroup.AddTab(CGroupTab("Aimbot", 1));
	AimbotGroup.AddTab(CGroupTab("Accuracy", 2));
	AimbotGroup.AddTab(CGroupTab("Hitscan", 3));
	AimbotGroup.SetSize(376, 350);
	RegisterControl(&AimbotGroup);
	RegisterControl(&Active);

	Active.SetFileId("active");
	AimbotGroup.PlaceLabledControl(1, "Active Rage", this, &Active);

	AimbotEnable.SetFileId("aim_enable");
	AimbotGroup.PlaceLabledControl(1, "Enable", this, &AimbotEnable);

	AimbotAutoFire.SetFileId("aim_autofire");
	AimbotGroup.PlaceLabledControl(1, "Auto fire", this, &AimbotAutoFire);

	AimbotFov.SetFileId("aim_fov");
	AimbotFov.SetBoundaries(0.f, 180.f);
	AimbotFov.SetValue(39.f);
	AimbotGroup.PlaceLabledControl(1, "Maximum fov", this, &AimbotFov);

	AimbotSilentAim.SetFileId("aim_silent");
	AimbotGroup.PlaceLabledControl(1, "Silent aim", this, &AimbotSilentAim);

	AutoRevolver.SetFileId("aim_autorevolver");
	AimbotGroup.PlaceLabledControl(1, "Auto revolver", this, &AutoRevolver);

	AimbotAimStep.SetFileId("aim_aimstep");
	AimbotGroup.PlaceLabledControl(1, "Aim step", this, &AimbotAimStep);

	AimbotKeyPress.SetFileId("aim_usekey");
	AimbotGroup.PlaceLabledControl(1, "Aimbot on key", this, &AimbotKeyPress);

	AimbotKeyBind.SetFileId("aim_key");
	AimbotGroup.PlaceLabledControl(1, "Aimbot key", this, &AimbotKeyBind);

	AWPAtBody.SetFileId("aim_awpatbody");
	AimbotGroup.PlaceLabledControl(2, "AWP body aim", this, &AWPAtBody);

	AccuracyHitchance.SetFileId("acc_chance");
	AccuracyHitchance.SetBoundaries(0, 100);
	AccuracyHitchance.SetValue(0);
	AimbotGroup.PlaceLabledControl(2, "Hit chance", this, &AccuracyHitchance);

	BaimIfUnderXHealth.SetFileId("acc_BaimIfUnderXHealth");
	BaimIfUnderXHealth.SetBoundaries(0, 100);
	BaimIfUnderXHealth.SetValue(0);
	AimbotGroup.PlaceLabledControl(2, "Baim if hp lower than", this, &BaimIfUnderXHealth);

	AccuracyRecoil.SetFileId("acc_norecoil");
	AimbotGroup.PlaceLabledControl(2, "Remove recoil", this, &AccuracyRecoil);

	AccuracyAutoWall.SetFileId("acc_awall");
	AimbotGroup.PlaceLabledControl(2, "Auto wall", this, &AccuracyAutoWall);

	AccuracyMinimumDamage.SetFileId("acc_mindmg");
	AccuracyMinimumDamage.SetBoundaries(1.f, 99.f);
	AccuracyMinimumDamage.SetValue(1.f);
	AimbotGroup.PlaceLabledControl(2, "Autowall damage", this, &AccuracyMinimumDamage);

	AccuracyAutoScope.SetFileId("acc_scope");
	AimbotGroup.PlaceLabledControl(2, "Auto scope", this, &AccuracyAutoScope);

	AimbotResolver.SetFileId("acc_aaa");
	AimbotResolver.AddItem("Default");
	AimbotResolver.AddItem("Experimental");
	AimbotGroup.PlaceLabledControl(2, "Resolver", this, &AimbotResolver);

	TargetSelection.SetFileId("tgt_selection");
	TargetSelection.AddItem("Closest To Crosshair");
	TargetSelection.AddItem("Distance");
	TargetSelection.AddItem("Lowest Health");
	TargetSelection.AddItem("Threat");
	TargetSelection.AddItem("Next Shot");
	AimbotGroup.PlaceLabledControl(3, "Selection", this, &TargetSelection);

	TargetHitbox.SetFileId("tgt_hitbox");
	TargetHitbox.AddItem("Head");
	TargetHitbox.AddItem("Neck");
	TargetHitbox.AddItem("Chest");
	TargetHitbox.AddItem("Pelvis");
	TargetHitbox.AddItem("Shin");
	AimbotGroup.PlaceLabledControl(3, "Hitbox", this, &TargetHitbox);

	TargetHitscan.SetFileId("tgt_hitscan");
	TargetHitscan.AddItem("Off"); //0
	TargetHitscan.AddItem("Low"); // 1
	TargetHitscan.AddItem("Medium"); // 2
	TargetHitscan.AddItem("High"); // 3
	TargetHitscan.AddItem("Body only"); // 4
	AimbotGroup.PlaceLabledControl(3, "Hitscan", this, &TargetHitscan);

	TargetMultipoint.SetFileId("tgt_multipoint");
	AimbotGroup.PlaceLabledControl(3, "Multipoint", this, &TargetMultipoint);

	TargetPointscale.SetFileId("tgt_pointscale");
	TargetPointscale.SetBoundaries(0.f, 10.f);
	TargetPointscale.SetValue(5.f);
	AimbotGroup.PlaceLabledControl(3, "Pointscale", this, &TargetPointscale);
#pragma endregion Targetting controls 

#pragma endregion Aimbot Controls Get Setup in here

#pragma endregion Targetting controls 

#pragma region AntiAim
	AntiAimGroup.SetPosition(408, 71);
	AntiAimGroup.SetText("Anti Aim");
	AntiAimGroup.AddTab(CGroupTab("Main", 1));
	AntiAimGroup.AddTab(CGroupTab("Misc", 2));
	AntiAimGroup.SetSize(360, 300);
	RegisterControl(&AntiAimGroup);

	AntiAimEnable.SetFileId("aa_enable");
	AntiAimGroup.PlaceLabledControl(1, "Enable", this, &AntiAimEnable);

	AntiAimPitch.SetFileId("aa_x");
	AntiAimPitch.AddItem("Off");
	AntiAimPitch.AddItem("Halfdown");
	AntiAimPitch.AddItem("Jitter");
	AntiAimPitch.AddItem("Emotion");
	AntiAimPitch.AddItem("Up");
	AntiAimPitch.AddItem("Zero");
	AntiAimPitch.AddItem("Custom");
	AntiAimGroup.PlaceLabledControl(1, "Pitch", this, &AntiAimPitch);

	AntiAimYaw.SetFileId("aa_y");
	AntiAimYaw.AddItem("Off");
	AntiAimYaw.AddItem("Fast Spin");
	AntiAimYaw.AddItem("Slow Spin");
	AntiAimYaw.AddItem("Jitter");
	AntiAimYaw.AddItem("180 Jitter");
	AntiAimYaw.AddItem("Backwards");
	AntiAimYaw.AddItem("Backwards Jitter");
	AntiAimYaw.AddItem("Sideways Switch");
	AntiAimYaw.AddItem("Sideways Right");
	AntiAimYaw.AddItem("Sideways Left");
	AntiAimYaw.AddItem("LBY");
	AntiAimYaw.AddItem("LBY Jitter");
	AntiAimYaw.AddItem("LBY Sideways");
	AntiAimYaw.AddItem("LBY Spin");
	AntiAimYaw.AddItem("LBY Break");
	AntiAimGroup.PlaceLabledControl(1, "Real yaw", this, &AntiAimYaw);

	FakeYaw.SetFileId("fakeaa");
	FakeYaw.AddItem("Off");
	FakeYaw.AddItem("Fast Spin");
	FakeYaw.AddItem("Slow Spin");
	FakeYaw.AddItem("Jitter");
	FakeYaw.AddItem("180 Jitter");
	FakeYaw.AddItem("Backwards");
	FakeYaw.AddItem("Backwards Jitter");
	FakeYaw.AddItem("Sideways Switch");
	FakeYaw.AddItem("Sideways Right");
	FakeYaw.AddItem("Sideways Left");
	FakeYaw.AddItem("LBY");
	FakeYaw.AddItem("LBY Jitter");
	FakeYaw.AddItem("LBY Sideways");
	FakeYaw.AddItem("LBY Spin");
	FakeYaw.AddItem("LBY Break");
	AntiAimGroup.PlaceLabledControl(1, "Fake yaw", this, &FakeYaw);

	AntiAimTarget.SetFileId("aa_target");
	AntiAimGroup.PlaceLabledControl(1, "At targets", this, &AntiAimTarget);

	ManualAAEnable.SetFileId("manual_antiaim");
	AntiAimGroup.PlaceLabledControl(2, "Enable manual aa", this, &ManualAAEnable);

	ManualAASwitch.SetFileId("manual_aaswitchkey");
	AntiAimGroup.PlaceLabledControl(2, "Manual switch key", this, &ManualAASwitch);


#pragma endregion  AntiAim controls get setup in here
}

/*void CLegitBotTab::Setup()
{
	SetTitle("");

	ActiveLabel.SetPosition(16, -15);
	ActiveLabel.SetText("Active");
	RegisterControl(&ActiveLabel);

	Active.SetFileId("active");
	Active.SetPosition(66, -15);
	RegisterControl(&Active);*/

/*#pragma region Aimbot
	AimbotGroup.SetPosition(16, 11);
	AimbotGroup.SetText("Aimbot");
	AimbotGroup.SetSize(240, 170);
	RegisterControl(&AimbotGroup);

	AimbotEnable.SetFileId("aim_enable");
	AimbotGroup.PlaceLabledControl("Enable", this, &AimbotEnable);

	AimbotAutoFire.SetFileId("aim_autofire");
	AimbotGroup.PlaceLabledControl("Auto Fire", this, &AimbotAutoFire);

	AimbotFriendlyFire.SetFileId("aim_friendfire");
	AimbotGroup.PlaceLabledControl("Friendly Fire", this, &AimbotFriendlyFire);

	AimbotSmokeCheck.SetFileId("otr_smokecheck");
	AimbotGroup.PlaceLabledControl("Smoke Check", this, &AimbotSmokeCheck);

	AimbotKeyPress.SetFileId("aim_usekey");
	AimbotGroup.PlaceLabledControl("On Key", this, &AimbotKeyPress);

	AimbotKeyBind.SetFileId("aim_key");
	AimbotGroup.PlaceLabledControl("Key Bind", this, &AimbotKeyBind);

#pragma endregion Aimbot shit

#pragma region Triggerbot
	TriggerGroup.SetPosition(272, 11);
	TriggerGroup.SetText("Triggerbot");
	TriggerGroup.SetSize(240, 170);
	RegisterControl(&TriggerGroup);

	TriggerEnable.SetFileId("trig_enable");
	TriggerGroup.PlaceLabledControl("Enable", this, &TriggerEnable);

	TriggerKeyPress.SetFileId("trig_onkey");
	TriggerGroup.PlaceLabledControl("On Key Press", this, &TriggerKeyPress);

	TriggerKeyBind.SetFileId("trig_key");
	TriggerGroup.PlaceLabledControl("Key Bind", this, &TriggerKeyBind);

	TriggerRecoil.SetFileId("trig_recoil");
	TriggerGroup.PlaceLabledControl("Recoil Control", this, &TriggerRecoil);

	TriggerSmokeCheck.SetFileId("trig_smokecheck");
	TriggerGroup.PlaceLabledControl("Smoke Check", this, &TriggerSmokeCheck);

	TriggerDelay.SetFileId("trig_time");
	TriggerDelay.SetBoundaries(0, 100);
	TriggerDelay.SetValue(1);
	TriggerGroup.PlaceLabledControl("Delay", this, &TriggerDelay);

#pragma endregion Triggerbot stuff

#pragma region TriggerbotFilter
	TriggerFilterGroup.SetPosition(528, 11);
	TriggerFilterGroup.SetText("Triggerbot Filter");
	TriggerFilterGroup.SetSize(240, 170);
	RegisterControl(&TriggerFilterGroup);

	TriggerHead.SetFileId("trig_head");
	TriggerFilterGroup.PlaceLabledControl("Head", this, &TriggerHead);

	TriggerChest.SetFileId("trig_chest");
	TriggerFilterGroup.PlaceLabledControl("Chest", this, &TriggerChest);

	TriggerStomach.SetFileId("trig_stomach");
	TriggerFilterGroup.PlaceLabledControl("Stomach", this, &TriggerStomach);

	TriggerArms.SetFileId("trig_arms");
	TriggerFilterGroup.PlaceLabledControl("Arms", this, &TriggerArms);

	TriggerLegs.SetFileId("trig_legs");
	TriggerFilterGroup.PlaceLabledControl("Legs", this, &TriggerLegs);

	TriggerTeammates.SetFileId("trig_teammates");
	TriggerFilterGroup.PlaceLabledControl("Friendly Fire", this, &TriggerTeammates);

#pragma endregion TriggerbotFilter stuff

#pragma region Main Weapon
	WeaponMainGroup.SetPosition(16, 208);
	WeaponMainGroup.SetText("Rifles");
	WeaponMainGroup.SetSize(240, 135);
	RegisterControl(&WeaponMainGroup);

	WeaponMainHitbox.SetFileId("main_hitbox");
	WeaponMainHitbox.AddItem("Head");
	WeaponMainHitbox.AddItem("Neck");
	WeaponMainHitbox.AddItem("Chest");
	WeaponMainHitbox.AddItem("Stomach");
	WeaponMainHitbox.AddItem("Multihitbox");
	WeaponMainGroup.PlaceLabledControl("Hitbox", this, &WeaponMainHitbox);

	WeaponMainSpeed.SetFileId("main_speed");
	WeaponMainSpeed.SetBoundaries(0.f, 100.f);
	WeaponMainSpeed.SetValue(1.f);
	WeaponMainGroup.PlaceLabledControl("Max Speed", this, &WeaponMainSpeed);

	WeaponMainFoV.SetFileId("main_fov");
	WeaponMainFoV.SetBoundaries(0.f, 30.f);
	WeaponMainFoV.SetValue(3.5f);
	WeaponMainGroup.PlaceLabledControl("Field of View", this, &WeaponMainFoV);

	WeaponMainRecoil.SetFileId("main_recoil");
	WeaponMainRecoil.SetBoundaries(0.f, 2.f);
	WeaponMainRecoil.SetValue(1.f);
	WeaponMainGroup.PlaceLabledControl("Recoil Control", this, &WeaponMainRecoil);

	WeaponMainAimtime.SetValue(0);
	WeaoponMainStartAimtime.SetValue(0);

#pragma endregion

#pragma region Pistols
	WeaponPistGroup.SetPosition(272, 208);
	WeaponPistGroup.SetText("Pistols");
	WeaponPistGroup.SetSize(240, 135);
	RegisterControl(&WeaponPistGroup);

	WeaponPistHitbox.SetFileId("pist_hitbox");
	WeaponPistHitbox.AddItem("Head");
	WeaponPistHitbox.AddItem("Neck");
	WeaponPistHitbox.AddItem("Chest");
	WeaponPistHitbox.AddItem("Stomach");
	WeaponPistHitbox.AddItem("Multihitbox");
	WeaponPistGroup.PlaceLabledControl("Hitbox", this, &WeaponPistHitbox);

	WeaponPistSpeed.SetFileId("pist_speed");
	WeaponPistSpeed.SetBoundaries(0.f, 100.f);
	WeaponPistSpeed.SetValue(1.0f);
	WeaponPistGroup.PlaceLabledControl("Max Speed", this, &WeaponPistSpeed);

	WeaponPistFoV.SetFileId("pist_fov");
	WeaponPistFoV.SetBoundaries(0.f, 30.f);
	WeaponPistFoV.SetValue(3.f);
	WeaponPistGroup.PlaceLabledControl("Field of View", this, &WeaponPistFoV);

	WeaponPistRecoil.SetFileId("pist_recoil");
	WeaponPistRecoil.SetBoundaries(0.f, 2.f);
	WeaponPistRecoil.SetValue(1.f);
	WeaponPistGroup.PlaceLabledControl("Recoil Control", this, &WeaponPistRecoil);

	WeaponPistAimtime.SetValue(0);
	WeaoponPistStartAimtime.SetValue(0);

#pragma endregion

#pragma region Snipers
	WeaponSnipGroup.SetPosition(528, 208);
	WeaponSnipGroup.SetText("Snipers");
	WeaponSnipGroup.SetSize(240, 135);
	RegisterControl(&WeaponSnipGroup);

	WeaponSnipHitbox.SetFileId("snip_hitbox");
	WeaponSnipHitbox.AddItem("Head");
	WeaponSnipHitbox.AddItem("Neck");
	WeaponSnipHitbox.AddItem("Chest");
	WeaponSnipHitbox.AddItem("Stomach");
	WeaponSnipHitbox.AddItem("Multihitbox");
	WeaponSnipGroup.PlaceLabledControl("Hitbox", this, &WeaponSnipHitbox);

	WeaponSnipSpeed.SetFileId("snip_speed");
	WeaponSnipSpeed.SetBoundaries(0.f, 100.f);
	WeaponSnipSpeed.SetValue(1.5f);
	WeaponSnipGroup.PlaceLabledControl("Max Speed", this, &WeaponSnipSpeed);

	WeaponSnipFoV.SetFileId("snip_fov");
	WeaponSnipFoV.SetBoundaries(0.f, 30.f);
	WeaponSnipFoV.SetValue(2.f);
	WeaponSnipGroup.PlaceLabledControl("Field of View", this, &WeaponSnipFoV);

	WeaponSnipRecoil.SetFileId("snip_recoil");
	WeaponSnipRecoil.SetBoundaries(0.f, 2.f);
	WeaponSnipRecoil.SetValue(1.f);
	WeaponSnipGroup.PlaceLabledControl("Recoil Control", this, &WeaponSnipRecoil);

	WeaponSnipAimtime.SetValue(0);
	WeaoponSnipStartAimtime.SetValue(0);

#pragma region MPs
	WeaponMpGroup.SetPosition(16, 365);
	WeaponMpGroup.SetText("MPs");
	WeaponMpGroup.SetSize(240, 136);
	RegisterControl(&WeaponMpGroup);

	WeaponMpHitbox.SetFileId("mps_hitbox");
	WeaponMpHitbox.AddItem("Head");
	WeaponMpHitbox.AddItem("Neck");
	WeaponMpHitbox.AddItem("Chest");
	WeaponMpHitbox.AddItem("Stomach");
	WeaponMpHitbox.AddItem("Multihitbox");
	WeaponMpGroup.PlaceLabledControl("Hitbox", this, &WeaponMpHitbox);

	WeaponMpSpeed.SetFileId("mps_speed");
	WeaponMpSpeed.SetBoundaries(0.f, 100.f);
	WeaponMpSpeed.SetValue(1.0f);
	WeaponMpGroup.PlaceLabledControl("Max Speed", this, &WeaponMpSpeed);

	WeaponMpFoV.SetFileId("mps_fov");
	WeaponMpFoV.SetBoundaries(0.f, 30.f);
	WeaponMpFoV.SetValue(4.f);
	WeaponMpGroup.PlaceLabledControl("Field of View", this, &WeaponMpFoV);

	WeaponMpRecoil.SetFileId("mps_recoil");
	WeaponMpRecoil.SetBoundaries(0.f, 2.f);
	WeaponMpRecoil.SetValue(1.f);
	WeaponMpGroup.PlaceLabledControl("Recoil Control", this, &WeaponMpRecoil);

	WeaponMpAimtime.SetValue(0);
	WeaoponMpStartAimtime.SetValue(0);
#pragma endregion

#pragma region Shotguns
	WeaponShotgunGroup.SetPosition(272, 365);
	WeaponShotgunGroup.SetText("Shotguns");
	WeaponShotgunGroup.SetSize(240, 136);
	RegisterControl(&WeaponShotgunGroup);

	WeaponShotgunHitbox.SetFileId("shotgun_hitbox");
	WeaponShotgunHitbox.AddItem("Head");
	WeaponShotgunHitbox.AddItem("Neck");
	WeaponShotgunHitbox.AddItem("Chest");
	WeaponShotgunHitbox.AddItem("Stomach");
	WeaponShotgunHitbox.AddItem("Multihitbox");
	WeaponShotgunGroup.PlaceLabledControl("Hitbox", this, &WeaponShotgunHitbox);

	WeaponShotgunSpeed.SetFileId("shotgun_speed");
	WeaponShotgunSpeed.SetBoundaries(0.f, 100.f);
	WeaponShotgunSpeed.SetValue(1.0f);
	WeaponShotgunGroup.PlaceLabledControl("Max Speed", this, &WeaponShotgunSpeed);

	WeaponShotgunFoV.SetFileId("shotgun_fov");
	WeaponShotgunFoV.SetBoundaries(0.f, 30.f);
	WeaponShotgunFoV.SetValue(3.f);
	WeaponShotgunGroup.PlaceLabledControl("Field of View", this, &WeaponShotgunFoV);

	WeaponShotgunRecoil.SetFileId("snip_recoil");
	WeaponShotgunRecoil.SetBoundaries(0.f, 2.f);
	WeaponShotgunRecoil.SetValue(1.f);
	WeaponShotgunGroup.PlaceLabledControl("Recoil Control", this, &WeaponShotgunRecoil);

	WeaponShotgunAimtime.SetValue(0);
	WeaoponShotgunStartAimtime.SetValue(0);

#pragma endregion

#pragma region Machineguns
	WeaponMGGroup.SetPosition(528, 365);
	WeaponMGGroup.SetText("Heavy");
	WeaponMGGroup.SetSize(240, 136);
	RegisterControl(&WeaponMGGroup);

	WeaponMGHitbox.SetFileId("mg_hitbox");
	WeaponMGHitbox.AddItem("Head");
	WeaponMGHitbox.AddItem("Neck");
	WeaponMGHitbox.AddItem("Chest");
	WeaponMGHitbox.AddItem("Stomach");
	WeaponMGHitbox.AddItem("Multihitbox");
	WeaponMGGroup.PlaceLabledControl("Hitbox", this, &WeaponMGHitbox);

	WeaponMGSpeed.SetFileId("mg_speed");
	WeaponMGSpeed.SetBoundaries(0.f, 100.f);
	WeaponMGSpeed.SetValue(1.0f);
	WeaponMGGroup.PlaceLabledControl("Max Speed", this, &WeaponMGSpeed);

	WeaponMGFoV.SetFileId("mg_fov");
	WeaponMGFoV.SetBoundaries(0.f, 30.f);
	WeaponMGFoV.SetValue(4.f);
	WeaponMGGroup.PlaceLabledControl("Field of View", this, &WeaponMGFoV);

	WeaponMGRecoil.SetFileId("mg_recoil");
	WeaponMGRecoil.SetBoundaries(0.f, 2.f);
	WeaponMGRecoil.SetValue(1.f);
	WeaponMGGroup.PlaceLabledControl("Recoil Control", this, &WeaponMGRecoil);

	WeaponMGAimtime.SetValue(0);
	WeaoponMGStartAimtime.SetValue(0);

#pragma endregion 
}*/

void CVisualTab::Setup()
{
	SetTitle("c");


#pragma region Options
	OptionsGroup.SetText("Options");
	OptionsGroup.SetPosition(16, 71);
	OptionsGroup.SetSize(193, 460);
	RegisterControl(&OptionsGroup);

	Active.SetFileId("active");
	OptionsGroup.PlaceLabledControl(1, "Active Visuals", this, &Active);

	OptionsBox.SetFileId("opt_box");
	OptionsBox.AddItem("Off");
	OptionsBox.AddItem("2D Box");
	OptionsBox.AddItem("Filled");
	OptionsBox.AddItem("Corners");
	OptionsGroup.PlaceLabledControl(1, "Box", this, &OptionsBox);

	OptionsName.SetFileId("opt_name");
	OptionsGroup.PlaceLabledControl(1, "Name", this, &OptionsName);

	OptionsWeapon.SetFileId("opt_weapone");
	OptionsGroup.PlaceLabledControl(1, "Weapon", this, &OptionsWeapon);

	OptionsArmor.SetFileId("opt_armor");
	OptionsGroup.PlaceLabledControl(1, "Armor", this, &OptionsArmor);


	Ammo.SetFileId("opt_ammo");
	OptionsGroup.PlaceLabledControl(1, "Ammo", this, &Ammo);

	OptionsHealth.SetFileId("opt_hp");
	OptionsGroup.PlaceLabledControl(1, "Health", this, &OptionsHealth);

	OptionsInfo.SetFileId("opt_info");
	OptionsGroup.PlaceLabledControl(1, "Info", this, &OptionsInfo);

	OtherHitmarker.SetFileId("otr_hitmarker");
	OptionsGroup.PlaceLabledControl(1, "Hitmarker", this, &OtherHitmarker);

	OptionsSkeleton.SetFileId("opt_bone");
	OptionsGroup.PlaceLabledControl(1, "Skeleton", this, &OptionsSkeleton);

	OptionsCompRank.SetFileId("opt_comprank");
	OptionsGroup.PlaceLabledControl(1, "Show ranks", this, &OptionsCompRank);

	EntityGlow.SetFileId("opt_entityglow");
	OptionsGroup.PlaceLabledControl(1, "Entity glow", this, &EntityGlow);

	OptionsGlow.SetFileId("opt_glow");
	OptionsGroup.PlaceLabledControl(1, "Glow", this, &OptionsGlow);

	GlowZ.SetFileId("opt_glowz");
	GlowZ.SetBoundaries(0.f, 255.f);
	GlowZ.SetValue(255);
	OptionsGroup.PlaceLabledControl(1, "Glow opacity", this, &GlowZ);

#pragma endregion Setting up the Options controls

#pragma region Filters
	FiltersGroup.SetText("Filters");
	FiltersGroup.SetPosition(225, 71);
	FiltersGroup.SetSize(193, 155);
	RegisterControl(&FiltersGroup);

	FiltersAll.SetFileId("ftr_all");
	FiltersGroup.PlaceLabledControl(2, "All", this, &FiltersAll);

	FiltersPlayers.SetFileId("ftr_players");
	FiltersGroup.PlaceLabledControl(2, "Players", this, &FiltersPlayers);

	FiltersEnemiesOnly.SetFileId("ftr_enemyonly");
	FiltersGroup.PlaceLabledControl(2, "Enemies only", this, &FiltersEnemiesOnly);

	FiltersWeapons.SetFileId("ftr_weaps");
	FiltersGroup.PlaceLabledControl(2, "Weapons", this, &FiltersWeapons);

	FiltersNades.SetFileId("ftr_nades");
	FiltersGroup.PlaceLabledControl(2, "Nades", this, &FiltersNades);

	FiltersC4.SetFileId("ftr_c4");
	FiltersGroup.PlaceLabledControl(2, "C4", this, &FiltersC4);

#pragma endregion Setting up the Filters controls

#pragma region Other
	OtherGroup.SetText("Other");
	OtherGroup.SetPosition(434, 71);
	OtherGroup.SetSize(360, 375);
	RegisterControl(&OtherGroup);

	NightMode.SetFileId("otr_nightmode");
	OtherGroup.PlaceLabledControl(0, "Night Mode", this, &NightMode);

	NightSky.SetFileId("otr_nightsky");
	OtherGroup.PlaceLabledControl(0, "Night Sky", this, &NightSky);

	AAIndicators.SetFileId("otr_aaindicators");
	OtherGroup.PlaceLabledControl(0, "AA indicator", this, &AAIndicators);

	SpecList.SetFileId("otr_speclist");
	OtherGroup.PlaceLabledControl(0, "Spectator List", this, &SpecList);

	OtherNoVisualRecoil.SetFileId("otr_visrecoil");
	OtherGroup.PlaceLabledControl(0, "No Visual Recoil", this, &OtherNoVisualRecoil);

	OtherNoFlash.SetFileId("otr_noflash");
	OtherGroup.PlaceLabledControl(0, "No Flash", this, &OtherNoFlash);

	OtherNoSmoke.SetFileId("otr_nosmoke");
	OtherGroup.PlaceLabledControl(0, "No Smoke", this, &OtherNoSmoke);

	OtherNoScope.SetFileId("otr_noscope");
	OtherGroup.PlaceLabledControl(0, "Remove Scope Borders", this, &OtherNoScope);

	OtherRadar.SetFileId("otr_radar");
	OtherGroup.PlaceLabledControl(0, "Radar", this, &OtherRadar);

	/*Watermark.SetFileId("otr_watermark");
	OtherGroup.PlaceLabledControl(0, "Watermark", this, &Watermark);*/

	OtherNoHands.SetFileId("otr_hands");
	OtherNoHands.AddItem("Off");
	OtherNoHands.AddItem("None");
	OtherNoHands.AddItem("Transparent");
	OtherNoHands.AddItem("Wireframe");
	OtherNoHands.AddItem("Chams");
	OtherNoHands.AddItem("Rainbow");
	OtherGroup.PlaceLabledControl(0, "Hands", this, &OtherNoHands);

	OtherViewmodelFOV.SetFileId("otr_viewfov");
	OtherViewmodelFOV.SetBoundaries(0.f, 180.f);
	OtherViewmodelFOV.SetValue(0.f);
	OtherGroup.PlaceLabledControl(0, "Adjust Viewmodel FOV", this, &OtherViewmodelFOV);

	OtherFOV.SetFileId("otr_fov");
	OtherFOV.SetBoundaries(0.f, 70.f);
	OtherFOV.SetValue(0.f);
	OtherGroup.PlaceLabledControl(0, "Adjust FOV", this, &OtherFOV);

#pragma endregion Setting up the Other controls
}

void CMiscTab::Setup()
{
	SetTitle("d");

#pragma region Other
	OtherGroup.SetPosition(408, 25);
	OtherGroup.SetSize(360, 235);
	OtherGroup.SetText("Other");
	RegisterControl(&OtherGroup);

	//MoonWalk.SetFileId("otr_moonwalk"); //it must work but it is not so need to do something
	//OtherGroup.PlaceLabledControl("MoonWalk (WIP)", this, &MoonWalk);

	OtherSafeMode.SetFileId("otr_safemode");
	OtherSafeMode.SetState(true);
	OtherGroup.PlaceLabledControl(0, "Anti untrusted", this, &OtherSafeMode);

	AutoPistol.SetFileId("otr_autopistol");
	OtherGroup.PlaceLabledControl(0, "Auto pistol", this, &AutoPistol);

	OtherAutoJump.SetFileId("otr_autojump");
	OtherGroup.PlaceLabledControl(0, "Auto jump", this, &OtherAutoJump);


	OtherAutoStrafe.SetFileId("otr_strafe");
	OtherAutoStrafe.AddItem("Off");
	OtherAutoStrafe.AddItem("Legit");
	OtherAutoStrafe.AddItem("Rage");
	OtherGroup.PlaceLabledControl(0, "Auto Strafer", this, &OtherAutoStrafe);

	ClanTag.SetFileId("otr_clantag");
	OtherGroup.PlaceLabledControl(0, "Clantag Changer", this, &ClanTag);

	OtherThirdperson.SetFileId("aa_thirdpsr");
	OtherGroup.PlaceLabledControl(0, "Thirdperson", this, &OtherThirdperson);


#pragma endregion other random options

#pragma region FakeLag
	FakeLagGroup.SetPosition(16, 25);
	FakeLagGroup.SetSize(360, 105);
	FakeLagGroup.SetText("Fakelag");
	RegisterControl(&FakeLagGroup);

	FakeLagEnable.SetFileId("fakelag_enable");
	FakeLagGroup.PlaceLabledControl(0, "Enable", this, &FakeLagEnable);

	FakeLagChoke.SetFileId("fakelag_choke");
	FakeLagChoke.SetBoundaries(0, 14);
	FakeLagChoke.SetValue(0);
	FakeLagGroup.PlaceLabledControl(0, "Choke factor", this, &FakeLagChoke);


	FakeLagTyp.SetFileId("fakelag_typ");
	FakeLagTyp.AddItem("Off");
	FakeLagTyp.AddItem("Normal");
	FakeLagTyp.AddItem("Fluctuate");
	FakeLagGroup.PlaceLabledControl(0, "Mode", this, &FakeLagTyp);

	ConfigGroup.SetPosition(16, 200);
	ConfigGroup.SetText("Configs");
	ConfigGroup.SetSize(300, 100);
	RegisterControl(&ConfigGroup);

	ConfigBox.SetFileId("cfg_box");
	ConfigBox.AddItem("legit");
	ConfigBox.AddItem("rage");
	ConfigBox.AddItem("mm hvh");
	ConfigBox.AddItem("casual");
	ConfigGroup.PlaceLabledControl(0, "Config", this, &ConfigBox);

#pragma endregion fakelag shit
	/*
 #pragma region Buybot
	BuyBotGroup.SetPosition(16, 105);
	BuyBotGroup.SetSize(360, 150);
	BuyBotGroup.SetText("Buybot");
	RegisterControl(&BuyBotGroup);

	EnableBuyBot.SetFileId("bb_enable");
	BuyBotGroup.PlaceLabledControl("Enable", this, &EnableBuyBot);

	BuyBot.SetFileId("buybot");
	BuyBot.AddItem("Off");
	BuyBot.AddItem("Ak/M4");
	BuyBot.AddItem("AWP");
	BuyBot.AddItem("Auto + Duals");
	BuyBotGroup.PlaceLabledControl("Buy Bot", this, &BuyBot);

	BuyBotGrenades.SetFileId("buybot_grenades");
	BuyBotGrenades.AddItem("Off");
	BuyBotGrenades.AddItem("Flash + Smoke + HE");
	BuyBotGrenades.AddItem("Flash + Smoke + HE + Molo");
	BuyBotGroup.PlaceLabledControl("Buy Grenades", this, &BuyBotGrenades);

	BuyBotKevlar.SetFileId("buybot_kevlar");
	BuyBotGroup.PlaceLabledControl("Buy Armor", this, &BuyBotKevlar);

	BuyBotDefuser.SetFileId("buybot_defuser");
	BuyBotGroup.PlaceLabledControl("Buy Defuse Kit", this, &BuyBotDefuser);

	*/
#pragma endregion Buybot

}

void CColorTab::Setup()
{
	SetTitle("e");
#pragma region Visual Colors

	ColorsGroup.SetText("Colors");
	ColorsGroup.SetPosition(200, 81);
	ColorsGroup.AddTab(CGroupTab("Colors1", 1));
	ColorsGroup.AddTab(CGroupTab("Colors2", 2));
	ColorsGroup.SetSize(300, 346);
	RegisterControl(&ColorsGroup);


	CTColorVisR.SetFileId("ct_color_vis_r");
	CTColorVisR.SetBoundaries(0.f, 255.f);
	CTColorVisR.SetValue(0.f);
	ColorsGroup.PlaceLabledControl(1, "CT visible red", this, &CTColorVisR);

	CTColorVisG.SetFileId("ct_color_vis_g");
	CTColorVisG.SetBoundaries(0.f, 255.f);
	CTColorVisG.SetValue(230.f);
	ColorsGroup.PlaceLabledControl(1, "CT visible green", this, &CTColorVisG);

	CTColorVisB.SetFileId("ct_color_vis_b");
	CTColorVisB.SetBoundaries(0.f, 255.f);
	CTColorVisB.SetValue(15.f);
	ColorsGroup.PlaceLabledControl(1, "CT visible blue", this, &CTColorVisB);

	CTColorNoVisR.SetFileId("ct_color_no_vis_r");
	CTColorNoVisR.SetBoundaries(0.f, 255.f);
	CTColorNoVisR.SetValue(0.f);
	ColorsGroup.PlaceLabledControl(1, "CT not visible red", this, &CTColorNoVisR);

	CTColorNoVisG.SetFileId("ct_color_no_vis_g");
	CTColorNoVisG.SetBoundaries(0.f, 255.f);
	CTColorNoVisG.SetValue(235.f);
	ColorsGroup.PlaceLabledControl(1, "CT Not Visible Green", this, &CTColorNoVisG);

	CTColorNoVisB.SetFileId("ct_color_no_vis_b");
	CTColorNoVisB.SetBoundaries(0.f, 255.f);
	CTColorNoVisB.SetValue(10.f);
	ColorsGroup.PlaceLabledControl(1, "CT Not Visible Blue", this, &CTColorNoVisB);

	TColorVisR.SetFileId("t_color_vis_r");
	TColorVisR.SetBoundaries(0.f, 255.f);
	TColorVisR.SetValue(0.f);
	ColorsGroup.PlaceLabledControl(1, "T Visible Red", this, &TColorVisR);

	TColorVisG.SetFileId("t_color_vis_g");
	TColorVisG.SetBoundaries(0.f, 255.f);
	TColorVisG.SetValue(50.f);
	ColorsGroup.PlaceLabledControl(1, "T Visible Green", this, &TColorVisG);

	TColorVisB.SetFileId("t_color_vis_b");
	TColorVisB.SetBoundaries(0.f, 255.f);
	TColorVisB.SetValue(220.f);
	ColorsGroup.PlaceLabledControl(1, "T Visible Blue", this, &TColorVisB);

	TColorNoVisR.SetFileId("t_color_no_vis_r");
	TColorNoVisR.SetBoundaries(0.f, 255.f);
	TColorNoVisR.SetValue(0.f);
	ColorsGroup.PlaceLabledControl(1, "T Not Visible Red", this, &TColorNoVisR);

	TColorNoVisG.SetFileId("t_color_no_vis_g");
	TColorNoVisG.SetBoundaries(0.f, 255.f);
	TColorNoVisG.SetValue(50.f);
	ColorsGroup.PlaceLabledControl(1, "T Not Visible Green", this, &TColorNoVisG);

	TColorNoVisB.SetFileId("t_color_no_vis_b");
	TColorNoVisB.SetBoundaries(0.f, 255.f);
	TColorNoVisB.SetValue(220.f);
	ColorsGroup.PlaceLabledControl(1, "T Not Visible Blue", this, &TColorNoVisB);

	GlowR.SetFileId("GlowR");
	GlowR.SetBoundaries(0.f, 255.f);
	GlowR.SetValue(230.f);
	ColorsGroup.PlaceLabledControl(2, "Glow Red", this, &GlowR);

	GlowG.SetFileId("GlowG");
	GlowG.SetBoundaries(0.f, 255.f);
	GlowG.SetValue(0.f);
	ColorsGroup.PlaceLabledControl(2, "Glow Green", this, &GlowG);

	GlowB.SetFileId("GlowB");
	GlowB.SetBoundaries(0.f, 255.f);
	GlowB.SetValue(0.f);
	ColorsGroup.PlaceLabledControl(2, "Glow Blue", this, &GlowB);

	CTChamsR.SetFileId("ctchamsr");
	CTChamsR.SetBoundaries(0.f, 255.f);
	CTChamsR.SetValue(40.f);
	Colors2Group.PlaceLabledControl(2, "CT Chams Red", this, &CTChamsR);

	CTChamsG.SetFileId("ctchamsg");
	CTChamsG.SetBoundaries(0.f, 255.f);
	CTChamsG.SetValue(120.f);
	ColorsGroup.PlaceLabledControl(2, "CT Chams Green", this, &CTChamsG);

	CTChamsB.SetFileId("ctchamsb");
	CTChamsB.SetBoundaries(0.f, 255.f);
	CTChamsB.SetValue(170.f);
	Colors2Group.PlaceLabledControl(2, "CT Chams Blue", this, &CTChamsB);

	TChamsR.SetFileId("tchamsr");
	TChamsR.SetBoundaries(0.f, 255.f);
	TChamsR.SetValue(210.f);
	ColorsGroup.PlaceLabledControl(2, "T Chams Red", this, &TChamsR);

	TChamsG.SetFileId("tchamsg");
	TChamsG.SetBoundaries(0.f, 255.f);
	TChamsG.SetValue(20.f);
	ColorsGroup.PlaceLabledControl(2, "T Chams Green", this, &TChamsG);

	TChamsB.SetFileId("tchamsb");
	TChamsB.SetBoundaries(0.f, 255.f);
	TChamsB.SetValue(70.f);
	ColorsGroup.PlaceLabledControl(2, "T Chams Blue", this, &TChamsB);

	TChamsB.SetFileId("tchamsb");
	TChamsB.SetBoundaries(0.f, 255.f);
	TChamsB.SetValue(70.f);
	ColorsGroup.PlaceLabledControl(2, "T Chams Blue", this, &TChamsB);

#pragma endregion

/*#pragma region GloveModel
	Gloves.SetPosition(400, 90);
	Gloves.SetText("Override Gloves");
	Gloves.SetSize(376, 100);
	RegisterControl(&Gloves);

	EnableGloves.SetFileId("gloves_enable");
	Gloves.PlaceLabledControl("Enable", this, &EnableGloves);

	GloveModel.SetFileId("glove_model");
	GloveModel.AddItem("Off");
	GloveModel.AddItem("Bloodhound");
	GloveModel.AddItem("Handwrap");
	GloveModel.AddItem("Driver");
	GloveModel.AddItem("Sport");
	GloveModel.AddItem("Motorcycle");
	GloveModel.AddItem("Specialist");
	Gloves.PlaceLabledControl("Glove Model", this, &GloveModel);

	GloveSkin.SetFileId("glove_skin");
	GloveSkin.AddItem("Off");
	GloveSkin.AddItem("Bloodhound - Snakebite");
	GloveSkin.AddItem("Bloodhound - Charred");
	GloveSkin.AddItem("Bloodhound - Guerrilla");
	GloveSkin.AddItem("Bloodhound - Bronzed");
	GloveSkin.AddItem("Handwrap - Slaughter");
	GloveSkin.AddItem("Handwrap - Badlands");
	GloveSkin.AddItem("Handwrap - Leather");
	GloveSkin.AddItem("Handwrap - Spruce DDPAT");
	GloveSkin.AddItem("Driver - Crimson Weave");
	GloveSkin.AddItem("Driver - Lunar Weave");
	GloveSkin.AddItem("Driver - Diamondback");
	GloveSkin.AddItem("Driver - Convoy");
	GloveSkin.AddItem("Sport - Pandoras Box");
	GloveSkin.AddItem("Sport - Hedge Naze");
	GloveSkin.AddItem("Sport - Superconductor");
	GloveSkin.AddItem("Sport - Arid");
	GloveSkin.AddItem("Motorcycle - Spearmint");
	GloveSkin.AddItem("Motorcycle - Cool Mint");
	GloveSkin.AddItem("Motorcycle - Boom");
	GloveSkin.AddItem("Motorcycle - Eclipse");
	GloveSkin.AddItem("Specialist - Crimson Kimono");
	GloveSkin.AddItem("Specialist - Emerald Web");
	GloveSkin.AddItem("Specialist - Foundation");
	GloveSkin.AddItem("Specialist - Forest DDPAT");
	Gloves.PlaceLabledControl("Glove Skin", this, &GloveSkin);

	GlovesApply.SetText("Apply Gloves");
	GlovesApply.SetCallback(GlovesApplyCallbk);
	GlovesApply.SetPosition(407, 200);
	GlovesApply.SetSize(360, 106);
	RegisterControl(&GlovesApply);

	KnifeGroup.SetPosition(407, 245);
	KnifeGroup.SetText("Override Knife");
	KnifeGroup.SetSize(360, 100);
	RegisterControl(&KnifeGroup);

	SkinEnable.SetFileId("otr_skinenable");
	KnifeGroup.PlaceLabledControl("Enable", this, &SkinEnable);

	KnifeModel.SetFileId("knife_model");
	KnifeModel.AddItem("Bayonet");
	KnifeModel.AddItem("Bowie Knife");
	KnifeModel.AddItem("Butterfly Knife");
	KnifeModel.AddItem("Falchion Knife");
	KnifeModel.AddItem("Flip Knife");
	KnifeModel.AddItem("Gut Knife");
	KnifeModel.AddItem("Huntsman Knife");
	KnifeModel.AddItem("Karambit");
	KnifeModel.AddItem("M9 Bayonet");
	KnifeModel.AddItem("Shadow Daggers");
	KnifeGroup.PlaceLabledControl("Knife", this, &KnifeModel);

	KnifeSkin.SetFileId("knife_skin");
	KnifeGroup.PlaceLabledControl("Skin ID", this, &KnifeSkin);

	KnifeApply.SetText("Apply Changes");
	KnifeApply.SetCallback(KnifeApplyCallbk);
	KnifeApply.SetPosition(407, 355);
	KnifeApply.SetSize(360, 106);
	RegisterControl(&KnifeApply);

#pragma endregion*/
}

void Menu::SetupMenu()
{
	Window.Setup();

	GUI.RegisterWindow(&Window);
	GUI.BindWindow(VK_INSERT, &Window);
}

void Menu::DoUIFrame()
{
	if (Window.VisualsTab.FiltersAll.GetState())
	{
		Window.VisualsTab.FiltersC4.SetState(true);
		Window.VisualsTab.FiltersPlayers.SetState(true);
		Window.VisualsTab.FiltersWeapons.SetState(true);
		Window.VisualsTab.FiltersNades.SetState(true);
	}

	GUI.Update();
	GUI.Draw();
	
}