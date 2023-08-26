/*
 * lcd.h
 *
 *  Created on: Aug 18, 2023
 *      Author: Mahmoud A. Monaim
 */

#ifndef LCD_H_
#define LCD_H_

// LCD instructions
#define lcd_Clear           0x1          // replace all characters with ASCII 'space'
#define lcd_cursor2_Home    0x2          // return cursor to first position on first line
#define lcd_Inc_cursor      0x6          // shift cursor from left to right on read/write
#define lcd_DisplayOff      0b00001000          // turn display off
#define lcd_DisplayOn       0x0e          // display on, cursor off, don't blink character
#define lcd_FunctionReset   0x28          // reset the LCD
#define lcd_FunctionSet8bit 0x38          // 8-bit data, 2-line display, 5 x 7 font
#define lcd_SetCursor       0x80          // set cursor position
//#define lcd_wakeup          0x30



void delay(Uint8_t t);
void lcd_init();
void send_bytes(Uint8_t b);
void send_command (Uint8_t c);
void send_char (Uint8_t d);
void send_digit(uint16_t);


#endif /* LCD_H_ */
