#include "types.h"
#include "usb_config.h"
#include "usb_definitions.h"
#include "usb_descriptor.h"
#include "usb_device.h"
#include "usb_cdc_definitions.h"

#include "cdc.h"

#define WBVAL(x) (x & 0xFF),((x >> 8) & 0xFF)

typedef enum
{
  STR_DESCRIPTOR_IDX_LANG_ID = 0,   /* Language ID */
  STR_DESCRIPTOR_IDX_MANUFACTURER,  /* iManufacturer */
  STR_DESCRIPTOR_IDX_PRODUCT,       /* iProduct */
  STR_DESCRIPTOR_IDX_CDC0,
  STR_DESCRIPTOR_IDX_CDC1,
  STR_DESCRIPTOR_IDX_CDC2,
  STR_DESCRIPTOR_IDX_CDC3,
  STR_DESCRIPTOR_IDX_SERIAL_NUMBER, /* iSerialNumber */
  /* Strings count */
  STR_DESCRIPTOR_IDX_CNT
} STR_DESCRIPTOR_IDX;

typedef enum
{
  USB_INTERFACE_IDX_CDC0 = 0,
  USB_INTERFACE_IDX_CDC1,
  USB_INTERFACE_IDX_CDC2,
  USB_INTERFACE_IDX_CDC3,
  /* Interfaces count */
  USB_INTERFACE_IDX_CNT
} USB_INTERFACE_IDX;

typedef enum
{
  USB_ENDPOINT_IDX_CTRL = 0,
  USB_ENDPOINT_IDX_CDC0,
  USB_ENDPOINT_IDX_CDC1,
  USB_ENDPOINT_IDX_CDC2,
  USB_ENDPOINT_IDX_CDC3,
  /* Endpoints count */
  USB_ENDPOINT_IDX_CNT
} USB_ENDPOINT_IDX;

/* -------------------------------------------------------------------------- */

/* USB Standard Device Descriptor */
static const U8 USB_DeviceDescriptor[] =
{
  USB_DEVICE_DESCRIPTOR_SIZE,            /* bLength */
  USB_DEVICE_DESCRIPTOR_TYPE,            /* bDescriptorType */
  WBVAL(0x0200), /* 2.00 */              /* bcdUSB */
  USB_DEVICE_CLASS_RESERVED,             /* bDeviceClass */
  0x00,                                  /* bDeviceSubClass */
  0x00,                                  /* bDeviceProtocol */
  USB_CTRL_PACKET_SIZE,                  /* bMaxPacketSize0 */
  WBVAL(0x10C4),                         /* idVendor */
  WBVAL(0xEA71),                         /* idProduct */
  WBVAL(0x0100), /* 1.00 */              /* bcdDevice */
  STR_DESCRIPTOR_IDX_MANUFACTURER,       /* iManufacturer */
  STR_DESCRIPTOR_IDX_PRODUCT,            /* iProduct */
  STR_DESCRIPTOR_IDX_SERIAL_NUMBER,      /* iSerialNumber */
  0x01                                   /* bNumConfigurations */
};

/* -------------------------------------------------------------------------- */
/* USB Configuration Descriptor */
/* All Descriptors (Configuration, Interface, Endpoint, Class, Vendor) */
static const U8 USB_ConfigDescriptor[] =
{
/* Configuration 1 */
  USB_CONFIGURATION_DESCRIPTOR_SIZE,     /* bLength */
  USB_CONFIGURATION_DESCRIPTOR_TYPE,     /* bDescriptorType */
  WBVAL((                                /* wTotalLength */
   USB_CONFIGURATION_DESCRIPTOR_SIZE  * (1)                              +
   USB_INTERFACE_DESCRIPTOR_SIZE      * (USB_INTERFACE_IDX_CNT)          +
   USB_ENDPOINT_DESCRIPTOR_SIZE       * (USB_INTERFACE_IDX_CNT * 2)
  )),
  USB_INTERFACE_IDX_CNT,                 /* bNumInterfaces */
  0x01,                                  /* bConfigurationValue */
  0x00,                                  /* iConfiguration */
  USB_CONFIG_BUS_POWERED /*|*/           /* bmAttributes */
  /*USB_CONFIG_REMOTE_WAKEUP*/,
  USB_CONFIG_POWER_MA(500),              /* bMaxPower */
/* Interface 0, Alternate Setting 0, Vendor Specific Class */
  USB_INTERFACE_DESCRIPTOR_SIZE,         /* bLength */
  USB_INTERFACE_DESCRIPTOR_TYPE,         /* bDescriptorType */
  USB_INTERFACE_IDX_CDC0,                /* bInterfaceNumber */
  0x00,                                  /* bAlternateSetting */
  0x02,                                  /* bNumEndpoints */
  USB_DEVICE_CLASS_VENDOR_SPECIFIC,      /* bInterfaceClass */
  CDC_IF_SUBCLASS_NONE,                  /* bInterfaceSubClass */
  CDC_IF_PROTOCOL_NONE,                  /* bInterfaceProtocol */
  STR_DESCRIPTOR_IDX_CDC0,               /* iInterface */
/* Bulk In Endpoint */
  USB_ENDPOINT_DESCRIPTOR_SIZE,          /* bLength */
  USB_ENDPOINT_DESCRIPTOR_TYPE,          /* bDescriptorType */
  USB_ENDPOINT_I(USB_ENDPOINT_IDX_CDC0), /* bEndpointAddress */
  USB_ENDPOINT_TYPE_BULK,                /* bmAttributes */
  WBVAL(USB_CDC_PACKET_SIZE),            /* wMaxPacketSize */
  0,                                     /* bInterval */
/* Bulk Out Endpoint */
  USB_ENDPOINT_DESCRIPTOR_SIZE,          /* bLength */
  USB_ENDPOINT_DESCRIPTOR_TYPE,          /* bDescriptorType */
  USB_ENDPOINT_O(USB_ENDPOINT_IDX_CDC0), /* bEndpointAddress */
  USB_ENDPOINT_TYPE_BULK,                /* bmAttributes */
  WBVAL(USB_CDC_PACKET_SIZE),            /* wMaxPacketSize */
  0,                                     /* bInterval */
/* Interface 1, Alternate Setting 0, Vendor Specific Class */
  USB_INTERFACE_DESCRIPTOR_SIZE,         /* bLength */
  USB_INTERFACE_DESCRIPTOR_TYPE,         /* bDescriptorType */
  USB_INTERFACE_IDX_CDC1,                /* bInterfaceNumber */
  0x00,                                  /* bAlternateSetting */
  0x02,                                  /* bNumEndpoints */
  USB_DEVICE_CLASS_VENDOR_SPECIFIC,      /* bInterfaceClass */
  CDC_IF_SUBCLASS_NONE,                  /* bInterfaceSubClass */
  CDC_IF_PROTOCOL_NONE,                  /* bInterfaceProtocol */
  STR_DESCRIPTOR_IDX_CDC1,               /* iInterface */
/* Bulk In Endpoint */
  USB_ENDPOINT_DESCRIPTOR_SIZE,          /* bLength */
  USB_ENDPOINT_DESCRIPTOR_TYPE,          /* bDescriptorType */
  USB_ENDPOINT_I(USB_ENDPOINT_IDX_CDC1), /* bEndpointAddress */
  USB_ENDPOINT_TYPE_BULK,                /* bmAttributes */
  WBVAL(USB_CDC_PACKET_SIZE),            /* wMaxPacketSize */
  0,                                     /* bInterval */
/* Bulk Out Endpoint */
  USB_ENDPOINT_DESCRIPTOR_SIZE,          /* bLength */
  USB_ENDPOINT_DESCRIPTOR_TYPE,          /* bDescriptorType */
  USB_ENDPOINT_O(USB_ENDPOINT_IDX_CDC1), /* bEndpointAddress */
  USB_ENDPOINT_TYPE_BULK,                /* bmAttributes */
  WBVAL(USB_CDC_PACKET_SIZE),            /* wMaxPacketSize */
  0,                                     /* bInterval */
/* Interface 2, Alternate Setting 0, Vendor Specific Class */
  USB_INTERFACE_DESCRIPTOR_SIZE,         /* bLength */
  USB_INTERFACE_DESCRIPTOR_TYPE,         /* bDescriptorType */
  USB_INTERFACE_IDX_CDC2,                /* bInterfaceNumber */
  0x00,                                  /* bAlternateSetting */
  0x02,                                  /* bNumEndpoints */
  USB_DEVICE_CLASS_VENDOR_SPECIFIC,      /* bInterfaceClass */
  CDC_IF_SUBCLASS_NONE,                  /* bInterfaceSubClass */
  CDC_IF_PROTOCOL_NONE,                  /* bInterfaceProtocol */
  STR_DESCRIPTOR_IDX_CDC2,               /* iInterface */
/* Bulk In Endpoint */
  USB_ENDPOINT_DESCRIPTOR_SIZE,          /* bLength */
  USB_ENDPOINT_DESCRIPTOR_TYPE,          /* bDescriptorType */
  USB_ENDPOINT_I(USB_ENDPOINT_IDX_CDC2), /* bEndpointAddress */
  USB_ENDPOINT_TYPE_BULK,                /* bmAttributes */
  WBVAL(USB_CDC_PACKET_SIZE),            /* wMaxPacketSize */
  0,                                     /* bInterval */
/* Bulk Out Endpoint */
  USB_ENDPOINT_DESCRIPTOR_SIZE,          /* bLength */
  USB_ENDPOINT_DESCRIPTOR_TYPE,          /* bDescriptorType */
  USB_ENDPOINT_O(USB_ENDPOINT_IDX_CDC2), /* bEndpointAddress */
  USB_ENDPOINT_TYPE_BULK,                /* bmAttributes */
  WBVAL(USB_CDC_PACKET_SIZE),            /* wMaxPacketSize */
  0,                                     /* bInterval */
/* Interface 3, Alternate Setting 0, Vendor Specific Class */
  USB_INTERFACE_DESCRIPTOR_SIZE,         /* bLength */
  USB_INTERFACE_DESCRIPTOR_TYPE,         /* bDescriptorType */
  USB_INTERFACE_IDX_CDC3,                /* bInterfaceNumber */
  0x00,                                  /* bAlternateSetting */
  0x02,                                  /* bNumEndpoints */
  USB_DEVICE_CLASS_VENDOR_SPECIFIC,      /* bInterfaceClass */
  CDC_IF_SUBCLASS_NONE,                  /* bInterfaceSubClass */
  CDC_IF_PROTOCOL_NONE,                  /* bInterfaceProtocol */
  STR_DESCRIPTOR_IDX_CDC3,               /* iInterface */
/* Bulk In Endpoint */
  USB_ENDPOINT_DESCRIPTOR_SIZE,          /* bLength */
  USB_ENDPOINT_DESCRIPTOR_TYPE,          /* bDescriptorType */
  USB_ENDPOINT_I(USB_ENDPOINT_IDX_CDC3), /* bEndpointAddress */
  USB_ENDPOINT_TYPE_BULK,                /* bmAttributes */
  WBVAL(USB_CDC_PACKET_SIZE),            /* wMaxPacketSize */
  0,                                     /* bInterval */
/* Bulk Out Endpoint */
  USB_ENDPOINT_DESCRIPTOR_SIZE,          /* bLength */
  USB_ENDPOINT_DESCRIPTOR_TYPE,          /* bDescriptorType */
  USB_ENDPOINT_O(USB_ENDPOINT_IDX_CDC3), /* bEndpointAddress */
  USB_ENDPOINT_TYPE_BULK,                /* bmAttributes */
  WBVAL(USB_CDC_PACKET_SIZE),            /* wMaxPacketSize */
  0,                                     /* bInterval */
/* Terminator */
  0                                      /* bTerminator */
};

/* -------------------------------------------------------------------------- */
/* USB String Descriptor (optional) */
static const U8 usbd_StrDescriptor_LanguageId[] =
{
  0x04,                                  /* bLength */
  USB_STRING_DESCRIPTOR_TYPE,            /* bDescriptorType */
  WBVAL(0x0409), /* US English */        /* wLANGID */
};

static const U8 usbd_StrDescriptor_Manufacturer[] =
{
  0x1A,                                  /* bLength */
  USB_STRING_DESCRIPTOR_TYPE,            /* bDescriptorType */
  'S',0,
  'i',0,
  'L',0,
  'a',0,
  'b',0,
  's',0,
};

static const U8 usbd_StrDescriptor_Product[] =
{
  0x54,                                  /* bLength */
  USB_STRING_DESCRIPTOR_TYPE,            /* bDescriptorType */
  'C',0,
  'P',0,
  '2',0,
  '1',0,
  '0',0,
  '8',0,
};

static const U8 usbd_StrDescriptor_SerialNumber[] =
{
  0x0A,                                  /* bLength */
  USB_STRING_DESCRIPTOR_TYPE,            /* bDescriptorType */
  '3',0,
  '0',0,
  '2',0,
  '1',0,
};

static const U8 usbd_StrDescriptor_CDC0[] =
{
  0x24,                                  /* bLength */
  USB_STRING_DESCRIPTOR_TYPE,            /* bDescriptorType */
  'U',0,
  'A',0,
  'R',0,
  'T',0,
  '1',0,
};

static const U8 usbd_StrDescriptor_CDC1[] =
{
  0x24,                                  /* bLength */
  USB_STRING_DESCRIPTOR_TYPE,            /* bDescriptorType */
  'U',0,
  'A',0,
  'R',0,
  'T',0,
  '2',0,
};

static const U8 usbd_StrDescriptor_CDC2[] =
{
  0x24,                                  /* bLength */
  USB_STRING_DESCRIPTOR_TYPE,            /* bDescriptorType */
  'U',0,
  'A',0,
  'R',0,
  'T',0,
  '3',0,
};

static const U8 usbd_StrDescriptor_CDC3[] =
{
  0x24,                                  /* bLength */
  USB_STRING_DESCRIPTOR_TYPE,            /* bDescriptorType */
  'G',0,
  'P',0,
  'I',0,
  'O',0,
  's',0,
};

static const U8 * usbd_StrDescriptor[STR_DESCRIPTOR_IDX_CNT] =
{
  usbd_StrDescriptor_LanguageId,
  usbd_StrDescriptor_Manufacturer,
  usbd_StrDescriptor_Product,
  usbd_StrDescriptor_CDC0,
  usbd_StrDescriptor_CDC1,
  usbd_StrDescriptor_CDC2,
  usbd_StrDescriptor_CDC3,
  usbd_StrDescriptor_SerialNumber,
};

/* -------------------------------------------------------------------------- */

U8 *USBD_GetDeviceDescriptor(void)
{
  return (U8 *)USB_DeviceDescriptor;
};

/* -------------------------------------------------------------------------- */

U8 *USBD_GetConfigDescriptor(void)
{
  return (U8 *)USB_ConfigDescriptor;
};

/* -------------------------------------------------------------------------- */

U8 *USBD_GetStringDescriptor(U8 aIndex)
{
  if (STR_DESCRIPTOR_IDX_CNT > aIndex)
  {
    return (U8 *)usbd_StrDescriptor[aIndex];
  }
  else
  {
    return NULL;
  }
}

/* -------------------------------------------------------------------------- */

FW_BOOLEAN USBD_GetItrfaceDescriptor
(
  USB_SETUP_PACKET * pSetup,
  U8 **pData,
  U16 *pSize
)
{
  FW_BOOLEAN result = FW_FALSE;

  return result;
}

/* -------------------------------------------------------------------------- */

U8 USBD_GetItrfacesCount(void)
{
  return USB_INTERFACE_IDX_CNT;
}

/* --- Interfaces Callbacks Descriptor -------------------------------------- */

const USBD_INTERFACE_CALLBACKS_DESCRIPTOR
      USBD_IfCbDescriptor[USB_INTERFACE_IDX_CNT] =
{
  [USB_INTERFACE_IDX_CDC0] =
  {
    .CbInit      = CDC_Init,
    .CbCtrlSetup = CDC_CtrlSetupReq,
    .CbCtrlOut   = CDC_CtrlOutReq,
    .CbSOF       = CDC_SOF,
    .CbEndPointI = CDC_BulkI,
    .CbEndPointO = CDC_BulkO,
    .Param       = USB_CDC0_NUM,
    .EndPointI   = USB_ENDPOINT_I(USB_ENDPOINT_IDX_CDC0),
    .EndPointO   = USB_ENDPOINT_O(USB_ENDPOINT_IDX_CDC0),
  },
  [USB_INTERFACE_IDX_CDC1] =
  {
    .CbInit      = NULL,
    .CbCtrlSetup = CDC_CtrlSetupReq,
    .CbCtrlOut   = CDC_CtrlOutReq,
    .CbSOF       = NULL,
    .CbEndPointI = CDC_BulkI,
    .CbEndPointO = CDC_BulkO,
    .Param       = USB_CDC1_NUM,
    .EndPointI   = USB_ENDPOINT_I(USB_ENDPOINT_IDX_CDC1),
    .EndPointO   = USB_ENDPOINT_O(USB_ENDPOINT_IDX_CDC1),
  },
  [USB_INTERFACE_IDX_CDC2] =
  {
    .CbInit      = NULL,
    .CbCtrlSetup = CDC_CtrlSetupReq,
    .CbCtrlOut   = CDC_CtrlOutReq,
    .CbSOF       = NULL,
    .CbEndPointI = CDC_BulkI,
    .CbEndPointO = CDC_BulkO,
    .Param       = USB_CDC2_NUM,
    .EndPointI   = USB_ENDPOINT_I(USB_ENDPOINT_IDX_CDC2),
    .EndPointO   = USB_ENDPOINT_O(USB_ENDPOINT_IDX_CDC2),
  },
  [USB_INTERFACE_IDX_CDC3] =
  {
    .CbInit      = NULL,
    .CbCtrlSetup = CDC_CtrlSetupReq,
    .CbCtrlOut   = CDC_CtrlOutReq,
    .CbSOF       = NULL,
    .CbEndPointI = CDC_BulkI,
    .CbEndPointO = CDC_BulkO,
    .Param       = USB_CDC3_NUM,
    .EndPointI   = USB_ENDPOINT_I(USB_ENDPOINT_IDX_CDC3),
    .EndPointO   = USB_ENDPOINT_O(USB_ENDPOINT_IDX_CDC3),
  },
};

/* -------------------------------------------------------------------------- */

USB_CDC_NUM USBD_CDC_GetPortNumber(U16 aIfcIdx)
{
  static const USB_CDC_NUM itfIdx2CdcNumMap[USB_INTERFACE_IDX_CNT] =
  {
    [USB_INTERFACE_IDX_CDC0] = USB_CDC0_NUM,
    [USB_INTERFACE_IDX_CDC1] = USB_CDC1_NUM,
    [USB_INTERFACE_IDX_CDC2] = USB_CDC2_NUM,
    [USB_INTERFACE_IDX_CDC3] = USB_CDC3_NUM,
  };
  return itfIdx2CdcNumMap[aIfcIdx];
}

/* -------------------------------------------------------------------------- */

static USB_INTERFACE_IDX USBD_CDC_GetInterfaceIndex(U8 aCdcNum)
{
  static const USB_INTERFACE_IDX cdcNum2ItfIdxMap[USB_CDC_CNT] =
  {
    [USB_CDC0_NUM] = USB_INTERFACE_IDX_CDC0,
    [USB_CDC1_NUM] = USB_INTERFACE_IDX_CDC1,
    [USB_CDC2_NUM] = USB_INTERFACE_IDX_CDC2,
    [USB_CDC3_NUM] = USB_INTERFACE_IDX_CDC3,
  };
  return cdcNum2ItfIdxMap[aCdcNum];
}

/* -------------------------------------------------------------------------- */

U32 USBD_CDC_IEP_WrWsCb(USB_CDC_NUM aCdcNum, USBD_CbByte pGetByteCb, U32 aSize)
{
  USB_INTERFACE_IDX idx = USBD_CDC_GetInterfaceIndex(aCdcNum);
  return USBD_EP_WrWsCb(USBD_IfCbDescriptor[idx].EndPointI, pGetByteCb, aSize);
}

/* -------------------------------------------------------------------------- */

FW_BOOLEAN USBD_CDC_IEP_IsTxEmpty(USB_CDC_NUM aCdcNum)
{
  USB_INTERFACE_IDX idx = USBD_CDC_GetInterfaceIndex(aCdcNum);
  return USBD_EP_IsTxEmpty(USBD_IfCbDescriptor[idx].EndPointI);
}

/* -------------------------------------------------------------------------- */

U32 USBD_CDC_OEP_RdWsCb(USB_CDC_NUM aCdcNum, USBD_CbByte pPutByteCb, U32 aSize)
{
  USB_INTERFACE_IDX idx = USBD_CDC_GetInterfaceIndex(aCdcNum);
  return USBD_EP_RdWsCb(USBD_IfCbDescriptor[idx].EndPointO, pPutByteCb, aSize);
}

/* -------------------------------------------------------------------------- */

FW_BOOLEAN USBD_CDC_OEP_IsRxEmpty(USB_CDC_NUM aCdcNum)
{
  USB_INTERFACE_IDX idx = USBD_CDC_GetInterfaceIndex(aCdcNum);
  return USBD_EP_IsRxEmpty(USBD_IfCbDescriptor[idx].EndPointO);
}

/* -------------------------------------------------------------------------- */
