#include <Arduino.h>
#include "Tauno_keyboard_matrix.h"

// Keypad settings
const uint8_t NUM_COLS = 4;
const uint8_t NUM_ROWS = 5;

// Xiao
//uint8_t ROW_PINS[NUM_COLS] = {10, 9, 2, 3};
//uint8_t COL_PINS[NUM_ROWS] = {4, 5, 6, 7, 8};

// Pico
uint8_t ROW_PINS[NUM_COLS] = {3, 4, 28, 29};
uint8_t COL_PINS[NUM_ROWS] = {6, 7, 0, 1, 2};

const char KEYS[NUM_ROWS][NUM_COLS] = {
  {'#', '#', '%', '/'},
  {'7', '8', '9', '*'},
  {'4', '5', '6', '-'},
  {'1', '2', '3', '+'},
  {'0', ',', '#', '='},
};

// The number of button bounces before trigger a press or release
const uint8_t MAX_DEBOUNCE = 5;

// One debounce counter per switch
static int8_t debounce_count[NUM_COLS][NUM_ROWS];

Tauno_Keyboard_Matrix Klahvid(ROW_PINS, COL_PINS, NUM_ROWS, NUM_COLS);

/*****************************************/

static void scan_row() {
  static uint8_t currentRow = 0;

  // Write current row LOW
  digitalWrite(ROW_PINS[currentRow], LOW);

  // Scan through switches on this row:
  for (uint8_t j = 0; j < NUM_COLS; j++) {
    // Read the button. pressed = LOW.
    if (digitalRead(COL_PINS[j]) == LOW) {
      // Increment a debounce counter
      if (debounce_count[currentRow][j] < MAX_DEBOUNCE) {
        debounce_count[currentRow][j]++;
        // If debounce counter hits MAX_DEBOUNCE
        if ( debounce_count[currentRow][j] == MAX_DEBOUNCE ) {
          // Trigger key press
          Serial.print("Key pressed ");
          Serial.println((currentRow * NUM_COLS) + j);
        }
      }
    } else {
    // Otherwise, button is released
      if (debounce_count[currentRow][j] > 0) {
        debounce_count[currentRow][j]--;
        if (debounce_count[currentRow][j] == 0) {
          // If debounce counter hits 0
          // Trigger key release
          Serial.print("Key released ");
          Serial.println((currentRow * NUM_COLS) + j);
        }
      }
    }
  }

  // Once done scanning, de-select the switch by writing them HIGH.
  digitalWrite(ROW_PINS[currentRow], HIGH);


  // Increment currentRow, so next time we scan the next row
  currentRow++;
  if (currentRow >= NUM_ROWS) {
    currentRow = 0;
  }
}



static void setup_switch_pins() {
  // Button drive rows - written LOW when active, HIGH otherwise
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


void setup() {
  Serial.begin(11520);

  // setup_switch_pins();
  delay(3000);
  Klahvid.begin();

  // Initialize the debounce counter array
  for (uint8_t i = 0; i < NUM_COLS; i++) {
    for (uint8_t j = 0; j < NUM_ROWS; j++) {
      debounce_count[i][j] = 0;
    }
  }
}

void loop() {
  Klahvid.scan();
}