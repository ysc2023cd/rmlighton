#include "main.h"
#include "usart.h"

extern uint8_t rx_msg[4];

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
    if (huart == &huart7) {
        if (rx_msg[0] == 'R') {
            HAL_GPIO_WritePin(LED_R_GPIO_Port, LED_R_Pin, GPIO_PIN_RESET);
        }else if (rx_msg[0] == 'M') {
            HAL_GPIO_WritePin(LED_R_GPIO_Port, LED_R_Pin, GPIO_PIN_SET);
        }
    }
    HAL_UART_Receive_IT(&huart7, rx_msg, 1);
}