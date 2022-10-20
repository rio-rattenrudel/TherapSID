#include "globals.h"
#include "leds.h"
#include "display.h"

void showVersion() {
	digit(1, versionDecimal);
	digit(0, version);
	mydisplay.setLed(0, 7, 6, 1);
}

void leds() { ledSet(32, 1); }

void showFilterAssigns() {
	if (filterEnabled[0]) {
		ledSet(1, 1);
		ledSet(2, 1);
		ledSet(3, 1);
		ledSet(4, 1);
	} else {
		ledSet(1, 0);
		ledSet(2, 0);
		ledSet(3, 0);
		ledSet(4, 0);
	}

	if (filterEnabled[1]) {
		ledSet(5, 1);
		ledSet(6, 1);
		ledSet(7, 1);
		ledSet(8, 1);
	} else {
		ledSet(5, 0);
		ledSet(6, 0);
		ledSet(7, 0);
		ledSet(8, 0);
	}

	if (filterEnabled[2]) {
		ledSet(9, 1);
		ledSet(10, 1);
		ledSet(11, 1);
		ledSet(12, 1);
	} else {
		ledSet(9, 0);
		ledSet(10, 0);
		ledSet(11, 0);
		ledSet(12, 0);
	}
}

void unShowFilterAssigns() {

	ledSet(1, bitRead(sid[4], 6));
	ledSet(2, bitRead(sid[4], 4));
	ledSet(3, bitRead(sid[4], 5));
	ledSet(4, bitRead(sid[4], 7));

	ledSet(5, bitRead(sid[11], 6));
	ledSet(6, bitRead(sid[11], 4));
	ledSet(7, bitRead(sid[11], 5));
	ledSet(8, bitRead(sid[11], 7));

	ledSet(9, bitRead(sid[18], 6));
	ledSet(10, bitRead(sid[18], 4));
	ledSet(11, bitRead(sid[18], 5));
	ledSet(12, bitRead(sid[18], 7));
}

void ledSet(byte number, bool value) {

	switch (number) {
		case 1:
			mydisplay.setLed(0, 0, 1, value);
			break;
		case 2:
			mydisplay.setLed(0, 1, 1, value);
			break;
		case 3:
			mydisplay.setLed(0, 2, 1, value);
			break;
		case 4:
			mydisplay.setLed(0, 3, 1, value);
			break;

		case 5:
			mydisplay.setLed(0, 4, 1, value);
			break;
		case 6:
			mydisplay.setLed(0, 5, 1, value);
			break;
		case 7:
			mydisplay.setLed(0, 6, 1, value);
			break;
		case 8:
			mydisplay.setLed(0, 7, 1, value);
			break;

		case 9:
			mydisplay.setLed(0, 0, 2, value);
			break;
		case 10:
			mydisplay.setLed(0, 1, 2, value);
			break;
		case 11:
			mydisplay.setLed(0, 2, 2, value);
			break;
		case 12:
			mydisplay.setLed(0, 3, 2, value);
			break;

		case 13:
			mydisplay.setLed(0, 4, 2, value);
			break;
		case 14:
			mydisplay.setLed(0, 5, 2, value);
			break;
		case 15:
			mydisplay.setLed(0, 6, 2, value);
			break;

		case 16:
			mydisplay.setLed(0, 7, 2, value);
			break;
		case 17:
			mydisplay.setLed(0, 0, 3, value);
			break;

		case 18:
			mydisplay.setLed(0, 1, 3, value);
			break;
		case 19:
			mydisplay.setLed(0, 2, 3, value);
			break;

		case 20:
			mydisplay.setLed(0, 3, 3, value);
			break;
		case 21:
			mydisplay.setLed(0, 4, 3, value);
			break;

		case 22:
			mydisplay.setLed(0, 5, 3, value);
			break;
		case 23:
			mydisplay.setLed(0, 6, 3, value);
			break;
		case 24:
			mydisplay.setLed(0, 7, 3, value);
			break;
		case 25:
			mydisplay.setLed(0, 0, 4, value);
			break;
		case 26:
			mydisplay.setLed(0, 1, 4, value);
			break;

		case 27:
			mydisplay.setLed(0, 2, 4, value);
			break;
		case 28:
			mydisplay.setLed(0, 3, 4, value);
			break;
		case 29:
			mydisplay.setLed(0, 4, 4, value);
			break;

		case 30:
			mydisplay.setLed(0, 5, 4, value);
			break;
		case 31:
			mydisplay.setLed(0, 6, 4, value);
			break;
	}
}

/*
  0
5   1
  6
4   2
  3   7
*/

void rightDot() {

	mydisplay.setLed(0, 7, 7, 1);

	dotTimer = 50;
}

void leftDot() {

	mydisplay.setLed(0, 7, 6, 1);
	dotTimer = 50;
}

void ledNumber(int number) {

	if (!frozen) {
		if (number < 0)
			number = -number;
		if (number < 100) {
			digit(0, number / 10);
			digit(1, number - (number / 10) * 10);
		}
	}
}
void digit(byte channel, byte number) {
	switch (number) {

		case 18: // E
			mydisplay.setLed(0, 0, 6 + channel, 1);
			mydisplay.setLed(0, 5, 6 + channel, 1);
			mydisplay.setLed(0, 1, 6 + channel, 0);
			mydisplay.setLed(0, 6, 6 + channel, 1);
			mydisplay.setLed(0, 4, 6 + channel, 1);
			mydisplay.setLed(0, 2, 6 + channel, 0);
			mydisplay.setLed(0, 3, 6 + channel, 1);
			break;
		case 17: // A
			mydisplay.setLed(0, 0, 6 + channel, 1);
			mydisplay.setLed(0, 5, 6 + channel, 1);
			mydisplay.setLed(0, 1, 6 + channel, 1);
			mydisplay.setLed(0, 6, 6 + channel, 1);
			mydisplay.setLed(0, 4, 6 + channel, 1);
			mydisplay.setLed(0, 2, 6 + channel, 1);
			mydisplay.setLed(0, 3, 6 + channel, 0);

			break;

		case 16: // r
			mydisplay.setLed(0, 0, 6 + channel, 0);
			mydisplay.setLed(0, 5, 6 + channel, 0);
			mydisplay.setLed(0, 1, 6 + channel, 0);
			mydisplay.setLed(0, 6, 6 + channel, 1);
			mydisplay.setLed(0, 4, 6 + channel, 1);
			mydisplay.setLed(0, 2, 6 + channel, 0);
			mydisplay.setLed(0, 3, 6 + channel, 0);

			break;

		case 15: // d
			mydisplay.setLed(0, 0, 6 + channel, 0);
			mydisplay.setLed(0, 5, 6 + channel, 0);
			mydisplay.setLed(0, 1, 6 + channel, 1);
			mydisplay.setLed(0, 6, 6 + channel, 1);
			mydisplay.setLed(0, 4, 6 + channel, 1);
			mydisplay.setLed(0, 2, 6 + channel, 1);
			mydisplay.setLed(0, 3, 6 + channel, 1);

			break;

		case 14: // P
			mydisplay.setLed(0, 0, 6 + channel, 1);
			mydisplay.setLed(0, 5, 6 + channel, 1);
			mydisplay.setLed(0, 1, 6 + channel, 1);
			mydisplay.setLed(0, 6, 6 + channel, 1);
			mydisplay.setLed(0, 4, 6 + channel, 1);
			mydisplay.setLed(0, 2, 6 + channel, 0);
			mydisplay.setLed(0, 3, 6 + channel, 0);

			break;

		case 13: // U
			mydisplay.setLed(0, 0, 6 + channel, 0);
			mydisplay.setLed(0, 5, 6 + channel, 1);
			mydisplay.setLed(0, 1, 6 + channel, 1);
			mydisplay.setLed(0, 6, 6 + channel, 0);
			mydisplay.setLed(0, 4, 6 + channel, 1);
			mydisplay.setLed(0, 2, 6 + channel, 1);
			mydisplay.setLed(0, 3, 6 + channel, 1);

			break;

		case 12: // F
			mydisplay.setLed(0, 0, 6 + channel, 1);
			mydisplay.setLed(0, 5, 6 + channel, 1);
			mydisplay.setLed(0, 1, 6 + channel, 0);
			mydisplay.setLed(0, 6, 6 + channel, 1);
			mydisplay.setLed(0, 4, 6 + channel, 1);
			mydisplay.setLed(0, 2, 6 + channel, 0);
			mydisplay.setLed(0, 3, 6 + channel, 0);

			break;
		case 11: // L
			mydisplay.setLed(0, 0, 6 + channel, 0);
			mydisplay.setLed(0, 5, 6 + channel, 1);
			mydisplay.setLed(0, 1, 6 + channel, 0);
			mydisplay.setLed(0, 6, 6 + channel, 0);
			mydisplay.setLed(0, 4, 6 + channel, 1);
			mydisplay.setLed(0, 2, 6 + channel, 0);
			mydisplay.setLed(0, 3, 6 + channel, 1);

			break;

		case 10: // C
			mydisplay.setLed(0, 0, 6 + channel, 1);
			mydisplay.setLed(0, 5, 6 + channel, 1);
			mydisplay.setLed(0, 1, 6 + channel, 0);
			mydisplay.setLed(0, 6, 6 + channel, 0);
			mydisplay.setLed(0, 4, 6 + channel, 1);
			mydisplay.setLed(0, 2, 6 + channel, 0);
			mydisplay.setLed(0, 3, 6 + channel, 1);

			break;

		case 9:
			mydisplay.setLed(0, 0, 6 + channel, 1);
			mydisplay.setLed(0, 5, 6 + channel, 1);
			mydisplay.setLed(0, 1, 6 + channel, 1);
			mydisplay.setLed(0, 6, 6 + channel, 1);
			mydisplay.setLed(0, 4, 6 + channel, 0);
			mydisplay.setLed(0, 2, 6 + channel, 1);
			mydisplay.setLed(0, 3, 6 + channel, 0);

			break;

		case 8:
			mydisplay.setLed(0, 0, 6 + channel, 1);
			mydisplay.setLed(0, 5, 6 + channel, 1);
			mydisplay.setLed(0, 1, 6 + channel, 1);
			mydisplay.setLed(0, 6, 6 + channel, 1);
			mydisplay.setLed(0, 4, 6 + channel, 1);
			mydisplay.setLed(0, 2, 6 + channel, 1);
			mydisplay.setLed(0, 3, 6 + channel, 1);

			break;

		case 7:
			mydisplay.setLed(0, 0, 6 + channel, 1);
			mydisplay.setLed(0, 5, 6 + channel, 0);
			mydisplay.setLed(0, 1, 6 + channel, 1);
			mydisplay.setLed(0, 6, 6 + channel, 0);
			mydisplay.setLed(0, 4, 6 + channel, 0);
			mydisplay.setLed(0, 2, 6 + channel, 1);
			mydisplay.setLed(0, 3, 6 + channel, 0);

			break;
		case 6:
			mydisplay.setLed(0, 0, 6 + channel, 1);
			mydisplay.setLed(0, 5, 6 + channel, 1);
			mydisplay.setLed(0, 1, 6 + channel, 0);
			mydisplay.setLed(0, 6, 6 + channel, 1);
			mydisplay.setLed(0, 4, 6 + channel, 1);
			mydisplay.setLed(0, 2, 6 + channel, 1);
			mydisplay.setLed(0, 3, 6 + channel, 1);

			break;

		case 5:
			mydisplay.setLed(0, 0, 6 + channel, 1);
			mydisplay.setLed(0, 5, 6 + channel, 1);
			mydisplay.setLed(0, 1, 6 + channel, 0);
			mydisplay.setLed(0, 6, 6 + channel, 1);
			mydisplay.setLed(0, 4, 6 + channel, 0);
			mydisplay.setLed(0, 2, 6 + channel, 1);
			mydisplay.setLed(0, 3, 6 + channel, 1);

			break;

		case 4:
			mydisplay.setLed(0, 0, 6 + channel, 0);
			mydisplay.setLed(0, 5, 6 + channel, 1);
			mydisplay.setLed(0, 1, 6 + channel, 1);
			mydisplay.setLed(0, 6, 6 + channel, 1);
			mydisplay.setLed(0, 4, 6 + channel, 0);
			mydisplay.setLed(0, 2, 6 + channel, 1);
			mydisplay.setLed(0, 3, 6 + channel, 0);

			break;

		case 3:
			mydisplay.setLed(0, 0, 6 + channel, 1);
			mydisplay.setLed(0, 5, 6 + channel, 0);
			mydisplay.setLed(0, 1, 6 + channel, 1);
			mydisplay.setLed(0, 6, 6 + channel, 1);
			mydisplay.setLed(0, 4, 6 + channel, 0);
			mydisplay.setLed(0, 2, 6 + channel, 1);
			mydisplay.setLed(0, 3, 6 + channel, 1);

			break;

		case 2:
			mydisplay.setLed(0, 0, 6 + channel, 1);
			mydisplay.setLed(0, 5, 6 + channel, 0);
			mydisplay.setLed(0, 1, 6 + channel, 1);
			mydisplay.setLed(0, 6, 6 + channel, 1);
			mydisplay.setLed(0, 4, 6 + channel, 1);
			mydisplay.setLed(0, 2, 6 + channel, 0);
			mydisplay.setLed(0, 3, 6 + channel, 1);

			break;

		case 1:
			mydisplay.setLed(0, 0, 6 + channel, 0);
			mydisplay.setLed(0, 5, 6 + channel, 0);
			mydisplay.setLed(0, 1, 6 + channel, 1);
			mydisplay.setLed(0, 6, 6 + channel, 0);
			mydisplay.setLed(0, 4, 6 + channel, 0);
			mydisplay.setLed(0, 2, 6 + channel, 1);
			mydisplay.setLed(0, 3, 6 + channel, 0);

			break;

		case 0:
			mydisplay.setLed(0, 0, 6 + channel, 1);
			mydisplay.setLed(0, 5, 6 + channel, 1);
			mydisplay.setLed(0, 1, 6 + channel, 1);
			mydisplay.setLed(0, 6, 6 + channel, 0);
			mydisplay.setLed(0, 4, 6 + channel, 1);
			mydisplay.setLed(0, 2, 6 + channel, 1);
			mydisplay.setLed(0, 3, 6 + channel, 1);

			break;

		case 99: // BLANK
			mydisplay.setLed(0, 0, 6 + channel, 0);
			mydisplay.setLed(0, 5, 6 + channel, 0);
			mydisplay.setLed(0, 1, 6 + channel, 0);
			mydisplay.setLed(0, 6, 6 + channel, 0);
			mydisplay.setLed(0, 4, 6 + channel, 0);
			mydisplay.setLed(0, 2, 6 + channel, 0);
			mydisplay.setLed(0, 3, 6 + channel, 0);

			break;
	}
}
