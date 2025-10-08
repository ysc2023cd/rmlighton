#include "main.h"
#include "usart.h"
#include <cstring>

extern uint8_t rx_msg[4];
extern uint8_t tx_msg[4];

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
    if (huart == &huart7) {
        memcpy(tx_msg, rx_msg, 3);
        HAL_UART_Transmit_IT(&huart7, tx_msg, 3);
        HAL_UART_Receive_IT(&huart7, rx_msg, 3);
    }
}