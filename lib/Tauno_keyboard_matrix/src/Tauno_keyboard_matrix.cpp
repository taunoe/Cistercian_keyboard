/*
 * File         Tauno_keyboard_matrix.cpp
 * Last edited  03.05.2021
 * 
 * Copyright 2021 Tauno Erik
 * https://taunoerik.art/
 */

#include <Arduino.h>
#include "Tauno_keyboard_matrix.h"

Tauno_Keyboard_Matrix::Tauno_Keyboard_Matrix(
  uint8_t *ROW_PINS,
  uint8_t *COL_PINS,
  uint8_t NUM_ROWS,
  uint8_t NUM_COLS)
  : _ROW_PINS(ROW_PINS),
    _COL_PINS(COL_PINS),
    _NUM_ROWS(NUM_ROWS),
    _NUM_COLS(NUM_COLS) {
      _MAX_DEBOUNCE = 5;
      _current_row = 0;
  }

Tauno_Keyboard_Matrix::~Tauno_Keyboard_Matrix() {
  // Cleanup
  // set each column to back to input
  Serial.print("--Destructor!");
  for (uint8_t col = 0; col < _NUM_COLS; col++) {
    pinMode(_COL_PINS[col], INPUT_PULLUP);
  }
}

void Tauno_Keyboard_Matrix::begin() {
  init_debounce_count();
  // Rows are ouputs and HIGH, low when button pressed
  Serial.print("_NUM_ROWS = ");
  Serial.println(_NUM_ROWS);
  for (uint8_t row = 0; row < _NUM_ROWS; row++) {
    Serial.print("_ROW_PINS[row] = ");
    Serial.println(_ROW_PINS[row]);
    pinMode(_ROW_PINS[row], OUTPUT);
    digitalWrite(_ROW_PINS[row], HIGH);
  }
  // Columns pulled high
  Serial.print("_NUM_COLS = ");
  Serial.println(_NUM_COLS);
  for (uint8_t col = 0; col < _NUM_COLS; col++) {
    Serial.print("_COL_PINS[col] = ");
    Serial.println(_COL_PINS[col]);
    pinMode(_COL_PINS[col], INPUT_PULLUP);
  }
  //
  print_debounce_count();
}

void Tauno_Keyboard_Matrix::scan() {
  scan_row();
}

void Tauno_Keyboard_Matrix::scan_row() {
  // Write current row LOW
  pinMode(_ROW_PINS[_current_row], OUTPUT);
  digitalWrite(_ROW_PINS[_current_row], LOW);
  // Serial.print("digitalWrite LOW ");
  // Serial.println(_current_row);

  // Scan throught columns (switches) on this row
  for (uint8_t col = 0; col < _NUM_COLS; col++) {
     // Read the button
     // uint8_t button = digitalRead(_COL_PINS[col]);
     // Serial.print("r = ");
     // Serial.print(_current_row);
     // Serial.print(" c = ");
     // Serial.println(col);
     // delay(100);
     // Serial.println(button);

    // If button is pressed it is LOW
    if (digitalRead(_COL_PINS[col]) == LOW) {
      /*
      Serial.print("r = ");
      Serial.print(_current_row);
      Serial.print(" c = ");
      Serial.print(col);
      Serial.println(" b = LOW");
      */
     // print_debounce_count();
      // Increment a debounce counter
      if (_debounce_count[_current_row][col] < _MAX_DEBOUNCE) {
        _debounce_count[_current_row][col]++;
        // If debounce counter hits MAX_DEBOUNCE
        if (_debounce_count[_current_row][col] == _MAX_DEBOUNCE) {
          // Trigger key press
          print_debounce_count();
          Serial.print("Key pressed: ");
          Serial.print((_current_row * _NUM_COLS) + col);
          Serial.print(" row:");
          Serial.print(_current_row);
          Serial.print(" col:");
          Serial.print(col);
          Serial.print(" _debounce_count[_current_row][col] = ");
          Serial.println(_debounce_count[_current_row][col]);
        }
      }
    } else {
    // Button is released
      if (_debounce_count[_current_row][col] > 0) {
        _debounce_count[_current_row][col]--;
        if (_debounce_count[_current_row][col] == 0) {
          // If debounce counter hits 0
          // Trigger key release
          Serial.print("Key released: ");
          Serial.println((_current_row * _NUM_COLS) + col);
          Serial.print("_debounce_count[_current_row][col] = ");
          Serial.println(_debounce_count[_current_row][col]);
        }
      }
    }
  }

  // Write current row back to HIGH
  digitalWrite(_ROW_PINS[_current_row], HIGH);
  pinMode(_ROW_PINS[_current_row], INPUT);
  // Serial.print("digitalWrite HIGH ");
  // Serial.println(_current_row);

  // Increment currentRow, so next time we scan the next row
  _current_row++;
  if (_current_row >= _NUM_ROWS) {
    // Serial.print("_current_row >= _NUM_ROWS");
    _current_row = 0;
    // Serial.println(_current_row);
  }
}


void Tauno_Keyboard_Matrix::init_debounce_count() {
  for (uint8_t r = 0; r < _NUM_ROWS; ++r) {
    // loop through columns of current row
    for ( int c = 0; c < _NUM_COLS; ++c ) {
      _debounce_count[r][c] = 0;
    }
  }
}


void Tauno_Keyboard_Matrix::print_debounce_count() {
  // loop through array's rows
  for (uint8_t r = 0; r < _NUM_ROWS; ++r) {
    // loop through columns of current row
    for ( int c = 0; c < _NUM_COLS; ++c ) {
      Serial.print(_debounce_count[r][c]);
      Serial.print("-");
    }
    Serial.print("\n");
  }
  Serial.print("\n");
}