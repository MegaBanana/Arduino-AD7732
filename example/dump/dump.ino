#include <AD7732.h>

const int PT100_SPI_MISO        = 50;
const int PT100_SPI_MOSI        = 51;
const int PT100_SPI_CLK         = 52;
const int PT100_TCD_SPI_CS      = 44;               // TCD

AD7732 ad7732(PT100_TCD_SPI_CS);

void setup() {
  // put your setup code here, to run once:

  Serial.begin(115200);

  
  ad7732.begin();
  ad7732.configuration();

}

void loop() {

   char tabs[10] ={0};
   // Clear hyperterminal
   Serial.write(0x0c);
   for(int i = 0; i < 10 ; i++)
   {
      tabs[10] ={0};
      sprintf(tabs,"[%d] = 0x%02x",i,ad7732.readReg(i) & 0xff);
      Serial.println(tabs);
   } 
}