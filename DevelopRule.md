## 开发规范
### 函数规范
所有的函数使用小写加下划线的方式命令，所有的函数结构和Linux保持一致，例如下面的函数： 
```C
void sgl_create_button()
{
    ...
    if {

    }else {

    };
    ...
}
```
### 宏规范
所有的宏应该大写，暴露在sgl.h中的宏应该加上SGL_前缀    
例如：    
```C
#define  SGL_CONFIG_PANEL_XRES
```

### 文件命名
所有的文件命名都应该以sgl_前缀开始，并且文件名采用小写加下划线的方式，例如：`sgl_font.h`  

