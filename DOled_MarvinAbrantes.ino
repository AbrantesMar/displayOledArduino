#include <U8glib.h>

// Placas testadas Arduino: Uno, Mega 2560, Nano
// Display Oled
// 4 fios macho macho

//Pinos nos Arduino Nano e Uno Display = Arduino - GND = GND | VDD = 5v | SDK = A5 | SDA = A4
//Pinos nos Arduino Mega Display = Arduino - GND = GND | VDD = 5v | SDK = A5 | SDA = A4


U8GLIB_SSD1306_128X64 u8g(U8G_I2C_OPT_NO_ACK);  // Display which does not send AC
int h = 1, m = 1, c = 1;

void draw() 
{
  //Hora
  u8g.setFont(u8g_font_8x13B);


  u8g.drawStr( 0, 10,"   /''\\/''\\ ");
  u8g.drawStr( 0, 20,"   |_|\\/|_| ");
  u8g.drawStr( 0, 40,"    Marvin ");
  u8g.drawStr( 0, 50,"   Abrantes");
  
}
 
void setup(void) 
{
  Serial.begin(9600);
  if ( u8g.getMode() == U8G_MODE_R3G3B2 ) {
    u8g.setColorIndex(255);     // white
  }
  else if ( u8g.getMode() == U8G_MODE_GRAY2BIT ) {
    u8g.setColorIndex(3);         // max intensity
  }
  else if ( u8g.getMode() == U8G_MODE_BW ) {
    u8g.setColorIndex(1);         // pixel on
  }
  else if ( u8g.getMode() == U8G_MODE_HICOLOR ) {
    u8g.setHiColorByRGB(255,255,255);
  }
}

void loop(void) 
{
  u8g.firstPage();  
  do 
  {
    
    draw();
  } while( u8g.nextPage() );
  
  delay(50);
}
