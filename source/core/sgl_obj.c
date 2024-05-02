/* source/core/sgl_obj.c
 *
 * MIT License
 *
 * Copyright(c) 2023-present All contributors of SGL  
 *  
 * Email: 1477153217@qq.com
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#include "./sgl_obj.h"
#include "./sgl_device.h"


/**
* @brief Obtain the alignment position of the object, note that the position 
*        here is calculated based on the relative position
*
* @param parent_size       size of parent object
* @param size              size of object
* @param size    The parent of the object
*
* @return sgl_pos_t  The calculated position
*/
sgl_pos_t sgl_get_align_pos(sgl_size_t *parent_size, sgl_size_t *size, sgl_align_type_e type)
{
    sgl_pos_t ret = {.x = 0, .y = 0};
    switch(type) {                
        case SGL_ALIGN_TOP_MID:          
            ret.x = (parent_size->w - size->w)/2;
            ret.y = 0;
        break;

        case SGL_ALIGN_TOP_LEFT:
            ret.x = 0;
            ret.y = 0;
        break; 
            
        case SGL_ALIGN_TOP_RIGHT:    
            ret.x = parent_size->w - size->w;
            ret.y = 0;
        break;

        case SGL_ALIGN_CENTER_MID:
            ret.x = (parent_size->w - size->w)/2;
            ret.y = (parent_size->h - size->h)/2;
        break;
        
        case SGL_ALIGN_CENTER_LEFT:
            ret.x = 0;
            ret.y = (parent_size->h - size->h)/2;
        break;

        case SGL_ALIGN_CENTER_RIGHT:
            ret.x = parent_size->w - size->w ;
            ret.y = (parent_size->h - size->h)/2;
        break;

        case SGL_ALIGN_BOT_LEFT:
            ret.x = 0;
            ret.y = parent_size->h - size->h;
        break;

        case SGL_ALIGN_BOT_MID:
            ret.x = (parent_size->w - size->w)/2;
            ret.y = parent_size->h - size->h;
        break;

        case SGL_ALIGN_BOT_RIGHT:
            ret.x = parent_size->w - size->w;
            ret.y = parent_size->h - size->h;
        break;

        case SGL_ALIGN_TOP: 
            ret.y = 0;
        break;
        case SGL_ALIGN_CENTER: 
            ret.y = (parent_size->h - size->h)/2;
        break;
        case SGL_ALIGN_BOT: 
            ret.y = parent_size->h - size->h;
        break;
        case SGL_ALIGN_LEFT: 
            ret.x = 0;
        break;
        case SGL_ALIGN_MID: 
            ret.x = (parent_size->w - size->w)/2;
        break;
        case SGL_ALIGN_RIGHT: 
            ret.x = parent_size->w - size->w; 
        break;
        default: break;
    }
    return ret;
}
