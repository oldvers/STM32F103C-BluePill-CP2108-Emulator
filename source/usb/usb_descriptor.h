#ifndef __USB_DESCRIPTOR_H__
#define __USB_DESCRIPTOR_H__

#include "usb_descriptor_definitions.h"
#include "usb_device.h"

/* -------------------------------------------------------------------------- */

typedef enum
{
  USB_CDC0_NUM = 0,
  USB_CDC1_NUM,
  USB_CDC2_NUM,
  USB_CDC3_NUM,
  USB_CDC_CNT
} USB_CDC_NUM;

/* --- Class Specific Optional Function Prototypes -------------------------- */

USB_CDC_NUM USBD_CDC_GetPortNumber(U16 aIfcIdx);
U32 USBD_CDC_IEP_WrWsCb(USB_CDC_NUM aCdcNum, USBD_CbByte pGetByteCb, U32 aSize);
FW_BOOLEAN USBD_CDC_IEP_IsTxEmpty(USB_CDC_NUM aCdcNum);
U32 USBD_CDC_OEP_RdWsCb(USB_CDC_NUM aCdcNum, USBD_CbByte pPutByteCb, U32 aSize);
FW_BOOLEAN USBD_CDC_OEP_IsRxEmpty(USB_CDC_NUM aCdcNum);

/* -------------------------------------------------------------------------- */

#endif  /* __USB_DESCRIPTOR_H__ */
