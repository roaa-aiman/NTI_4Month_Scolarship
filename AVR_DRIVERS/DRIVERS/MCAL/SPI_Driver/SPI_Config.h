/*
 * SPI_Config.h
 *
 * Created: 3/8/2024 12:03:39 PM
 *  Author: SMART
 */ 


#ifndef SPI_CONFIG_H_
#define SPI_CONFIG_H_

/*Enable SPI Interrupt Mode*/
/*
 * ENABLED
 * DISABLED
 *
 */

#define SPI_INTERRUPT_MODE 	ENABLE_INTERRUPT

/*SPI Data Order*/
/*
 * LSB_FIRST
 * MSB_FIRST
 *
 */

#define SPI_DATA_ORDER  LSB_FIRST

/*
 * Clock Polarity mode
 * IDLE_LOW >> leading edge is rising
 * IDLE_HIGH >> leading edge is falling
 *
 */
#define SPI_CLOCK_POLARITY  IDLE_HIGH


/* Clock Phase Mode
 *
 * SAMPLE_AT_LEADING >> sample at leading and setup at trailing
 * SETUP_AT_LEADING >> sample at trailing and setup at rising
 *
 */

#define SPI_CLOCK_PHASE   SETUP_AT_LEADING
/* CLOCK
 *
 * MODE_F/4
 * MODE_F/2
 *
 */

#define SPI_FREQUENCY  DIVIDE_BY_64




#endif /* SPI_CONFIG_H_ */