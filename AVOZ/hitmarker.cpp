/*#pragma once

#include "Hacks.h"
#include "hitmarker.h"

bool Config::Visuals::HitMarkers::Enable = true;
float Config::Visuals::HitMarkers::ExpireTime = 0.5f;
float Config::Visuals::HitMarkers::MarkerSize = 12.f;
float Config::Visuals::HitMarkers::TravelDistance = 24.f;

DamageListener::DamageListener()
{
	if (!Interfaces::GameEventManager->AddListener(this, "player_hurt", false))
		Utilities::Error("Unable to add player_hurt listener.");
	else
		Utilities::Log("GameEvent player_hurt registered successfully.");
}

DamageListener::~DamageListener()
{
	Interfaces::GameEventManager->RemoveListener(this);
}

void DamageListener::FireGameEvent(IGameEvent* event)
{
	if (!strcmp(event->GetName(), "player_hurt"))
		if (Interfaces::Engine->GetPlayerForUserID(event->GetInt("attacker")) == Interfaces::Engine->GetLocalPlayer())
		{
			HitMarker_t temp = { Interfaces::globalVars->curtime + Config::Visuals::HitMarkers::ExpireTime, event->GetInt("dmg_health") };

			if (temp.damage > 0 && temp.damage < 100)
				HitMarkers.push_back(temp);
		}
}

int DamageListener::GetEventDebugID(void)
{
	return EVENT_DEBUG_ID_INIT;
}

void DamageListener::PaintTraverse()
{
	static int width = 0;
	static int height = 0;
	if (height == 0 || width == 0)
		Interfaces::Engine->GetScreenSize(width, height);

	float alpha = 0.f;

	for (size_t i = 0; i < HitMarkers.size(); i++)
	{
		float timeDiff = HitMarkers[i].expireTime - Interfaces::Globals->curtime;

		if (timeDiff < 0.f)
		{
			HitMarkers.erase(HitMarkers.begin() + i);
			continue;
		}

		int moveDist = (int)Config::Visuals::HitMarkers::TravelDistance;

		float ratio = 1.f - (timeDiff / Config::Visuals::HitMarkers::ExpireTime);
		alpha = (timeDiff / Config::Visuals::HitMarkers::ExpireTime) * 2.f;
		Render::Text(width / 2 + 6 + ratio * moveDist / 2, height / 2 + 6 + ratio * moveDist, oldColors::FOOTSTEPS_TEAM.CustomAlpha(alpha), Render::Fonts::tahoma16, std::to_string(HitMarkers[i].damage).c_str());
	}

	if (HitMarkers.size() > 0)
	{
		int lineSize = (int)Config::Visuals::HitMarkers::MarkerSize;
		Render::Line(width / 2 - lineSize / 2, height / 2 - lineSize / 2, width / 2 + lineSize / 2, height / 2 + lineSize / 2, oldColors::WHITE40.CustomAlpha(alpha));
		Render::Line(width / 2 + lineSize / 2, height / 2 - lineSize / 2, width / 2 - lineSize / 2, height / 2 + lineSize / 2, oldColors::WHITE40.CustomAlpha(alpha));
	}
} */