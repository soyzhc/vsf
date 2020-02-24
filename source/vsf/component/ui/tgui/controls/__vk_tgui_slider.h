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

#ifndef __VK_TGUI_CONTROLS_SLIDER_H__
#define __VK_TGUI_CONTROLS_SLIDER_H__

/*============================ INCLUDES ======================================*/
#include "./__vsf_tgui_controls_common.h"
#include "./vsf_tgui_control.h"

/*! \NOTE: Make sure #include "utilities/ooc_class.h" is close to the class
 *!        definition and there is NO ANY OTHER module-interface-header file
 *!        included in this file
 */

#if     defined(__VK_TGUI_CONTROLS_SLIDER_CLASS_IMPLEMENT)
#   define __PLOOC_CLASS_IMPLEMENT
#   undef __VK_TGUI_CONTROLS_SLIDER_CLASS_IMPLEMENT
#elif   defined(__VK_TGUI_CONTROLS_SLIDER_CLASS_INHERIT)
#   define __PLOOC_CLASS_INHERIT
#   undef __VK_TGUI_CONTROLS_SLIDER_CLASS_INHERIT
#endif   

#include "utilities/ooc_class.h"

/*============================ MACROS ========================================*/
/*============================ MACROFIED FUNCTIONS ===========================*/
/*============================ TYPES =========================================*/

declare_class(__vk_tgui_slider_t)

def_class(__vk_tgui_slider_t,
    
    public_member(
        uint16_t            hwSpeed; 
        uint16_t            hwAcceleration;
    )

    protected_member(
        struct {
            int16_t         iTarget;
            int16_t         iCurrent;
            int16_t         iResidual;
        } tPosition;
    )

    private_member(
        vsf_tgui_timer_t    tSlideTimer;
        vsf_timer_tick_t    tOldTimeTick;
    )

)
end_def_class(__vk_tgui_slider_t)

/*============================ GLOBAL VARIABLES ==============================*/
/*============================ PROTOTYPES ====================================*/

extern
void vk_tgui_slider_init(   __vk_tgui_slider_t *ptSlider, 
                            const vsf_tgui_control_t *ptHost,
                            uint_fast8_t chFrameRatePerSec);

extern 
int_fast16_t vk_tgui_slider_on_timer_event_handler(__vk_tgui_slider_t *ptSlider);

extern
int_fast16_t vk_tgui_slider_location_target_set(  __vk_tgui_slider_t *ptSlider, 
                                                    int_fast16_t iLocation);

extern 
int_fast16_t vk_tgui_slider_location_current_get( __vk_tgui_slider_t *ptSlider);

extern 
int_fast16_t vk_tgui_slider_location_current_set( __vk_tgui_slider_t *ptSlider,
                                                    int_fast16_t iLocation);
#endif
/* EOF */

