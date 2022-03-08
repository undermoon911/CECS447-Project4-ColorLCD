// Walk_Man.c
// Runs on TM4C123
// Uses ST7735.c LCD.
// Jonathan Valvano
// August 5, 2015
// Possible main program to test the lab
// Feel free to edit this to match your specifications

// Backlight (pin 10) connected to +3.3 V
// MISO (pin 9) unconnected 
// SCK (pin 8) connected to PA2 (SSI0Clk)
// MOSI (pin 7) connected to PA5 (SSI0Tx)
// TFT_CS (pin 6) connected to PA3 (SSI0Fss)
// CARD_CS (pin 5) unconnected
// Data/Command (pin 4) connected to PA6 (GPIO)
// RESET (pin 3) connected to PA7 (GPIO)
// VCC (pin 2) connected to +3.3 V
// Gnd (pin 1) connected to ground

#include <stdio.h>
#include <stdint.h>
#include "string.h"
#include "ST7735.h"
#include "PLL.h"
#include "walking.h"
#include "tm4c123gh6pm.h"
#include "SysTick.h"



int main(void){
	uint32_t x = 40, ht = 0;	
	uint32_t Lazerx = 127, Lazery = 0,Lazerh=30,Steavex=17,Steavey=99;	
	int32_t l = 15, h = 15;
	int i = 0;
  PLL_Init(12);
  ST7735_InitR(INITR_REDTAB);
	SysTick_Init();
	// DRAW THE GROUND
	ST7735_FillScreen(ST7735_WHITE);
	ST7735_FillRect(0,119,127,40,ST7735_GREEN);
	//step
	ST7735_FillRect(37, 129,30, 30, ST7735_YELLOW);
	ST7735_FillRect(67, 99,30, 60, ST7735_RED);
	ST7735_FillRect(97, 69,38, 90, ST7735_YELLOW);
	
	
	
	STEAVE(17,99,0,ST7735_YELLOW,ST7735_RED,ST7735_BLUE);
	//show the word on the sky
	ST7735_DrawChar(0,0,'L',ST7735_RED,ST7735_MAGENTA,2);
	ST7735_DrawChar(12,0,'O',ST7735_YELLOW,ST7735_MAGENTA,2);
	ST7735_DrawChar(31,0,'o',ST7735_RED,ST7735_MAGENTA,2);
	ST7735_DrawChar(47,0,'K',ST7735_YELLOW,ST7735_MAGENTA,2);
	ST7735_DrawChar(0,20,'U',ST7735_RED,ST7735_WHITE,3);
	ST7735_DrawChar(18,20,'P',ST7735_BLUE,ST7735_WHITE,4);
	while(1){
		while(i < 3){//the line from right top
		SysTick_Wait10ms(50);
		ST7735_DrawLine(Lazerx,Lazery,Lazerx-Lazerh,Lazery+Lazerh,ST7735_BLACK);
		i = i + 1;
		Lazerh = Lazerh + 30;		
		}
		i = 0;
		Lazerh = 30;
		while(i < 3){// clear the line
		SysTick_Wait10ms(50);
		ST7735_DrawLine(Lazerx,Lazery,Lazerx-Lazerh,Lazery+Lazerh,ST7735_WHITE);
		i = i + 1;
		Lazerh = Lazerh + 30;		
		}
		
		i = 0;
		while(i < 5){//jump straight up
			SysTick_Wait10ms(5);
			STEAVE(Steavex,Steavey,0,ST7735_WHITE,ST7735_WHITE,ST7735_WHITE);//clear the old place
			Steavey = Steavey -5;
			STEAVE(Steavex,Steavey,0,ST7735_YELLOW,ST7735_RED,ST7735_BLUE);
			i = i + 1;		
		}
		i = 0;
		while(i < 5){//jump straight down
			SysTick_Wait10ms(5);
			STEAVE(Steavex,Steavey,0,ST7735_WHITE,ST7735_WHITE,ST7735_WHITE);//clear the old place
			Steavey = Steavey +5;
			STEAVE(Steavex,Steavey,0,ST7735_YELLOW,ST7735_RED,ST7735_BLUE);
			i = i + 1;		
		}
	
	}

}
