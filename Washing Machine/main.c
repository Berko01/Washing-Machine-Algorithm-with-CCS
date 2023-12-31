#include <main.h>                     // b portu manuel ayaralanacak
#use fast_io(d)
#define use_portd_lcd TRUE          // LCD B portuna ba�l�
#include <lcd.c>                    // lcd.c dosyas� tan�t�l�yor
void rotateMotor(){


         output_b(0b00000101);
         delay_ms(15000);
         output_b(0b00000110);
         delay_ms(15000);
         output_b(0b00000000);
      
}

void waterIntakeValve(){

      output_high(pin_B3);
      delay_ms(2000);
      output_low(pin_B3);
}

void waterDrainValve(){
      output_high(pin_B4);
      delay_ms(2000);
      output_low(pin_B4);
}

void main()
{
   set_tris_b(0x00);
   output_b(0x00);
   set_tris_a(0xFF);
   set_tris_d(0x00);
   output_d(0x00);
   
   lcd_init();

   while(true)
   {
   if(input(pin_A0) == 1)
   {
      printf(lcd_putc,"\f Yikaniyor.");
      output_high(pin_B3);
      delay_ms(2000);
      output_low(pin_B3);
      
      for(int i=0;i<1;i++)
      rotateMotor();
      
      printf(lcd_putc,"\f Yikama bitti.");
      delay_ms(2000);
      printf(lcd_putc,"\fDurulaniyor.");
      waterDrainValve();
      waterIntakeValve();
      rotateMotor();
      waterDrainValve();
      printf(lcd_putc,"\fDurulama bitti.");
      delay_ms(2000);
      printf(lcd_putc,"\fSikiliyor.");
      output_b(0b00000101);
      delay_ms(15000);
      output_b(0b00000000);
      printf(lcd_putc,"\fSikma bitti.");
      
      while(true)
      {
         printf(lcd_putc,"\fYikama tamamlandi.");
         output_high(pin_B5);
         delay_ms(1000);
         output_low(pin_B5);
      }

   }

      
   }

}
