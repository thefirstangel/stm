//////////////////////////////////////////////////////////////////////////////////	 
//              ----------------------------------------------------------------
//              GND    电源地
//              VCC  接5V或3.3v电源
//              D0   接PA6（SCL）
//              D1   接PA7（SDA）
//              RES  接PA4
//              DC   接PA5
//                      
//              ----------------------------------------------------------------
//******************************************************************************/

#ifndef __OLED_H
#define __OLED_H	

#include "sys.h"
#include "stdlib.h"	    	
//OLED模式设置
//0:4线串行模式
//1:并行8080模式
#define OLED_MODE 0
#define SIZE 16
#define XLevelL		0x00
#define XLevelH		0x10
#define Max_Column	128
#define Max_Row		64
#define	Brightness	0xFF 
#define X_WIDTH 	128
#define Y_WIDTH 	64	    						  
//-----------------OLED端口定义----------------  					   
#define OLED_CS_Clr()  GPIO_ResetBits(GPIOA,GPIO_Pin_3)//CS
#define OLED_CS_Set()  GPIO_SetBits(GPIOA,GPIO_Pin_3)

#define OLED_RST_Clr() GPIO_ResetBits(GPIOA,GPIO_Pin_4)//RES
#define OLED_RST_Set() GPIO_SetBits(GPIOA,GPIO_Pin_4)

#define OLED_DC_Clr() GPIO_ResetBits(GPIOA,GPIO_Pin_5)//DC
#define OLED_DC_Set() GPIO_SetBits(GPIOA,GPIO_Pin_5)




//PC0~7,作为数据线
#define DATAOUT(x) GPIO_Write(GPIOC,x);//输出  
//使用4线串行接口时使用 

#define OLED_SCLK_Clr() GPIO_ResetBits(GPIOA,GPIO_Pin_6)//CLK
#define OLED_SCLK_Set() GPIO_SetBits(GPIOA,GPIO_Pin_6)

#define OLED_SDIN_Clr() GPIO_ResetBits(GPIOA,GPIO_Pin_7)//DIN
#define OLED_SDIN_Set() GPIO_SetBits(GPIOA,GPIO_Pin_7)

 		     
#define OLED_CMD  0	//写命令
#define OLED_DATA 1	//写数据


//OLED控制用函数
void OLED_WR_Byte(u8 dat,u8 cmd);  // 写数据 命令	 
void OLED_Set_Pos(unsigned char x, unsigned char y);   // 显示位置  x 0~127 ; y0~7 
void OLED_Display_On(void);  // kai xian shi
void OLED_Display_Off(void); //  guan xian shi	   							   		    
void OLED_Init(void);    // 初始化
void OLED_Clear(void);  //   清屏
void OLED_DrawPoint(u8 x,u8 y,u8 t);  //  huadian
void OLED_Fill(u8 x1,u8 y1,u8 x2,u8 y2,u8 dot);  
void OLED_ShowChar(u8 x,u8 y,u8 chr);  // 显示一个字符
void OLED_ShowNum(u8 x,u8 y,u32 num,u8 len,u8 size);  // 显示数字 
void OLED_ShowString(u8 x,u8 y, u8 *p);	   // 显示字符串

void OLED_ShowCHinese(u8 x,u8 y,u8 no);
void OLED_DrawBMP(unsigned char x0, unsigned char y0,unsigned char x1, unsigned char y1,unsigned char BMP[]); // 绘图


#endif  
	 



