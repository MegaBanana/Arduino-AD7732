
#ifndef AD7732_H
#define AD7732_H


/******************************************************************************/
/* AD7732                                                                   */
/******************************************************************************/

/*AD7732 Registers*/
#define AD7732_REG_COMM		0x00	/* Communications Register	(W,  8-bit) */
#define AD7732_REG_IO	    0x01 	/* I/P Port register	  	(RW, 8-bit  */
#define AD7732_REG_REV	    0x02	/* Revision Register 		(R,  8-bit) */
#define AD7732_REG_TEST	    0x03 	/* Test Register	     	(RW, 24-bit)*/
#define AD7732_REG_STATUS	0x04 	/* ADC Status Register	 	(R,	 8-bit) */
#define AD7732_REG_CKS	    0x05 	/* Checksum Register	   	(RW, 16-bit)*/
#define AD7732_REG_ZSCAL   	0x06 	/* ADC Zero-Scale Calibration Register	(RW, 24-bit)*/
#define AD7732_REG_FS		0x07 	/* Full-Scale Register		(RW, 24-bit */
#define AD7732_REG_CH1_DATA 0x08	/* CH1 data Register		(R,  24-bit)*/
#define AD7732_REG_CH2_DATA 0x09	/* CH2 data Register		(R,  24-bit)*/
#define AD7732_REG_CH3_DATA 0x0A	/* CH3 data Register		(R,  24-bit)*/
#define AD7732_REG_CH4_DATA 0x0B	/* CH4 data Register		(R,  24-bit)*/
#define AD7732_REG_CH1_ZSCAL 0x10	/* CH1 Zero-Scale Calibration Register (R/W, 24-bit)*/
#define AD7732_REG_CH2_ZSCAL 0x11	/* CH2 Zero-Scale Calibration Register (R/W, 24-bit)*/
#define AD7732_REG_CH3_ZSCAL 0x12	/* CH3 Zero-Scale Calibration Register (R/W, 24-bit)*/
#define AD7732_REG_CH4_ZSCAL 0x13	/* CH4 Zero-Scale Calibration Register (R/W, 24-bit)*/
#define AD7732_REG_CH1_FSCAL 0x18	/* CH1 Full-Scale Calibration Register (R/W, 24-bit)*/
#define AD7732_REG_CH2_FSCAL 0x19	/* CH2 Full-Scale Calibration Register (R/W, 24-bit)*/
#define AD7732_REG_CH3_FSCAL 0x1A	/* CH3 Full-Scale Calibration Register (R/W, 24-bit)*/
#define AD7732_REG_CH4_FSCAL 0x1B	/* CH4 Full-Scale Calibration Register (R/W, 24-bit)*/
#define AD7732_REG_CH1_STAT	 0x20	/* CH1 Channel Status		(R,	 8-bit)*/
#define AD7732_REG_CH2_STAT	 0x21	/* CH2 Channel Status		(R,	 8-bit)*/
#define AD7732_REG_CH3_STAT	 0x22	/* CH3 Channel Status		(R,	 8-bit)*/
#define AD7732_REG_CH4_STAT	 0x23	/* CH4 Channel Status		(R,	 8-bit)*/
#define AD7732_REG_CH1_SETUP 0x28	/* CH1 Channel Setup		(RW,	 8-bit)*/
#define AD7732_REG_CH2_SETUP 0x29	/* CH2 Channel Setup		(RW,	 8-bit)*/
#define AD7732_REG_CH3_SETUP 0x2A	/* CH3 Channel Setup		(RW,	 8-bit)*/
#define AD7732_REG_CH4_SETUP 0x2B	/* CH4 Channel Setup		(RW,	 8-bit)*/
#define AD7732_REG_CH1_CONVTIME 0x30	/* CH1 Channel Conversion Time		(RW,	 8-bit)*/
#define AD7732_REG_CH2_CONVTIME 0x31	/* CH2 Channel Conversion Time		(RW,	 8-bit)*/
#define AD7732_REG_CH3_CONVTIME 0x32	/* CH3 Channel Conversion Time		(RW,	 8-bit)*/
#define AD7732_REG_CH4_CONVTIME 0x33	/* CH4 Channel Conversion Time		(RW,	 8-bit)*/
#define AD7732_REG_MODE_READ 0x38	/* Mode Register Read		(RW,	 8-bit)*/
#define AD7732_REG_CH1_MODE 0x38	/* CH1 Mode Register Write		(RW,	 8-bit)*/
#define AD7732_REG_CH2_MODE 0x39	/* CH2 Mode Register Write		(RW,	 8-bit)*/
#define AD7732_REG_CH3_MODE 0x3A	/* CH3 Mode Register Write		(RW,	 8-bit)*/
#define AD7732_REG_CH4_MODE 0x3B	/* CH4 Mode Register Write		(RW,	 8-bit)*/


/* Communications Register Bit Designations (AD7732_REG_COMM) */
#define AD7732_COMM_WRITE	(0 << 6) 			/* Write Operation */
#define AD7732_COMM_READ    (1 << 6) 			/* Read Operation */
#define AD7732_COMM_ADDR(x)	(((x) & 0x3F))	/* Register Address */

/* I/O Port Register Bit Designations (AD7732_REG_IO) */
#define AD7732_IO_P0		(1 << 7) /* P0 */
#define AD7732_IO_P1		(1 << 6) /* P1 */
#define AD7732_IO_P0_DIR	(1 << 5) /* P0_DIR */
#define AD7732_IO_P1_DIR	(1 << 4) /* P1_DIR */
#define AD7732_IO_RDYFN		(1 << 3) /* Control RDY function */
#define AD7732_IO_SYNC		(1 << 0) /* Enable SYNC function */

/* ADC Status Register Bit Designations (AD7732_REG_STATUS) */
#define AD7732_STATUS_RDY3	(1 << 3) /* Channel Status */
#define AD7732_STATUS_RDY2	(1 << 2) /* Channel Status */	
#define AD7732_STATUS_RDY1	(1 << 1) /* Channel Status */
#define AD7732_STATUS_RDY0	(1 << 0) /* Channel Status */

/* Channel Status Registers Bit Designations (AD7732_REG_CH1-4_STAT) */
#define AD7732_CHSTAT_CH(x)	(((x) & 0x3) << 5) /* Channel Number */	 
#define AD7732_CHSTAT_P0	(1 << 4) 
#define AD7732_CHSTAT_P1	(1 << 3)
#define AD7732_CHSTAT_NOREF	(1 << 2) /* Reference Input Status */
#define AD7732_CHSTAT_SIGN	(1 << 1) /* Polarity at the analog input */
#define AD7732_CHSTAT_OVR	(1 << 0) /* Overrange or underrange */

/* Channel Setup Registers Bit Designation (AD7732_REG_CH1-4_SETUP) */
#define AD7732_CHSETUP_STATOPT	(1 << 4) /* Status Option */
#define AD7732_CHSETUP_ENABLE	(1 << 3) /* Channel Enable */
#define AD7732_CHSETUP_RNG(x)	(((x) & 0x3) << 0) /* Channel Input Voltasge Range */

/* Channel Conversion Time Registers Bit Descriptions (AD7732_REG_CH1-4_CONVTIME) */
#define AD7732_CHCONVTIME_CHOP	(1 << 7)
#define AD7732_CHCONVTIME_FW(x)	(((x) & 0x7F) << 0)

/* Mode Registers Bit Descriptions (AD7732_REG_CH1_MODE)*/
#define AD7732_MODE_MD(x)	(((x) & 0x7) << 5)	
#define AD7732_MODE_CLKDIS	(1 << 4)
#define AD7732_MODE_DUMP	(1 << 3)
#define AD7732_MODE_CONT	(1 << 2)
#define AD7732_MODE_24BIT	(1 << 1)
#define AD7732_MODE_CLAMP	(1 << 0)


#if (ARDUINO >= 100)
 #include "Arduino.h"
#else
 #include "WProgram.h"
#endif


class AD7732 {
 public:
  AD7732(int8_t spi_cs, int8_t spi_mosi, int8_t spi_miso, int8_t spi_clk);
  AD7732(int8_t spi_cs);


  void configuration();
  float readAnalog();
  uint8_t readReg(uint8_t addr);

  boolean begin();
  unsigned char Ready(char ch);
  unsigned long GetRegisterValue(unsigned char regAddress, unsigned char size);
  void Reset(void);


 private:

  int8_t _sclk, _miso, _mosi, _cs;

};
#endif