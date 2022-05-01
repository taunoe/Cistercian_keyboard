/************************************************
 * File: Tauno_keyboard.ino
 * Last edited: 01.05.2022
 * Copyright 2022 Tauno Erik
 ************************************************/
#include <Keyboard.h>

// 1 = Serial.Print
// 0 = Keyboard
const uint8_t DEBUG = 0;

// Keypad settings
const uint8_t NUM_COLS = 4;
const uint8_t NUM_ROWS = 5;

// Xiao RP2040 pins
uint8_t COL_PINS[NUM_COLS] = {D10, D9, D2, D3};
uint8_t ROW_PINS[NUM_ROWS] = {D4, D5, D1, D0, D8}; // Fix on PCB! D6->D1, D7->D0

/*
const char KEYS[NUM_ROWS][NUM_COLS] = {
  {'#', '#', '%', '/'},
  {'7', '8', '9', '*'},
  {'4', '5', '6', '-'},
  {'1', '2', '3', '+'},
  {'0', ',', '0', '='}
};
*/

const uint8_t KEYS[NUM_ROWS][NUM_COLS] = {
  {'#', '#', '%', 0x2F},
  {'7', '8', '9', 0x2A},
  {'4', '5', '6', 0x2D},
  {'1', '2', '3', 0x2B},
  {'0', ',', 0x20, 0x3D}
};

// Bounces before trigger a press or release
const uint8_t MAX_DEBOUNCE = 5;

// One debounce counter per switch
static int8_t debounce_count[NUM_COLS][NUM_ROWS];


/*
 * 
 */
static void scan_row() {
  static uint8_t currentRow = 0;

  digitalWrite(ROW_PINS[currentRow], LOW);

  // Scan through switches on this row:
  for (uint8_t j = 0; j < NUM_COLS; j++) {
    
    // Read the button. pressed = LOW.
    if (digitalRead(COL_PINS[j]) == LOW) {
      
      //Serial.print(KEYS[currentRow][j]);
      
      // Increment a debounce counter
      if (debounce_count[currentRow][j] < MAX_DEBOUNCE) {
        debounce_count[currentRow][j]++;
        // If debounce counter hits MAX_DEBOUNCE
        if ( debounce_count[currentRow][j] == MAX_DEBOUNCE ) {
          // Trigger key press
          if (DEBUG) {
            Serial.print("Key pressed ");
            Serial.println(KEYS[currentRow][j], HEX);
          } else {
            //Keyboard.print(KEYS[currentRow][j]);
            Keyboard.write(KEYS[currentRow][j]);
          }
 
        }
      }
      
    } else {

    // Otherwise, button is released
      if (debounce_count[currentRow][j] > 0) {
        debounce_count[currentRow][j]--;
        if (debounce_count[currentRow][j] == 0) {
          // If debounce counter hits 0
          // Trigger key release
          if (DEBUG) {
            Serial.print("Key released ");
            Serial.println(KEYS[currentRow][j], HEX);
          } else {
            // Keyboard  
          }
        }
      }
    }
  }

  // Once done scanning, de-select the switch by writing them HIGH.
  digitalWrite(ROW_PINS[currentRow], HIGH);
  for (uint8_t i = 0; i < NUM_ROWS; i++) {
   //pinMode(ROW_PINS[i], OUTPUT);

    // with nothing selected by default
    digitalWrite(ROW_PINS[i], HIGH);
  }


  // Increment currentRow, so next time we scan the next row
  currentRow++;
  if (currentRow >= NUM_ROWS) {
    currentRow = 0;
  }
}


static void setup_switch_pins() {
  // ROWS - written LOW when active, HIGH otherwise
  for (uint8_t i = 0; i < NUM_ROWS; i++) {
    pinMode(ROW_PINS[i], OUTPUT);

    // with nothing selected by default
    digitalWrite(ROW_PINS[i], HIGH);
  }

  // Buttn select columns. Pulled high through resistor. Will be LOW when active
  for (uint8_t i = 0; i < NUM_COLS; i++) {
    pinMode(COL_PINS[i], INPUT_PULLUP);
  }
}


/************************************************
  Core 0
*************************************************/
void setup() {
  if (DEBUG) {
    Serial.begin(115200);
  } else {
    Keyboard.begin();
  }

  setup_switch_pins();

  // Initialize the debounce counter array
  for (uint8_t i = 0; i < NUM_COLS; i++) {
    for (uint8_t j = 0; j < NUM_ROWS; j++) {
      debounce_count[i][j] = 0;
    }
  }
}

void loop() {
  scan_row();
}
