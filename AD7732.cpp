

#include "AD7732.h"


#include <stdlib.h>
#include <SPI.h>
static SPISettings AD7732_spisettings = SPISettings(4000000, MSBFIRST, SPI_MODE3);


// Software (bitbang) SPI
AD7732::AD7732(int8_t spi_cs, int8_t spi_mosi, int8_t spi_miso, int8_t spi_clk) {
  _sclk = spi_clk;
  _cs = spi_cs;
  _miso = spi_miso;
  _mosi = spi_mosi;

}

// Hardware SPI init
AD7732::AD7732(int8_t spi_cs) {
  _cs = spi_cs;
  _sclk = _miso = _mosi = -1;
}

boolean AD7732::begin() {
  pinMode(_cs, OUTPUT);
  digitalWrite(_cs, HIGH);

  if (_sclk != -1) {
    //define pin modes
    pinMode(_sclk, OUTPUT); 
    digitalWrite(_sclk, LOW);
    pinMode(_mosi, OUTPUT); 
    pinMode(_miso, INPUT);
  } else {
    //start and configure hardware SPI
    SPI.begin();
  }  
  //SPI.beginTransaction(max31865_spisettings);
  return true;
}

float AD7732::readAnalog()
{
   
   //while((readReg(AD7732_REG_CH1_STAT) & 0x01) == AD7732_STATUS_RDY0);
   

   
    // Prepare output
   SPI.beginTransaction(AD7732_spisettings);
   
   // Enable communication with AD7732
   digitalWrite(_cs, LOW);
   // Send the adress
   SPI.transfer(AD7732_REG_COMM);
   // Send the communication register setting
   SPI.transfer( AD7732_COMM_READ | AD7732_REG_CH1_DATA);

   uint8_t status = SPI.transfer(0);
   uint8_t array[4] = {0};
   // Read data
   for(int i = 0 ; i < 3 ; i++)
   {
      array[2-i] = SPI.transfer(0);
   }

   // End of SPI Communication
   digitalWrite(_cs, HIGH);

   uint32_t uData = *(uint32_t*)array;
   float voltage = 0.0;
   //char tabs[20];
   //sprintf(tabs, "status %02X uData %08lX", status, uData);
   //Serial3.println(tabs);

   if (status & 0x02)
   {
       if (uData & 0x00800000)
       {
           voltage = -((0x01000000 - uData) * 20.0 / 16777215.0) - 10.0;
       }
       else
       {
           voltage = uData * 20.0 / 16777215.0 - 10.0; // KO problem de converison =>float
       }
   }
   else
   {
       if (uData & 0x00800000)
       {
           voltage = uData * 20.0 / 16777215.0 - 10.0; // OK
       }
       else // OK
       {
           voltage = (uData + 0x01000000) * 20.0 / 16777215.0 - 10.0; 
       }
   }
   
   
  // char tabs[48];
  // sprintf(tabs,"Status %x  array [%hhX:%hhX:%hhX:%hhX] udata %lx", status,array[3],array[2],array[1],array[0],uData);
  // Serial3.println(tabs);

    return voltage;
}




uint8_t AD7732::readReg(uint8_t addr)
{
   // Prepare output
   SPI.beginTransaction(AD7732_spisettings);

   // Enable communication with AD7732
   digitalWrite(_cs, LOW);
   
   // Send the adress
   SPI.transfer(AD7732_REG_COMM);
   
   // Send the communication register setting
   SPI.transfer( AD7732_COMM_READ | addr);
   
   // Read reg
   uint8_t reg = SPI.transfer(0x00);
   
   
   digitalWrite(_cs, HIGH);
   
   return reg;
}


unsigned char AD7732::Ready(char ch)
{
   unsigned char rdy = 0;
	ch--;
   rdy = (readReg( AD7732_REG_STATUS) & (1 << ch));   
	
	return(rdy);
}

void AD7732::configuration()
{
  
   Reset();
   // Prepare output
   SPI.beginTransaction(AD7732_spisettings);
   // Enable communication with AD7732
   digitalWrite(_cs, LOW);
   
   
   ////////////////////// SETUP ///////////////////////////
   // Send the adress
   SPI.transfer(AD7732_REG_COMM);
   // Send the communication register setting
   SPI.transfer(AD7732_REG_CH1_SETUP); // Write to MODE register  
   // Enable channel
   SPI.transfer(AD7732_CHSETUP_ENABLE);  
   
   
   ////////////////////// CONVERSION TIME ///////////////////////////
   // Send the adress
   SPI.transfer(AD7732_REG_COMM);
   // Send the communication register setting
   SPI.transfer(AD7732_REG_CH1_CONVTIME); // Write to MODE register
   // Send the data
   SPI.transfer(0x7F); 
   
   
   ////////////////////// MODE ///////////////////////////
   // Send the adress
   SPI.transfer(AD7732_REG_COMM);
   
   // Send the communication register setting
   SPI.transfer(AD7732_REG_CH1_MODE); // ask for write to MODE Register
   // Send the communication register setting
   SPI.transfer(AD7732_MODE_MD(1) | AD7732_MODE_CONT | AD7732_MODE_24BIT);// | AD7732_MODE_CLAMP); // Write to MODE register
     
   digitalWrite(_cs, HIGH);                          
   // Disable com
   SPI.endTransaction();
}



/***************************************************************************//**
 * @brief Sends 32 consecutive 1's on SPI in order to reset the part.
 *
 * @param None.
 *
 * @return  None.    
*******************************************************************************/
void AD7732::Reset(void)
{
	unsigned char dataToSend[5] = {0x03, 0xff, 0xff, 0xff, 0xff};
   digitalWrite(_cs, LOW);
   for(int i = 0 ; i < 5 ; i++)
   {
      SPI.transfer(dataToSend[i]);
   }
   digitalWrite(_cs, HIGH);
}
/**********************************************/


