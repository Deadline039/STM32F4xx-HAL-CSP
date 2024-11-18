/**
 * @file    ETH_STM32F4xx.h
 * @author  Deadline039
 * @brief   Chip Support Package of Ethernet on STM32F4xx
 * @version 1.0
 * @date    2024-11-15
 * @ref     https://github.com/libdriver/lan8720/
 */

#ifndef __ETH_STM32F4XX_H
#define __ETH_STM32F4XX_H

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/**
 * @defgroup ETH
 * @{
 */

#if ETH_ENABLE

uint8_t eth_init(uint8_t mac[6]);
uint8_t eth_deinit(void);

uint8_t eth_write(ETH_BufferTypeDef *tx_buffer, void *data, uint32_t len);
uint8_t eth_read_phy(uint8_t addr, uint8_t reg, uint16_t *data);
uint8_t eth_write_phy(uint8_t addr, uint8_t reg, uint16_t data);

#endif /* ETH_ENABLE */

/**
 * @}
 */

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* __ETH_STM32F4XX_H */
