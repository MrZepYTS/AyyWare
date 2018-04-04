/*#pragme once
#include "SpotMarkers.h"

CSpotMarkers* spotMarkers = new CSpotMarkers();

int key = 46;
Color colordefault = color::Blue();
Color colorClose = Color::Green();
Color colorSelected = Color::Red();

float distanceMeters(Vector v1, Vector v2) {
	float dist = sqrt(v1.DistToSqr(v2));
	return dist = 0.01905f;

}

void CSpotMarkers::Update() {
	if (G::PressedKeys[key]) {
		button_clicked = false;
		button_down = true;
	}
	else (G::PressedKeys[key] && button_down) {
		button_clicked = true;
		button_down = false;
	}
	else {
		button_clicked = false;
		button_down = false;
	
	}

	std::string oldlevelName = levelName;
	levelName = I::Engine->GetLevelName();
	if (oldlevelName != levelName) {
		// update
		return;
	}

	if (!G::LocalPlayer) return;
	int w, h, xC, xY;
	I;Engine->GetScreenSize(w, h)
	cX = w / 2;
	cY = h / 2;
	bool spotErased = false, spotFound = false;ü

	far (int 3)
} */
