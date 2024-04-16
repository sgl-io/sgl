#include <math.h>
#include <string.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>


double sgl_sqrt(uint32_t x)
{
    if( x==0 )
        return 0;
    double xk = 1, xk1 = 0; 
    double err = 1e-6; // err为误差，1e-6就是1乘10的-6次幂
    
    while( abs(xk-xk1) > err ) //循环退出的条件是真正解与近似解的误差进入允许的范围
    {
        xk1 = xk;
        xk = ( xk + x/xk )/2; //迭代公式
    }
    return xk;
}

int main(void)
{
    FILE *file; // 文件指针
    file = fopen("sqrt_data.txt", "w"); // 打开/创建文件 output.txt，以写入模式
    int border;
    int count=0;
    if (file == NULL) {
        printf("无法打开文件\n");
        return -1;
    }
    for(int i=0;i<=200;i++) {
        fprintf(file, "%d,", (uint32_t)(sgl_sqrt(i)+0.5));
    }
    fclose(file); // 关闭文件
    return 0;
}