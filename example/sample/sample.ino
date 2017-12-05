#include <AD7732.h>

const int PT100_SPI_MISO        = 50;
const int PT100_SPI_MOSI        = 51;
const int PT100_SPI_CLK         = 52;
const int PT100_TCD_SPI_CS      = 44;               // TCD

AD7732 ad7732(PT100_TCD_SPI_CS);

void setup() {
  // put your setup code here, to run once:

  ad7732.begin();
  ad7732.configuration();
  Serial.begin(115200);

}

void loop() {
   float test = ad7732.readAnalog();

   Serial.println( test);
   
   delay(1000);
}