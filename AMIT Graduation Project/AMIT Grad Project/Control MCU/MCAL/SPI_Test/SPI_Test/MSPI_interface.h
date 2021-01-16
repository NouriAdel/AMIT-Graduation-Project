/**************************************************************************/
/* Name:    MSPI_interface.h                                              */
/* Author:  Ahmed Ashraf                                                  */
/* Version: v1.0                                                          */
/* Description: This file contains interfacing information for SPI module */
/**************************************************************************/

/*Header file guard*/
#ifndef MSPI_INTERFACE_H_
#define MSPI_INTERFACE_H_

/************************************************************************/
/*                            Interfacing macros                        */
/************************************************************************/

/*SPI Data mode*/
#define MSPI_SAMPLE_R_SETUP_F  (0)
#define MSPI_SETUP_R_SAMPLE_F  (1) 
#define MSPI_SAMPLE_F_SETUP_R  (2) 
#define MSPI_SETUP_F_SAMPLE_R  (3) 
 
/*SPI Clock prescaler*/
#define MSPI_PRE_2             (0)
#define MSPI_PRE_4             (1)
#define MSPI_PRE_8             (2)
#define MSPI_PRE_16            (3)
#define MSPI_PRE_32            (4)
#define MSPI_PRE_64            (5)
#define MSPI_PRE_128           (7)

/************************************************************************/
/*                          Functions' prototypes                       */
/************************************************************************/

/*This function is responsible for initializing SPI peripheral for Master MCU*/
void mspi_init(u8_t data_mode, u8_t clk_prescaler);

/*This function is responsible for initializing SPI peripheral for Slave MCU*/
void mspi_init_slave(u8_t data_mode, u8_t clk_prescaler);

/*This function is responsible for sending and getting data over or from SPI bus*/
u8_t mspi_sendRecvByte(u8_t data);

/*This function is responsible for sending a stream of data over SPI peripheral*/
void mspi_sendStream(u8_t* data, u8_t data_size);

/*This function is responsible for receiving data as a Slave*/
u8_t mspi_RecvByte_slave(void);

#endif /* MSPI_INTERFACE_H_ */