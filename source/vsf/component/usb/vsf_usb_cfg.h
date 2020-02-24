/*****************************************************************************
 *   Copyright(C)2009-2019 by VSF Team                                       *
 *                                                                           *
 *  Licensed under the Apache License, Version 2.0 (the "License");          *
 *  you may not use this file except in compliance with the License.         *
 *  You may obtain a copy of the License at                                  *
 *                                                                           *
 *     http://www.apache.org/licenses/LICENSE-2.0                            *
 *                                                                           *
 *  Unless required by applicable law or agreed to in writing, software      *
 *  distributed under the License is distributed on an "AS IS" BASIS,        *
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. *
 *  See the License for the specific language governing permissions and      *
 *  limitations under the License.                                           *
 *                                                                           *
 ****************************************************************************/

/*============================ INCLUDES ======================================*/
//! \note do not move this pre-processor statement to other places
#include "component/vsf_component_cfg.h"

#ifndef __VSF_USB_CFG_H__
#define __VSF_USB_CFG_H__

/*============================ MACROS ========================================*/

#ifndef VSF_USB_ASSERT
#   define VSF_USB_ASSERT                       ASSERT
#endif

#if VSF_USE_USB_DEVICE == ENABLED

// check dependency here
#   if VSF_USE_USB_DEVICE_CDCACM == ENABLED
#       ifndef VSF_USE_USB_DEVICE_CDC
#           define VSF_USE_USB_DEVICE_CDC       ENABLED
#       elif VSF_USE_USB_DEVICE_CDC != ENABLED
#           #warning "VSF_USE_USB_DEVICE_CDC MUST be enabled to use VSF_USE_USB_DEVICE_CDCACM"
#           undef VSF_USE_USB_DEVICE_CDC
#           define VSF_USE_USB_DEVICE_CDC       ENABLED
#       endif
#   endif

#endif

#ifndef VSF_USBD_CFG_STREAM_EN
#   if VSF_USE_SERVICE_STREAM == ENABLED || VSF_USE_SERVICE_VSFSTREAM == ENABLED
#       define VSF_USBD_CFG_STREAM_EN           ENABLED
#   else
#       define VSF_USBD_CFG_STREAM_EN           DISABLED
#   endif
#endif

#if     (VSF_USBD_CFG_STREAM_EN == ENABLED)                                     \
    &&  (VSF_USE_SERVICE_STREAM != ENABLED)                                     \
    &&  (VSF_USE_SERVICE_VSFSTREAM != ENABLED)
#   error "VSF_USE_SERVICE_STREAM or VSF_USE_SERVICE_VSFSTREAM must be enabled to use VSF_USBD_CFG_STREAM_EN"
#endif

#if VSF_USE_USB_HOST == ENABLED
#   if VSF_USE_USB_HOST_ECM == ENABLED
#       undef VSF_USE_USB_HOST_CDC
#       define VSF_USE_USB_HOST_CDC                 ENABLED
#   endif
#endif

/*============================ MACROFIED FUNCTIONS ===========================*/
/*============================ TYPES =========================================*/
/*============================ GLOBAL VARIABLES ==============================*/
/*============================ LOCAL VARIABLES ===============================*/
/*============================ PROTOTYPES ====================================*/



#endif
/* EOF */