/*
 * File         Tauno_keyboard_matrix.h
 * Last edited  03.05.2021
 * 
 * Copyright 2021 Tauno Erik
 * https://taunoerik.art/
 * 
 * https://stackoverflow.com/questions/28796528/how-do-i-initialize-a-2d-array-of-variable-size-in-a-c-class
 */

#ifndef LIB_TAUNO_KEYBOARD_MATRIX_SRC_TAUNO_KEYBOARD_MATRIX_H_
#define LIB_TAUNO_KEYBOARD_MATRIX_SRC_TAUNO_KEYBOARD_MATRIX_H_

#include <Arduino.h>

class Tauno_Keyboard_Matrix {
 private:
  const char * _KEY_MAP;            // Mapping key (row+col) to character
  uint8_t * _ROW_PINS;              // Array of row pins
  uint8_t * _COL_PINS;              // Array of col pins
  uint8_t _NUM_ROWS;                // Number of rows
  uint8_t _NUM_COLS;                // Number of cols
  uint8_t _MAX_DEBOUNCE;            // Button bounces before trigger
  uint8_t _debounce_count[10][10];  // max_rows max_cols
  uint8_t _current_row;             // Curent scan row

  void scan_row();
  void init_debounce_count();
  void print_debounce_count();

 public:
  Tauno_Keyboard_Matrix(uint8_t *ROW_PINS,
                        uint8_t *COL_PINS,
                        uint8_t NUM_ROWS,
                        uint8_t NUM_COLS);

  ~Tauno_Keyboard_Matrix();
  void begin();
  void scan();
};

#endif  // LIB_TAUNO_KEYBOARD_MATRIX_SRC_TAUNO_KEYBOARD_MATRIX_H_
