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

#ifndef __VSF_TINY_GUI_V_TEXT_H__
#define __VSF_TINY_GUI_V_TEXT_H__

/*============================ INCLUDES ======================================*/
#include "../vsf_tgui_cfg.h"

#if VSF_USE_TINY_GUI == ENABLED
#include "./vsf_tgui_font.h"
/*============================ MACROS ========================================*/
#ifndef VSF_TGUI_SV_CFG_MULTI_LINE_TEXT
#define VSF_TGUI_SV_CFG_MULTI_LINE_TEXT ENABLED
#endif
/*============================ MACROFIED FUNCTIONS ===========================*/
/*============================ TYPES =========================================*/
/*============================ GLOBAL VARIABLES ==============================*/
/*============================ PROTOTYPES ====================================*/

#if VSF_TGUI_CFG_SAFE_STRING_MODE == ENABLED
extern
vsf_tgui_string_t* vsf_tgui_text_get_line(  vsf_tgui_string_t* ptStringIn,
                                            int16_t *piOffSet,
                                            vsf_tgui_string_t* ptStringOut);
#endif

extern
vsf_tgui_size_t vsf_tgui_text_get_size( const uint8_t chFontIndex, 
                                        vsf_tgui_string_t* ptString,
                                        uint16_t *phwLineCount,
                                        int_fast8_t chInterlineSpace);

extern
uint32_t vsf_tgui_text_get_next(const char* pchString, size_t* ptSize);

extern
void vsf_tgui_text_draw(vsf_tgui_location_t* ptLocation,
                        vsf_tgui_region_t* ptRelativeRegion,
                        vsf_tgui_string_t* ptString,
                        const uint8_t chFontIndex,
                        vsf_tgui_color_t tColor,
                        int_fast8_t chInterLineSpace);

#endif

#endif
/* EOF */
