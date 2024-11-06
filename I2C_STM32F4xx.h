/**
 * @file    I2C_STM32F4xx.h
 * @author  Deadline039
 * @brief   Chip Support Package of I2C on STM32F4xx
 * @version 1.0
 * @date    2024-10-22
 */

#ifndef __I2C_STM32F4XX_H
#define __I2C_STM32F4XX_H

#include "CSP_Config.h"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/*****************************************************************************
 * @defgroup I2C1 Functions
 * @{
 */

#if I2C1_ENABLE

extern I2C_HandleTypeDef i2c1_handle;

void i2c1_init(uint32_t clock_speed, uint32_t address, uint32_t address_mode);
void i2c1_deinit(void);

#if I2C1_RX_DMA
#define I2C1_RX_DMA_IRQHandler                                                 \
    CSP_DMA_STREAM_IRQ(I2C1_RX_DMA_NUMBER, I2C1_RX_DMA_STREAM)
#endif /* I2C1_RX_DMA */

#if I2C1_TX_DMA
#define I2C1_TX_DMA_IRQHandler                                                 \
    CSP_DMA_STREAM_IRQ(I2C1_TX_DMA_NUMBER, I2C1_TX_DMA_STREAM)
#endif /* I2C1_TX_DMA */

#endif /* I2C1_ENABLE */

/**
 * @}
 */

/*****************************************************************************
 * @defgroup I2C2 Functions
 * @{
 */

#if I2C2_ENABLE

extern I2C_HandleTypeDef i2c2_handle;

void i2c2_init(uint32_t clock_speed, uint32_t address, uint32_t address_mode);
void i2c2_deinit(void);

#if I2C2_RX_DMA
#define I2C2_RX_DMA_IRQHandler                                                 \
    CSP_DMA_STREAM_IRQ(I2C2_RX_DMA_NUMBER, I2C2_RX_DMA_STREAM)
#endif /* I2C2_RX_DMA */

#if I2C2_TX_DMA
#define I2C2_TX_DMA_IRQHandler                                                 \
    CSP_DMA_STREAM_IRQ(I2C2_TX_DMA_NUMBER, I2C2_TX_DMA_STREAM)
#endif /* I2C2_TX_DMA */

#endif /* I2C2_ENABLE */

/**
 * @}
 */

/*****************************************************************************
 * @defgroup I2C3 Functions
 * @{
 */

#if I2C3_ENABLE

extern I2C_HandleTypeDef i2c3_handle;

void i2c3_init(uint32_t clock_speed, uint32_t address, uint32_t address_mode);
void i2c3_deinit(void);

#if I2C3_RX_DMA
#define I2C3_RX_DMA_IRQHandler                                                 \
    CSP_DMA_STREAM_IRQ(I2C3_RX_DMA_NUMBER, I2C3_RX_DMA_STREAM)
#endif /* I2C3_RX_DMA */

#if I2C3_TX_DMA
#define I2C3_TX_DMA_IRQHandler                                                 \
    CSP_DMA_STREAM_IRQ(I2C3_TX_DMA_NUMBER, I2C3_TX_DMA_STREAM)
#endif /* I2C3_TX_DMA */

/**
 * @}
 */

#endif /* I2C3_ENABLE */

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* __I2C_STM32F7XX_H */
