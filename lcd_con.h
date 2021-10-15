/***********************************************************************
Private variables and functions
関数プロトタイプ宣言
***********************************************************************/
#include <stdint.h>
//
int dispset_titl(void);
void lcd_init(void);
void lcd_l1(unsigned char col1);
void lcd_l2(unsigned char col2);
int lcd_cout(unsigned char ccod);
int lcd_dout(unsigned char dcod);
void delay_micro(unsigned int icnt);
void delay_msec(unsigned int icnt);
int write_string(uint_fast8_t row, uint_fast8_t col, unsigned const char  *str);
void dispset_count(void);
void show(unsigned char *s);

void op_switich_upf(void);
//**** 変数
extern unsigned char dpcnt[4];

int set_cursor_position (uint_fast8_t row, uint_fast8_t col);   


//void write_string(uint_fast8_t line,uint_fast8_t col, unsigned char * str);

void increment(void);