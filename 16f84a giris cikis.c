#include <16F84a.h>         
#fuses hs, NOWDT, NOPUT
#use delay(clock=8m)
                           
/////////////////////////////////////
#define START PIN_B3
#define ledstop PIN_B4
#define SUAL PIN_A0
#define BOSALT PIN_A1
#define SAAT PIN_A2
#define ANTISAAT PIN_A3
#define HIZLI PIN_B1
#define SUAL2 PIN_B0
#define led pin_b5
////////////////////////////////////
int y=0;
int8 i=0, MENU_SAY=0, sn=0, dkk=0, m_sn=0, prg=0;


///////////////////////////////////////////////////////////////////////////////
#int_timer0  // Timer0 kesmesi
void  timer0_kesme ()   // Kesme fonksiyonu ismi
{
    set_timer0(10);   // "TMR0 deðeri belirlendi" degeri arttirirsan hizlanir azaltirsan azalir
    i++;             // i deðeri 1 arttýrýlýyor   
    if (i==16)      // i deðeri 16'ye eþitse 
       {sn++;      // her sn VE m_sn 1 arttirilsin
       m_sn++;
        i=0;}
       else if (sn>59)
       {dkk++;
       sn=0;}
       else if (dkk>57)
       {prg=0; output_high(ledstop); 
               output_low(SUAL);
               output_low(SUAL2);
               output_low(BOSALT);
               output_low(SAAT);
               output_low(ANTISAAT);
               output_low(HIZLI);}

}
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////

void main(void) 
{
   setup_timer_0(RTCC_INTERNAL | RTCC_DIV_256); // Timer0 ayarlarý yapýlýyor
   set_timer0(60);   // TMR0 deðeri belirleniyor
   enable_interrupts(INT_timer0); // int_timer0 kesmesini aktif yapar
   enable_interrupts(GLOBAL);     // Aktif edilen kesmelere izin ver
output_a(0);
output_b(0);
///////////////////////////////////////////////////////////////////////////////
while(TRUE) 
{  
if(prg==0)
{output_high(ledstop);}
if(input(start))
   {
   PRG=1;
   output_low(ledstop);
   sn=0;
   dkk=0;
   }
   
   if((prg>0))
   {
   switch(menu_say)
      {
      case 0:
      output_low(ledstop);
      output_high(led);
      output_high(SUAL);
      output_high(BOSALT);
      output_low(SAAT);
      output_low(ANTISAAT);
      output_low(HIZLI);
      break;
      
      case 1:  //SN 20 OLDUGUNDA CASE 1 E GECTI
      output_low(ledstop);
      output_low(SUAL);
      output_high(BOSALT);
      output_low(HIZLI);
      output_high(led);
      delay_ms(2000); // 1 sn bekle ve  yikamaya gec 
      for(y=0; y<1; ++y)
      {
      output_high(SAAT);                       //SAAT yonunde donmeye basla
      delay_ms(20000);                         // 7 sn dondur
      output_low(SAAT);                       // SAAT yonunde donmeyi durdur
      delay_ms(4000);                        //  1 saniye bekle
      output_high(ANTISAAT);                 // ANTISAAT yonunde donmeye basla
      delay_ms(20000);                       //  7 sn antisaat yonunde dondur
      output_low(ANTISAAT);                 // ANTISAAT yonunde donmeyi durdur
      delay_ms(2000);                       // 1 saniye bekle basa don 
      }
      break;
      
      case 2:                            // deterjanli su tahliyesi
      output_high(led);
      output_low(ledstop);
      output_low(SUAL);
      OUTPUT_low(SUAL2);
      output_low(SAAT);
      output_low(ANTISAAT);
      output_low(HIZLI);
      output_low(BOSALT);             //tahliye
      delay_ms(3000);
      for(y=0; y<1; ++y)
      {
      output_high(SAAT);                      
      delay_ms(15000);                          
      output_low(SAAT); 
      delay_ms(3000);                       
      output_high(ANTISAAT);                 
      delay_ms(15000);                       
      output_low(ANTISAAT);                 
      delay_ms(2000);                      
      }
      break;
      
      CASE 3:
      output_high(BOSALT);             //temiz su al
      output_low(SAAT);
      output_low(ANTISAAT);
      output_high(led);
      output_low(ledstop);
      output_low(HIZLI);
      OUTPUT_HIGH(SUAL2);   
      break;
      
      case 4:
      output_low(SUAL);
      output_low(ledstop);
      output_high(BOSALT);         
      output_low(HIZLI);
      output_high(led);
      OUTPUT_low(SUAL2); 
      delay_ms(2000);
      for(y=0; y<1; ++y)
      {
      output_high(SAAT);                       //SAAT yonunde donmeye basla
      delay_ms(20000);                         // 7 sn dondur
      output_low(SAAT);                       // SAAT yonunde donmeyi durdur
      delay_ms(4000);                        //  1 saniye bekle
      output_high(ANTISAAT);                 // ANTISAAT yonunde donmeye basla
      delay_ms(20000);                       //  7 sn antisaat yonunde dondur
      output_low(ANTISAAT);                 // ANTISAAT yonunde donmeyi durdur
      delay_ms(3000);                       // 1 saniye bekle basa don 
      }
      break;
      
      case 5:                           //temiz su tahliyesi
      output_high(led);
      output_low(ledstop);
      output_low(BOSALT);  
      output_low(SUAL);
      OUTPUT_low(SUAL2);
      output_low(SAAT);
      output_low(ANTISAAT);
      output_low(HIZLI);          delay_ms(2000);
      for(y=0; y<1; ++y)
      {
      output_high(SAAT);                      
      delay_ms(15000);                          
      output_low(SAAT); 
      delay_ms(4000);                       
      output_high(ANTISAAT);                 
      delay_ms(15000);                       
      output_low(ANTISAAT);                 
      delay_ms(4000);                      
      }
      break;
      
      case 6:  // kurutma
      delay_ms(5000);
      output_high(led);
      output_low(ledstop);
      output_low(SAAT);
      output_low(SUAL);
      OUTPUT_low(SUAL2); 
      output_low(ANTISAAT);
      output_low(BOSALT);             //kurutma
      output_high(HIZLI);
      break;
      
      case 7:
      output_low(BOSALT);             //tahliye
      output_low(HIZLI);
      output_low(SAAT);
      output_low(ANTISAAT);
      output_low(led);
      output_low(SUAL);
      OUTPUT_low(SUAL2); 
      output_high(ledstop);
      DELAY_MS(50);
      break;
      }
      /////////////////////////////////////////////////////////////////////////
      if((DKK<10)&&(prg>0))  ////case0'da 1dk su aldiktan sonra case 1 saat yonu ve tersi yikamaya gecti   1dk 29 SN SURDU
      {menu_say=0;}   //CASE 0       1 dk 55 sn
      if((dkk>=10)&&(dkk<25)&&(prg>0))  // 3 den kucuk ve 1 den buyuk veya 1 e esitse    2 dk >>>>    1dk 15 sn surdu
      {menu_say=1;}  // CASE 1
      if((dkk>=25)&&(dkk<28)&&(prg>0))  // tahliye
      {menu_say=2;}  //CASE 2
      if((dkk>=28)&&(dkk<38)&&(prg>0))    ///temiz su alma
      {menu_say=3;}
      if((dkk>=38)&&(dkk<50)&&(prg>0))   //durulama
      {menu_say=4;}
      if((dkk>=50)&&(dkk<53)&&(prg>0))  // temiz su tahliyesi
      {menu_say=5;}
      if((dkk>=53)&&(dkk<56)&&(prg>0)) //kurutma
      {menu_say=6;}
      if(dkk>=56)
      {menu_say=7;}
   }
}

}

