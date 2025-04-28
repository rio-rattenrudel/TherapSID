#pragma once
#include <Arduino.h>

struct UiState {
	bool filterModeHeld;
	byte lastPot;
	byte selectedLfo;
	byte midiSetup = 0;
	bool filterSetupMode;
	bool saveMode;
};

extern bool scrolled;             // UI
extern bool shape1Pressed;        // UI
extern int shape1PressedTimer;    // UI
extern int resetDownTimer;        // UI
extern int presetScrollSpeed;     // UI
extern int saveBounce;            // UI
extern bool presetUp, presetDown; // UI
extern int presetLast;            // UI??
extern bool fatChanged;           // UI
extern bool resetDown;            // UI
extern int frozen;                // UI
extern byte lfoButtPressed;       // UI
extern int lfoButtTimer;          // UI
extern int filterSetupTimer;      // UI
extern bool filterSetupBlink;     // UI
extern byte filterSetupShowOfSid; // UI
extern byte filterSetupShowIndex; // UI

extern int loadTimer;
extern bool arpModeHeld;

extern UiState ui_state;
