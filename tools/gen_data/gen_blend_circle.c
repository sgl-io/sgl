#include <math.h>
#include <string.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#define MAX_RADIUS    256

uint8_t blend_data[MAX_RADIUS*2][MAX_RADIUS*2];
uint16_t blend_index[MAX_RADIUS];

//render left top
#define SGL_RENDER_ROUND_EDGE_LT(cx1, cy1, x, y, factor) \
blend_data[cx1-y][cy1-x] =  factor; \
blend_data[cx1-x][cy1-y] = factor;

//render right top
#define SGL_RENDER_ROUND_EDGE_RT(cx2, cy1, x, y, factor) \
blend_data[cx2+y-1][cy1-x]=factor; \
blend_data[cx2+x-1][cy1-y]= factor;

//render left bottom
#define SGL_RENDER_ROUND_EDGE_LB(cx1, cy2, x, y, factor) \
blend_data[cx1-y][cy2+x-1]=factor; \
blend_data[cx1-x][cy2+y-1]=factor;

//render right bottom
#define SGL_RENDER_ROUND_EDGE_RB(cx2, cy2, x, y, factor) \
blend_data[cx2+y-1][cy2+x-1]=factor;  \
blend_data[cx2+x-1][cy2+y-1]=factor;

static uint16_t tab_index=2;

int sgl_draw_blend_data(int16_t cx, int16_t cy, int r)
{
    int f = 1 - r;
    int diameter = 2*r;
    int ddF_x = 0;
    int ddF_y = - diameter;
    int y = 0;
    int x = r;
    int factor;
    while(y < x) {
        if(f >= 0) {
            x--;
            ddF_y += 2;
            f += ddF_y;
        }
        y++;
        ddF_x += 2;
        factor = - f * 128 / r;
        SGL_RENDER_ROUND_EDGE_RB(cx, cy, x, y, factor);  
        f += ddF_x + 1;
    }
    return y;
}

int out_data(FILE *file, int r) {
    int border;
    int count=0;
    border = sgl_draw_blend_data(MAX_RADIUS, MAX_RADIUS, r);
    for(int i = 0; i<MAX_RADIUS*2;i++) {
        for(int j = 0; j < MAX_RADIUS*2; j++) {
            if(blend_data[i][j]) 
            {
                count ++;
                tab_index ++;
                fprintf(file, "%3d,", blend_data[i][j]);
                if(count >= border) {
                    tab_index ++;
                    fprintf(file, "%3d,\n", 128);
                    goto end;
                }
            }
        }
    }
end:
    printf("generate r: %d [OK]\n", r);
    return tab_index;
}

void clear_data()
{
    memset(blend_data, 0, MAX_RADIUS*2*MAX_RADIUS*2);
}


int main(void) 
{
    int border;
    int count=0;
    remove("output.txt");
    FILE *file; // 文件指针
    file = fopen("output.txt", "w"); // 打开/创建文件 output.txt，以写入模式
    if (file == NULL) {
        printf("无法打开文件\n");
        return -1;
    }
    fprintf(file, "%d,\n", 0);
    fprintf(file, "%d,%d,\n", 0, 0);
    for(int r = 2; r < MAX_RADIUS; r ++) {
        clear_data();
        blend_index[r] = out_data(file, r) + 1;
    }
    fprintf(file, "\n\n\n");
    for(int i=0;i<MAX_RADIUS;i++) {
        fprintf(file, "%d,", blend_index[i]);
    }
    fclose(file); // 关闭文件
    return 0;
}

