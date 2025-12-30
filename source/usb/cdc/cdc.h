#ifndef __CDC_H__
#define __CDC_H__

/* --- Class Specific Definitions ------------------------------------------- */

/* CDC Bulk Endpoint Max Packet Size */
#define USB_CDC_PACKET_SIZE        (32)

void CDC_Init(void);
USB_CTRL_STAGE CDC_CtrlSetupReq
(
  USB_SETUP_PACKET * pSetup,
  U8 **pData,
  U16 *pSize
);
USB_CTRL_STAGE CDC_CtrlOutReq
(
  USB_SETUP_PACKET * pSetup,
  U8 **pData,
  U16 *pSize
);
void CDC_SOF(void);
void CDC_BulkI(U32 aParam, U32 aEvent);
void CDC_BulkO(U32 aParam, U32 aEvent);

#endif /* __CDC_H__ */
