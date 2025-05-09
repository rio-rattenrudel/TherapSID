#pragma once
#include <Arduino.h>
#include "preset.h"
#include "voice_state.hpp"
#include "sid.h"

template <typename T> class optional;
extern bool noArp1key;
extern Preset preset_data;
extern VoiceState<SIDVOICES_TOTAL> voice_state;
extern Glide glide[SIDVOICES_TOTAL];
extern byte aftertouch;
extern bool aftertouchToLfo;
extern bool sendLfo;
extern int presetScrollTimer;
extern bool volumeChanged;
extern bool sendArp;
extern bool lfoNewRand[3];
extern float bend, bend1, bend2, bend3;
extern bool sync;
extern bool autoChord;
extern bool autoChordChanged;
extern bool clearAutoChord;
extern bool heldKeys[128];
extern bool chordKeys[128];
extern byte chordRoot;
extern bool pwLimit;
extern bool toolMode;
extern bool cvActive[3];
extern int lfoStep[3];
extern byte lfo[3];
extern bool velocityToLfo;
extern bool modToLfo;
extern byte velocityLast;
extern byte modWheelLast;
inline bool arping() { return preset_data.arp_speed_base < 250; }
extern bool filterAssignmentChanged;
extern byte lfoClockSpeedPending[3];
extern int lfoTune1, lfoTune2, lfoTune3, lfoTune4, lfoTune5, lfoTune6, lfoTune7, lfoTune8, lfoTune9;
extern float lfoFine1, lfoFine2, lfoFine3, lfoFine4, lfoFine5, lfoFine6, lfoFine7, lfoFine8, lfoFine9;
extern bool jumble;
extern byte masterChannel;
extern byte masterChannelOut;
extern byte filterSetupSidOffset[3];
extern byte filterSetupSidRange[3];
extern byte voice1Channel;
extern byte voice2Channel;
extern byte voice3Channel;
extern int arpCounter;
extern int arpSpeed;
extern int arpRange;
extern byte pitchBendUp;
extern byte pitchBendDown;
extern int arpRound;
extern byte tuneLfoRange;
extern byte arpCount;
extern byte envState;
extern int env;
extern int a4, d4, s4, r4;
extern byte lastNote;
extern int arpStepBase;
extern int lfoSpeed[3];

extern byte preset;
extern byte volume;
extern byte arp_output_note;
extern optional<byte> control_voltage_note;

// voice_index[operator] tells you the preset's voice to read the operator's settings from.
extern byte* voice_index; // array of size SIDVOICES_TOTAL, set depending on preset.paraphonic

// EEPROM Memory Mapping
#define EEPROM_ADDR_COOKIE 0x0000  // Two bytes
#define EEPROM_ADDR_VERSION 0x0002 // Two bytes
#define EEPROM_ADDR_PRESET_LAST 0x0004
#define EEPROM_ADDR_MIDI_IN_CH_MASTER 0x0005
#define EEPROM_ADDR_MIDI_OUT_CH_MASTER 0x0006
#define EEPROM_ADDR_SEND_LFO 0x0007
#define EEPROM_ADDR_SEND_ARP 0x0008
#define EEPROM_ADDR_MW_TO_LFO1 0x0009
#define EEPROM_ADDR_AT_TO_LFO2 0x000a
#define EEPROM_ADDR_VEL_TO_LFO3 0x000b
#define EEPROM_ADDR_MASTER_VOLUME 0x000c
#define EEPROM_ADDR_PW_LIMIT 0x000d
#define EEPROM_ADDR_MIDI_IN_CH_VOICE1 0x000e
#define EEPROM_ADDR_MIDI_IN_CH_VOICE2 0x000f
#define EEPROM_ADDR_MIDI_IN_CH_VOICE3 0x0010
#define EEPROM_ADDR_PITCH_BEND_UP 0x0011
#define EEPROM_ADDR_PITCH_BEND_DOWN 0x0012
#define EEPROM_ADDR_NO_ARP_1_KEY 0x0013
// ARMSID settings are one chip per nibble
#define EEPROM_ADDR_ARMSID_CHIP_EMULATION 0x0014
#define EEPROM_ADDR_ARMSID_ADSR_BUG_FIXED 0x0015
#define EEPROM_ADDR_ARMSID_6581_FILTER_STRENGTH 0x0016
#define EEPROM_ADDR_ARMSID_6581_FILTER_LOW 0x0017
#define EEPROM_ADDR_ARMSID_8580_FILTER_CENTRAL 0x0018
#define EEPROM_ADDR_ARMSID_8580_FILTER_LOW 0x0019
// FILTER SETUP
#define EEPROM_ADDR_SID1_OFFSET 0x001a
#define EEPROM_ADDR_SID1_RANGE 0x001b
#define EEPROM_ADDR_SID2_OFFSET 0x001c
#define EEPROM_ADDR_SID2_RANGE 0x001d
#define EEPROM_ADDR_SID3_OFFSET 0x001e
#define EEPROM_ADDR_SID3_RANGE 0x001f

// Preset storage from here
#define EEPROM_ADDR_PRESET_DATA_START 0x0028
// block of main storage for presets
#define EEPROM_ADDR_PRESET(preset) (EEPROM_ADDR_PRESET_DATA_START + (preset - 1) * PRESET_DATA_SIZE)
// one extra byte of storage per preset - located at two different places (1-96, 97-99)
#define EEPROM_ADDR_PRESET_EXTRA_BYTE(preset)                                                                          \
	(preset <= 96) ? EEPROM_ADDR_PRESET_DATA_START + PRESET_NUMBER_MAX* PRESET_DATA_SIZE + preset - 1                  \
	               : EEPROM_ADDR_PRESET_DATA_START + preset - 100

#define EEPROM_COOKIE_VALUE (uint16_t)19028
#define EEPROM_FORMAT_VERSION_V1 (uint16_t)0x0001
#define EEPROM_FORMAT_VERSION_V2 (uint16_t)0x0002
#define EEPROM_FORMAT_VERSION_V3 (uint16_t)0x0003
#define EEPROM_FORMAT_VERSION_V4 (uint16_t)0x0004

#define EEPROM_SETTINGS_NUM_BYTES (EEPROM_ADDR_SID3_RANGE - EEPROM_ADDR_PRESET_LAST + 1)

// Global settings, stored in EEPROM
struct globalSetting {
	void* variable;
	uint16_t eepromAddress;
	byte minValue;
	byte maxValue;
	byte defaultValue;
	byte ccMessageToolMode;
	bool isBaseOne;
};

extern const globalSetting globalSettings[EEPROM_SETTINGS_NUM_BYTES];