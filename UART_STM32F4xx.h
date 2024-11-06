/**
 * @file    UART_STM32F4xx.h
 * @author  Deadline039
 * @brief   Chip Support Package of UART on STM32F4xx
 * @version 1.0
 * @date    2024-10-22
 */

#ifndef __UART_STM32F4XX_H
#define __UART_STM32F4XX_H

#include "CSP_Config.h"
#include "stm32f4xx_hal.h"

#include <stdarg.h>

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/*****************************************************************************
 * @defgroup USART1 Functions
 * @{
 */

#if USART1_ENABLE

extern UART_HandleTypeDef usart1_handle;
void usart1_init(uint32_t baud_rate);
void usart1_deinit(void);

#if USART1_RX_DMA
#define USART1_RX_DMA_IRQHandler                                               \
    CSP_DMA_STREAM_IRQ(USART1_RX_DMA_NUMBER, USART1_RX_DMA_STREAM)
#endif /* USART1_RX_DMA */

#if USART1_TX_DMA
#define USART1_TX_DMA_IRQHandler                                               \
    CSP_DMA_STREAM_IRQ(USART1_TX_DMA_NUMBER, USART1_TX_DMA_STREAM)
#endif /* USART1_TX_DMA */

#endif /* USART1_ENABLE */

/**
 * @}
 */

/*****************************************************************************
 * @defgroup USART2 Functions
 * @{
 */

#if USART2_ENABLE

extern UART_HandleTypeDef usart2_handle;
void usart2_init(uint32_t baud_rate);
void usart2_deinit(void);

#if USART2_RX_DMA
#define USART2_RX_DMA_IRQHandler                                               \
    CSP_DMA_STREAM_IRQ(USART2_RX_DMA_NUMBER, USART2_RX_DMA_STREAM)
#endif /* USART2_RX_DMA */

#if USART2_TX_DMA
#define USART2_TX_DMA_IRQHandler                                               \
    CSP_DMA_STREAM_IRQ(USART2_TX_DMA_NUMBER, USART2_TX_DMA_STREAM)
#endif /* USART2_TX_DMA */

#endif /* USART2_ENABLE */

/**
 * @}
 */

/*****************************************************************************
 * @defgroup USART3 Functions
 * @{
 */

#if USART3_ENABLE

extern UART_HandleTypeDef usart3_handle;
void usart3_init(uint32_t baud_rate);
void usart3_deinit(void);

#if USART3_RX_DMA
#define USART3_RX_DMA_IRQHandler                                               \
    CSP_DMA_STREAM_IRQ(USART3_RX_DMA_NUMBER, USART3_RX_DMA_STREAM)
#endif /* USART3_RX_DMA */

#if USART3_TX_DMA
#define USART3_TX_DMA_IRQHandler                                               \
    CSP_DMA_STREAM_IRQ(USART3_TX_DMA_NUMBER, USART3_TX_DMA_STREAM)
#endif /* USART3_TX_DMA */

#endif /* USART3_ENABLE */

/**
 * @}
 */

/*****************************************************************************
 * @defgroup UART4 Functions
 * @{
 */

#if UART4_ENABLE

extern UART_HandleTypeDef uart4_handle;
void uart4_init(uint32_t baud_rate);
void uart4_deinit(void);

#if UART4_RX_DMA
#define UART4_RX_DMA_IRQHandler                                                \
    CSP_DMA_STREAM_IRQ(UART4_RX_DMA_NUMBER, UART4_RX_DMA_STREAM)
#endif /* UART4_RX_DMA */

#if UART4_TX_DMA
#define UART4_TX_DMA_IRQHandler                                                \
    CSP_DMA_STREAM_IRQ(UART4_TX_DMA_NUMBER, UART4_TX_DMA_STREAM)
#endif /* UART4_TX_DMA */

#endif /* UART4_ENABLE */

/**
 * @}
 */

/*****************************************************************************
 * @defgroup UART5 Functions
 * @{
 */

#if UART5_ENABLE

extern UART_HandleTypeDef uart5_handle;
void uart5_init(uint32_t baud_rate);
void uart5_deinit(void);

#if UART5_RX_DMA
#define UART5_RX_DMA_IRQHandler                                                \
    CSP_DMA_STREAM_IRQ(UART5_RX_DMA_NUMBER, UART5_RX_DMA_STREAM)
#endif /* UART5_RX_DMA */

#if UART5_TX_DMA
#define UART5_TX_DMA_IRQHandler                                                \
    CSP_DMA_STREAM_IRQ(UART5_TX_DMA_NUMBER, UART5_TX_DMA_STREAM)
#endif /* UART5_TX_DMA */

#endif /* UART5_ENABLE */

/**
 * @}
 */

/*****************************************************************************
 * @defgroup USART6 Functions
 * @{
 */

#if USART6_ENABLE

extern UART_HandleTypeDef usart6_handle;
void usart6_init(uint32_t baud_rate);
void usart6_deinit(void);

#if USART6_RX_DMA
#define USART6_RX_DMA_IRQHandler                                               \
    CSP_DMA_STREAM_IRQ(USART6_RX_DMA_NUMBER, USART6_RX_DMA_STREAM)
#endif /* USART6_RX_DMA */

#if USART6_TX_DMA
#define USART6_TX_DMA_IRQHandler                                               \
    CSP_DMA_STREAM_IRQ(USART6_TX_DMA_NUMBER, USART6_TX_DMA_STREAM)
#endif /* USART6_TX_DMA */

#endif /* USART6_ENABLE */

/**
 * @}
 */

/*****************************************************************************
 * @defgroup UART7 Functions
 * @{
 */

#if UART7_ENABLE

extern UART_HandleTypeDef uart7_handle;
void uart7_init(uint32_t baud_rate);
void uart7_deinit(void);

#if UART7_RX_DMA
#define UART7_RX_DMA_IRQHandler                                                \
    CSP_DMA_STREAM_IRQ(UART7_RX_DMA_NUMBER, UART7_RX_DMA_STREAM)
#endif /* UART7_RX_DMA */

#if UART7_TX_DMA
#define UART7_TX_DMA_IRQHandler                                                \
    CSP_DMA_STREAM_IRQ(UART7_TX_DMA_NUMBER, UART7_TX_DMA_STREAM)
#endif /* UART7_TX_DMA */

#endif /* UART7_ENABLE */

/**
 * @}
 */

/*****************************************************************************
 * @defgroup UART8 Functions
 * @{
 */

#if UART8_ENABLE

extern UART_HandleTypeDef uart8_handle;
void uart8_init(uint32_t baud_rate);
void uart8_deinit(void);

#if UART8_RX_DMA
#define UART8_RX_DMA_IRQHandler                                                \
    CSP_DMA_STREAM_IRQ(UART8_RX_DMA_NUMBER, UART8_RX_DMA_STREAM)
#endif /* UART8_RX_DMA */

#if UART8_TX_DMA
#define UART8_TX_DMA_IRQHandler                                                \
    CSP_DMA_STREAM_IRQ(UART8_TX_DMA_NUMBER, UART8_TX_DMA_STREAM)
#endif /* UART8_TX_DMA */

#endif /* UART8_ENABLE */

/**
 * @}
 */

/*****************************************************************************
 * @defgroup UART9 Functions
 * @{
 */

#if UART9_ENABLE

extern UART_HandleTypeDef uart9_handle;
void uart9_init(uint32_t baud_rate);
void uart9_deinit(void);

#if UART9_RX_DMA
#define UART9_RX_DMA_IRQHandler                                                \
    CSP_DMA_STREAM_IRQ(UART9_RX_DMA_NUMBER, UART9_RX_DMA_STREAM)
#endif /* UART9_RX_DMA */

#if UART9_TX_DMA
#define UART9_TX_DMA_IRQHandler                                                \
    CSP_DMA_STREAM_IRQ(UART9_TX_DMA_NUMBER, UART9_TX_DMA_STREAM)
#endif /* UART9_TX_DMA */

#endif /* UART9_ENABLE */

/**
 * @}
 */

/*****************************************************************************
 * @defgroup UART10 Functions
 * @{
 */

#if UART10_ENABLE

extern UART_HandleTypeDef uart10_handle;
void uart10_init(uint32_t baud_rate);
void uart10_deinit(void);

#if UART10_RX_DMA
#define UART10_RX_DMA_IRQHandler                                               \
    CSP_DMA_STREAM_IRQ(UART10_RX_DMA_NUMBER, UART10_RX_DMA_STREAM)
#endif /* UART10_RX_DMA */

#if UART10_TX_DMA
#define UART10_TX_DMA_IRQHandler                                               \
    CSP_DMA_STREAM_IRQ(UART10_TX_DMA_NUMBER, UART10_TX_DMA_STREAM)
#endif /* UART10_TX_DMA */

#endif /* UART10_ENABLE */

/**
 * @}
 */

/*****************************************************************************
 * @defgroup Public uart function.
 * @{
 */

int uart_printf(UART_HandleTypeDef *huart, const char *__format, ...);
int uart_scanf(UART_HandleTypeDef *huart, const char *__format, ...);

uint32_t uart_dmarx_read(UART_HandleTypeDef *huart, void *buf, size_t len);
uint8_t uart_dmarx_resize_fifo(UART_HandleTypeDef *huart, uint32_t buf_size,
                               uint32_t fifo_size);
uint32_t uart_dmarx_get_buf_size(UART_HandleTypeDef *huart);
uint32_t uart_dmarx_get_fifo_size(UART_HandleTypeDef *huart);

uint32_t uart_dmatx_write(UART_HandleTypeDef *huart, const void *data,
                          size_t len);
uint32_t uart_dmatx_send(UART_HandleTypeDef *huart);
uint8_t uart_dmatx_resize_buf(UART_HandleTypeDef *huart, uint32_t size);
uint32_t uart_damtx_get_buf_szie(UART_HandleTypeDef *huart);

/**
 * @}
 */

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* __UART_STM32F4XX_H */
