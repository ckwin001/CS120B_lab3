/*         Your Name & E-mail:Casey Kwinn, ckwin001@ucr.edu
 *         Lab Section:023
 *         Assignment: Lab #3  Exercise #2
 *         Exercise Description: 
 *        
 *         I acknowledge all content contained herein, excluding template or example code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "../header/simAVRHeader.h"
#endif

int main(void) {
   DDRA = 0x00; PORTA = 0xFF;
   DDRB = 0xFF; PORTC = 0x00;
   unsigned char fuel=0x00;
   //unsigned char danger;
   unsigned char low=0x00;
   while (1){
      if ((PINA&0x0F) <= 0x04) {low = 0x01;}
      else {low = 0x00;}
      if ((PINA&0x0F) >= 0x01 && (PINA&0x0F) <= 0x02) {fuel = 0x20;}
      else if ((PINA&0x0F) >= 0x03 && (PINA&0x0F) <= 0x04) {fuel = 0x30;}
      else if ((PINA&0x0F) >= 0x05 && (PINA&0x0F) <= 0x06) {fuel = 0x38;}
      else if ((PINA&0x0F) >= 0x07 && (PINA&0x0F) <= 0x09) {fuel = 0x3C;}
      else if ((PINA&0x0F) >= 0x0A && (PINA&0x0F) <= 0x0C) {fuel = 0x3E;}
      else if ((PINA&0x0F) >= 0x0D) {fuel = 0x3F;}
      else {fuel = 0x00;}
      //danger = ((PINA & 0x10)>>4) & !((PINA & 0x20)>>5) & ((PINA & 0x40)>>6);
      PORTC = fuel | low<<6; //|danger<<7;
   }
}

