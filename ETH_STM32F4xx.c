/**
 * @file    ETH_STM32F4xx.c
 * @author  Deadline039
 * @brief   Chip Support Package of Ethernet on STM32F4xx
 * @version 1.0
 * @date    2024-10-22
 */

#include "CSP_Config.h"
#include <string.h>

#include "ETH_STM32F4xx.h"

#if ETH_ENABLE

static ETH_HandleTypeDef eth_handle; /**< eth handle */
static ETH_TxPacketConfig tx_config; /**< eth tx config */
/**< ethernet rx dma descriptors */
static ETH_DMADescTypeDef dma_rx_dscr_tab[ETH_RX_DESC_CNT];
/**< ethernet tx dma descriptors */
static ETH_DMADescTypeDef dma_tx_dscr_tab[ETH_TX_DESC_CNT];

/**
 * @brief     eth init
 *
 * @param[in] mac points to a mac buffer
 * @return    status code
 *            - 0 success
 *            - 1 init failed
 */
uint8_t eth_init(uint8_t mac[6]) {
    eth_handle.Instance = ETH;
    eth_handle.Init.MACAddr = mac;
#if ETH_MII
    eth_handle.Init.MediaInterface = HAL_ETH_MII_MODE;
#elif ETH_RMII
    eth_handle.Init.MediaInterface = HAL_ETH_RMII_MODE;
#endif /* ETH_MODE */

    eth_handle.Init.TxDesc = dma_tx_dscr_tab;
    eth_handle.Init.RxDesc = dma_rx_dscr_tab;
    eth_handle.Init.RxBuffLen = ETH_RX_BUF_SIZE;
    if (HAL_ETH_Init(&eth_handle) != HAL_OK) {
        return 1;
    }

    /* set tx packet config common parameters */
    memset(&tx_config, 0, sizeof(ETH_TxPacketConfig));
    tx_config.Attributes =
        ETH_TX_PACKETS_FEATURES_CSUM | ETH_TX_PACKETS_FEATURES_CRCPAD;
    tx_config.ChecksumCtrl = ETH_CHECKSUM_IPHDR_PAYLOAD_INSERT_PHDR_CALC;
    tx_config.CRCPadCtrl = ETH_CRC_PAD_INSERT;

    return 0;
}

/**
 * @brief Ethernet ISR.
 */
void ETH_IRQHandler(void) {
    HAL_ETH_IRQHandler(&eth_handle);
}

/**
 * @brief Ethernet Low level init.
 *
 * @param heth eth handle
 */
void HAL_ETH_MspInit(ETH_HandleTypeDef *heth) {

    if (heth->Instance != ETH) {
        return;
    }

    GPIO_InitTypeDef gpio_init_struct = {.Mode = GPIO_MODE_AF_PP,
                                         .Pull = GPIO_NOPULL,
                                         .Alternate = GPIO_AF11_ETH,
                                         .Speed = GPIO_SPEED_FREQ_VERY_HIGH};

    __HAL_RCC_ETH_CLK_ENABLE();

    CSP_GPIO_CLK_ENABLE(ETH_MDI_MDC_PORT);
    gpio_init_struct.Pin = ETH_MDI_MDC_PIN;
    HAL_GPIO_Init(CSP_GPIO_PORT(ETH_MDI_MDC_PORT), &gpio_init_struct);

    CSP_GPIO_CLK_ENABLE(ETH_MDI_MDIO_PORT);
    gpio_init_struct.Pin = ETH_MDI_MDIO_PIN;
    HAL_GPIO_Init(CSP_GPIO_PORT(ETH_MDI_MDIO_PORT), &gpio_init_struct);

#if ETH_MII
    CSP_GPIO_CLK_ENABLE(ETH_MII_TX_CLK_PORT);
    gpio_init_struct.Pin = ETH_MII_TX_CLK_PIN;
    HAL_GPIO_Init(CSP_GPIO_PORT(ETH_MII_TX_CLK_PORT), &gpio_init_struct);

    CSP_GPIO_CLK_ENABLE(ETH_MII_TXD0_PORT);
    gpio_init_struct.Pin = ETH_MII_TXD0_PIN;
    HAL_GPIO_Init(CSP_GPIO_PORT(ETH_MII_TXD0_PORT), &gpio_init_struct);

    CSP_GPIO_CLK_ENABLE(ETH_MII_TXD1_PORT);
    gpio_init_struct.Pin = ETH_MII_TXD1_PIN;
    HAL_GPIO_Init(CSP_GPIO_PORT(ETH_MII_TXD1_PORT), &gpio_init_struct);

    CSP_GPIO_CLK_ENABLE(ETH_MII_TXD2_PORT);
    gpio_init_struct.Pin = ETH_MII_TXD2_PIN;
    HAL_GPIO_Init(CSP_GPIO_PORT(ETH_MII_TXD2_PORT), &gpio_init_struct);

    CSP_GPIO_CLK_ENABLE(ETH_MII_TXD3_PORT);
    gpio_init_struct.Pin = ETH_MII_TXD3_PIN;
    HAL_GPIO_Init(CSP_GPIO_PORT(ETH_MII_TXD3_PORT), &gpio_init_struct);

    CSP_GPIO_CLK_ENABLE(ETH_MII_TX_EN_PORT);
    gpio_init_struct.Pin = ETH_MII_TX_EN_PIN;
    HAL_GPIO_Init(CSP_GPIO_PORT(ETH_MII_TX_EN_PORT), &gpio_init_struct);

    CSP_GPIO_CLK_ENABLE(ETH_MII_RX_CLK_PORT);
    gpio_init_struct.Pin = ETH_MII_RX_CLK_PIN;
    HAL_GPIO_Init(CSP_GPIO_PORT(ETH_MII_RX_CLK_PORT), &gpio_init_struct);

    CSP_GPIO_CLK_ENABLE(ETH_MII_RXD0_PORT);
    gpio_init_struct.Pin = ETH_MII_RXD0_PIN;
    HAL_GPIO_Init(CSP_GPIO_PORT(ETH_MII_RXD0_PORT), &gpio_init_struct);

    CSP_GPIO_CLK_ENABLE(ETH_MII_RXD1_PORT);
    gpio_init_struct.Pin = ETH_MII_RXD1_PIN;
    HAL_GPIO_Init(CSP_GPIO_PORT(ETH_MII_RXD1_PORT), &gpio_init_struct);

    CSP_GPIO_CLK_ENABLE(ETH_MII_RXD2_PORT);
    gpio_init_struct.Pin = ETH_MII_RXD2_PIN;
    HAL_GPIO_Init(CSP_GPIO_PORT(ETH_MII_RXD2_PORT), &gpio_init_struct);

    CSP_GPIO_CLK_ENABLE(ETH_MII_RXD3_PORT);
    gpio_init_struct.Pin = ETH_MII_RXD3_PIN;
    HAL_GPIO_Init(CSP_GPIO_PORT(ETH_MII_RXD3_PORT), &gpio_init_struct);

    CSP_GPIO_CLK_ENABLE(ETH_MII_RX_DV_PORT);
    gpio_init_struct.Pin = ETH_MII_RX_DV_PIN;
    HAL_GPIO_Init(CSP_GPIO_PORT(ETH_MII_RX_DV_PORT), &gpio_init_struct);

    CSP_GPIO_CLK_ENABLE(ETH_MII_RX_ER_PORT);
    gpio_init_struct.Pin = ETH_MII_RX_ER_PIN;
    HAL_GPIO_Init(CSP_GPIO_PORT(ETH_MII_RX_ER_PORT), &gpio_init_struct);

    CSP_GPIO_CLK_ENABLE(ETH_MII_CRS_PORT);
    gpio_init_struct.Pin = ETH_MII_CRS_PIN;
    HAL_GPIO_Init(CSP_GPIO_PORT(ETH_MII_CRS_PORT), &gpio_init_struct);

    CSP_GPIO_CLK_ENABLE(ETH_MII_COL_PORT);
    gpio_init_struct.Pin = ETH_MII_COL_PIN;
    HAL_GPIO_Init(CSP_GPIO_PORT(ETH_MII_COL_PORT), &gpio_init_struct);
#elif ETH_RMII

    CSP_GPIO_CLK_ENABLE(ETH_RMII_TXD0_PORT);
    gpio_init_struct.Pin = ETH_RMII_TXD0_PIN;
    HAL_GPIO_Init(CSP_GPIO_PORT(ETH_RMII_TXD0_PORT), &gpio_init_struct);

    CSP_GPIO_CLK_ENABLE(ETH_RMII_TXD1_PORT);
    gpio_init_struct.Pin = ETH_RMII_TXD1_PIN;
    HAL_GPIO_Init(CSP_GPIO_PORT(ETH_RMII_TXD1_PORT), &gpio_init_struct);

    CSP_GPIO_CLK_ENABLE(ETH_RMII_TX_EN_PORT);
    gpio_init_struct.Pin = ETH_RMII_TX_EN_PIN;
    HAL_GPIO_Init(CSP_GPIO_PORT(ETH_RMII_TX_EN_PORT), &gpio_init_struct);

    CSP_GPIO_CLK_ENABLE(ETH_RMII_RXD0_PORT);
    gpio_init_struct.Pin = ETH_RMII_RXD0_PIN;
    HAL_GPIO_Init(CSP_GPIO_PORT(ETH_RMII_RXD0_PORT), &gpio_init_struct);

    CSP_GPIO_CLK_ENABLE(ETH_RMII_RXD1_PORT);
    gpio_init_struct.Pin = ETH_RMII_RXD1_PIN;
    HAL_GPIO_Init(CSP_GPIO_PORT(ETH_RMII_RXD1_PORT), &gpio_init_struct);

    CSP_GPIO_CLK_ENABLE(ETH_RMII_REF_CLK_PORT);
    gpio_init_struct.Pin = ETH_RMII_REF_CLK_PIN;
    HAL_GPIO_Init(CSP_GPIO_PORT(ETH_RMII_REF_CLK_PORT), &gpio_init_struct);

    CSP_GPIO_CLK_ENABLE(ETH_RMII_CRS_DV_PORT);
    gpio_init_struct.Pin = ETH_RMII_CRS_DV_PIN;
    HAL_GPIO_Init(CSP_GPIO_PORT(ETH_RMII_CRS_DV_PORT), &gpio_init_struct);
#endif /* ETH_MODE */

    HAL_NVIC_SetPriority(ETH_IRQn, ETH_IT_PRIORITY, ETH_IT_SUB);
    HAL_NVIC_EnableIRQ(ETH_IRQn);

    HAL_ETH_SetMDIOClockRange(&eth_handle);
}

/**
 * @brief Ethernet Low level deinit.
 *
 * @param heth eth handle
 */
void HAL_ETH_MspDeInit(ETH_HandleTypeDef *heth) {

    if (heth->Instance != ETH) {
        return;
    }

    __HAL_RCC_ETH_CLK_DISABLE();

    HAL_GPIO_DeInit(CSP_GPIO_PORT(ETH_MDI_MDC_PORT), ETH_MDI_MDC_PIN);
    HAL_GPIO_DeInit(CSP_GPIO_PORT(ETH_MDI_MDIO_PORT), ETH_MDI_MDIO_PIN);

#if ETH_MII
    HAL_GPIO_DeInit(CSP_GPIO_PORT(ETH_MII_TX_CLK_PORT), ETH_MII_TX_CLK_PIN);
    HAL_GPIO_DeInit(CSP_GPIO_PORT(ETH_MII_TXD0_PORT), ETH_MII_TXD0_PIN);
    HAL_GPIO_DeInit(CSP_GPIO_PORT(ETH_MII_TXD1_PORT), ETH_MII_TXD1_PIN);
    HAL_GPIO_DeInit(CSP_GPIO_PORT(ETH_MII_TXD2_PORT), ETH_MII_TXD2_PIN);
    HAL_GPIO_DeInit(CSP_GPIO_PORT(ETH_MII_TXD3_PORT), ETH_MII_TXD3_PIN);
    HAL_GPIO_DeInit(CSP_GPIO_PORT(ETH_MII_TX_EN_PORT), ETH_MII_TX_EN_PIN);
    HAL_GPIO_DeInit(CSP_GPIO_PORT(ETH_MII_RX_CLK_PORT), ETH_MII_RX_CLK_PIN);
    HAL_GPIO_DeInit(CSP_GPIO_PORT(ETH_MII_RXD0_PORT), ETH_MII_RXD0_PIN);
    HAL_GPIO_DeInit(CSP_GPIO_PORT(ETH_MII_RXD1_PORT), ETH_MII_RXD1_PIN);
    HAL_GPIO_DeInit(CSP_GPIO_PORT(ETH_MII_RXD2_PORT), ETH_MII_RXD2_PIN);
    HAL_GPIO_DeInit(CSP_GPIO_PORT(ETH_MII_RXD3_PORT), ETH_MII_RXD3_PIN);
    HAL_GPIO_DeInit(CSP_GPIO_PORT(ETH_MII_RX_DV_PORT), ETH_MII_RX_DV_PIN);
    HAL_GPIO_DeInit(CSP_GPIO_PORT(ETH_MII_RX_ER_PORT), ETH_MII_RX_ER_PIN);
    HAL_GPIO_DeInit(CSP_GPIO_PORT(ETH_MII_CRS_PORT), ETH_MII_CRS_PIN);
    HAL_GPIO_DeInit(CSP_GPIO_PORT(ETH_MII_COL_PORT), ETH_MII_COL_PIN);
#elif ETH_RMII
    HAL_GPIO_DeInit(CSP_GPIO_PORT(ETH_RMII_TXD0_PORT), ETH_RMII_TXD0_PIN);
    HAL_GPIO_DeInit(CSP_GPIO_PORT(ETH_RMII_TXD1_PORT), ETH_RMII_TXD1_PIN);
    HAL_GPIO_DeInit(CSP_GPIO_PORT(ETH_RMII_TX_EN_PORT), ETH_MII_TX_EN_PIN);
    HAL_GPIO_DeInit(CSP_GPIO_PORT(ETH_RMII_RXD0_PORT), ETH_MII_RXD0_PIN);
    HAL_GPIO_DeInit(CSP_GPIO_PORT(ETH_RMII_RXD1_PORT), ETH_MII_RXD1_PIN);
    HAL_GPIO_DeInit(CSP_GPIO_PORT(ETH_RMII_REF_CLK_PORT), ETH_RMII_REF_CLK_PIN);
    HAL_GPIO_DeInit(CSP_GPIO_PORT(ETH_RMII_CRS_DV_PORT), ETH_RMII_CRS_DV_PIN);
#endif /* ETH_MODE */
    HAL_NVIC_DisableIRQ(ETH_IRQn);
}

/**
 * @brief  eth deinit
 *
 * @return status code
 *         - 0 success
 *         - 1 deinit failed
 * @note   none
 */
uint8_t eth_deinit(void) {
    if (HAL_ETH_DeInit(&eth_handle) != HAL_OK) {
        return 1;
    }

    return 0;
}

/**
 * @brief      eth phy read
 *
 * @param[in]  addr is the device address
 * @param[in]  reg is the register address
 * @param[out] data points to a data buffer
 * @return     status code
 *             - 0 success
 *             - 1 read failed
 * @note
 */
uint8_t eth_read_phy(uint8_t addr, uint8_t reg, uint16_t *data) {
    uint32_t out;

    if (HAL_ETH_ReadPHYRegister(&eth_handle, addr, reg, &out) != HAL_OK) {
        return 1;
    }
    *data = out & 0xFFFF;

    return 0;
}

/**
 * @brief     eth phy write
 *
 * @param[in] addr is the device waddress
 * @param[in] reg is the register address
 * @param[in] data is the set data
 * @return    status code
 *            - 0 success
 *            - 1 write failed
 * @note      none
 */
uint8_t eth_write_phy(uint8_t addr, uint8_t reg, uint16_t data) {
    if (HAL_ETH_WritePHYRegister(&eth_handle, addr, reg, data) != HAL_OK) {
        return 1;
    }

    return 0;
}

/**
 * @brief     eth write
 *
 * @param[in] tx_buffer points to ETH_BufferTypeDef structure
 * @param[in] data points to a data buffer
 * @param[in] len is the set length
 * @return    status code
 *            - 0 success
 *            - 1 write failed
 * @note      none
 */
uint8_t eth_write(ETH_BufferTypeDef *tx_buffer, void *data, uint32_t len) {
    uint32_t timeout = 1000;

    tx_config.Length = len;
    tx_config.TxBuffer = tx_buffer;
    tx_config.pData = data;
    if (HAL_ETH_Transmit(&eth_handle, &tx_config, timeout) != HAL_OK) {
        return 1;
    }

    return 0;
}

#endif /* ETH_ENABLE */