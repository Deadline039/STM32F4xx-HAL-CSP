/**
 * @file    SPI_STM32F4xx.h
 * @author  Deadline039
 * @brief   Chip Support Package of SPI on STM32F4xx
 * @version 1.0
 * @date    2024-10-22
 */

#ifndef __SPI_STM32F4XX_H
#define __SPI_STM32F4XX_H

#include "CSP_Config.h"

#include "stm32f4xx_hal.h"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/**
 * @brief SPI Clock Mode select.
 */
typedef enum {
    SPI_CLK_MODE0, /*!< Mode 0: CPOL=0; CPHA=0 */
    SPI_CLK_MODE1, /*!< Mode 1: CPOL=0; CPHA=1 */
    SPI_CLK_MODE2, /*!< Mode 2: CPOL=1; CPHA=0 */
    SPI_CLK_MODE3  /*!< Mode 3: CPOL=1; CPHA=1 */
} spi_clk_mode_t;

/*****************************************************************************
 * @defgroup SPI1 Functions
 * @{
 */

#if SPI1_ENABLE

extern SPI_HandleTypeDef spi1_handle;

void spi1_init(uint32_t mode, spi_clk_mode_t clk_mode, uint32_t data_size,
               uint32_t first_bit);
void spi1_deinit(void);

#if SPI1_RX_DMA
#define SPI1_RX_DMA_IRQHandler                                                 \
    CSP_DMA_STREAM_IRQ(SPI1_RX_DMA_NUMBER, SPI1_RX_DMA_STREAM)
#endif /* SPI1_RX_DMA */

#if SPI1_TX_DMA
#define SPI1_TX_DMA_IRQHandler                                                 \
    CSP_DMA_STREAM_IRQ(SPI1_TX_DMA_NUMBER, SPI1_TX_DMA_STREAM)
#endif /* SPI1_TX_DMA */

#endif /* SPI1_ENABLE */

/**
 * @}
 */

/*****************************************************************************
 * @defgroup SPI2 Functions
 * @{
 */

#if SPI2_ENABLE

extern SPI_HandleTypeDef spi2_handle;

void spi2_init(uint32_t mode, spi_clk_mode_t clk_mode, uint32_t data_size,
               uint32_t first_bit);
void spi2_deinit(void);

#if SPI2_RX_DMA
#define SPI2_RX_DMA_IRQHandler                                                 \
    CSP_DMA_STREAM_IRQ(SPI2_RX_DMA_NUMBER, SPI2_RX_DMA_STREAM)
#endif /* SPI2_RX_DMA */

#if SPI2_TX_DMA
#define SPI2_TX_DMA_IRQHandler                                                 \
    CSP_DMA_STREAM_IRQ(SPI2_TX_DMA_NUMBER, SPI2_TX_DMA_STREAM)
#endif /* SPI2_TX_DMA */

#endif /* SPI2_ENABLE */

/**
 * @}
 */

/*****************************************************************************
 * @defgroup SPI3 Functions
 * @{
 */

#if SPI3_ENABLE

extern SPI_HandleTypeDef spi3_handle;

void spi3_init(uint32_t mode, spi_clk_mode_t clk_mode, uint32_t data_size,
               uint32_t first_bit);
void spi3_deinit(void);

#if SPI3_RX_DMA
#define SPI3_RX_DMA_IRQHandler                                                 \
    CSP_DMA_STREAM_IRQ(SPI3_RX_DMA_NUMBER, SPI3_RX_DMA_STREAM)
#endif /* SPI3_RX_DMA */

#if SPI3_TX_DMA
#define SPI3_TX_DMA_IRQHandler                                                 \
    CSP_DMA_STREAM_IRQ(SPI3_TX_DMA_NUMBER, SPI3_TX_DMA_STREAM)
#endif /* SPI3_TX_DMA */

#endif /* SPI3_ENABLE */

/**
 * @}
 */

/*****************************************************************************
 * @defgroup SPI4 Functions
 * @{
 */

#if SPI4_ENABLE

extern SPI_HandleTypeDef spi4_handle;

void spi4_init(uint32_t mode, spi_clk_mode_t clk_mode, uint32_t data_size,
               uint32_t first_bit);
void spi4_deinit(void);

#if SPI4_RX_DMA
#define SPI4_RX_DMA_IRQHandler                                                 \
    CSP_DMA_STREAM_IRQ(SPI4_RX_DMA_NUMBER, SPI4_RX_DMA_STREAM)
#endif /* SPI4_RX_DMA */

#if SPI4_TX_DMA
#define SPI4_TX_DMA_IRQHandler                                                 \
    CSP_DMA_STREAM_IRQ(SPI4_TX_DMA_NUMBER, SPI4_TX_DMA_STREAM)
#endif /* SPI4_TX_DMA */

#endif /* SPI4_ENABLE */

/**
 * @}
 */

/*****************************************************************************
 * @defgroup SPI5 Functions
 * @{
 */

#if SPI5_ENABLE

extern SPI_HandleTypeDef spi5_handle;

void spi5_init(uint32_t mode, spi_clk_mode_t clk_mode, uint32_t data_size,
               uint32_t first_bit);
void spi5_deinit(void);

#if SPI5_RX_DMA
#define SPI5_RX_DMA_IRQHandler                                                 \
    CSP_DMA_STREAM_IRQ(SPI5_RX_DMA_NUMBER, SPI5_RX_DMA_STREAM)
#endif /* SPI5_RX_DMA */

#if SPI5_TX_DMA
#define SPI5_TX_DMA_IRQHandler                                                 \
    CSP_DMA_STREAM_IRQ(SPI5_TX_DMA_NUMBER, SPI5_TX_DMA_STREAM)
#endif /* SPI5_TX_DMA */

#endif /* SPI5_ENABLE */

/**
 * @}
 */

/*****************************************************************************
 * @defgroup SPI6 Functions
 * @{
 */

#if SPI6_ENABLE

extern SPI_HandleTypeDef spi6_handle;

void spi6_init(uint32_t mode, spi_clk_mode_t clk_mode, uint32_t data_size,
               uint32_t first_bit);
void spi6_deinit(void);

#if SPI6_RX_DMA
#define SPI6_RX_DMA_IRQHandler                                                 \
    CSP_DMA_STREAM_IRQ(SPI6_RX_DMA_NUMBER, SPI6_RX_DMA_STREAM)
#endif /* SPI6_RX_DMA */

#if SPI6_TX_DMA
#define SPI6_TX_DMA_IRQHandler                                                 \
    CSP_DMA_STREAM_IRQ(SPI6_TX_DMA_NUMBER, SPI6_TX_DMA_STREAM)
#endif /* SPI6_TX_DMA */

#endif /* SPI6_ENABLE */

/**
 * @}
 */

/*****************************************************************************
 * @defgroup SPI Public Functions
 * @{
 */

uint8_t spi_rw_one_byte(SPI_HandleTypeDef *hspi, uint8_t byte);
uint16_t spi_rw_two_byte(SPI_HandleTypeDef *hspi, uint16_t tx_data);

uint8_t spi_change_speed(SPI_HandleTypeDef *hspi, uint8_t speed);
/**
 * @}
 */

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* __SPI_STM32F4XX_H */
