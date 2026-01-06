#ifndef __HARDWARE_CONFIG_H__
#define __HARDWARE_CONFIG_H__

/* Debug interface */
#define DBG_RTT

/* SWD - SWO */
#define SWD_SWO_PORT         GPIO_B
#define SWD_SWO_PIN          3

/* USB - Pull Up */
#define USB_PUP_PORT         GPIO_B
#define USB_PUP_PIN          2

/* USB - DP/DM */
#define USB_DM_PORT          GPIO_A
#define USB_DM_PIN           11
#define USB_DP_PORT          GPIO_A
#define USB_DP_PIN           12

/* LED */
#define LED_PORT             GPIO_C
#define LED_PIN              13

/* UART1: PA9 - Tx, PA10 - Rx, DTR - PB8, RTS - PB6 */
#define UART1_TX_PORT        GPIO_A
#define UART1_TX_PIN         9
#define UART1_RX_PORT        GPIO_A
#define UART1_RX_PIN         10
#define UART1_DTR_PORT       GPIO_B
#define UART1_DTR_PIN        8
#define UART1_RTS_PORT       GPIO_B
#define UART1_RTS_PIN        6

/* UART2: PA2 - Tx, PA3 - Rx */
#define UART2_TX_PORT        GPIO_A
#define UART2_TX_PIN         2
#define UART2_RX_PORT        GPIO_A
#define UART2_RX_PIN         3

/* UART3: PB10 - Tx, PB11 - Rx */
#define UART3_TX_PORT        GPIO_B
#define UART3_TX_PIN         10
#define UART3_RX_PORT        GPIO_B
#define UART3_RX_PIN         11

/* GPIOs */
#define GPIO1_PORT           GPIO_B
#define GPIO1_PIN            12
#define GPIO2_PORT           GPIO_B
#define GPIO2_PIN            13
#define GPIO3_PORT           GPIO_B
#define GPIO3_PIN            14
#define GPIO4_PORT           GPIO_B
#define GPIO4_PIN            15

#endif  /* __HARDWARE_CONFIG_H__ */
