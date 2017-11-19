#include "main.h"

#define SWITCH_DELAY 10000000
#define LED1_PIN GPIO_Pin_12
#define LED2_PIN GPIO_Pin_13
#define LED3_PIN GPIO_Pin_14
#define LED4_PIN GPIO_Pin_15

#define ALL_LEDS (LED1_PIN) | (LED2_PIN) | (LED3_PIN) | (LED4_PIN)
#define ALL_LEDS2 GPIO_Pin_8 | GPIO_Pin_9 | GPIO_Pin_10
#define BUTTON_PIN GPIO_Pin_0

int main(void)
{
  GPIO_InitTypeDef  GPIO_InitStructure;

  /* Enable peripheral clock for GPIOD port */
  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);
  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);
  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOE, ENABLE);
  /* Init leds */
  GPIO_InitStructure.GPIO_Pin = ALL_LEDS;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
  GPIO_Init(GPIOD, &GPIO_InitStructure);

  GPIO_InitStructure.GPIO_Pin = ALL_LEDS2;  
  GPIO_Init(GPIOA, &GPIO_InitStructure);

  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
  GPIO_InitStructure.GPIO_Pin = BUTTON_PIN;
  GPIO_Init(GPIOE, &GPIO_InitStructure);

  long ledArr[] = {~GPIO_Pin_8, ~GPIO_Pin_9, ~GPIO_Pin_10};
  int num = 0;
  while (1)
  {
	  int i;

	  /* Switch LED on */
	  //GPIO_SetBits(GPIOD, ALL_LEDS);

          GPIO_ResetBits(GPIOA, ledArr[num % 3]);
          num++;

          GPIO_SetBits(GPIOA, ledArr[num % 3]);
	  for (i=0; i < SWITCH_DELAY; i++)
	  {
	    /* empty cycle */
	  }

	  /* Switch LED off */
	  GPIO_ResetBits(GPIOD, ALL_LEDS);
          GPIO_ResetBits(GPIOA, ledArr[num % 3]);
          num++;
          GPIO_SetBits(GPIOA, ledArr[num % 3]);
	  for (i=0; i < SWITCH_DELAY; i++)
	  {
	    /* empty cycle */
	  }

          uint8_t buttonVal = GPIO_ReadInputDataBit(GPIOE, BUTTON_PIN);

          if(buttonVal){

            GPIO_SetBits(GPIOD, LED1_PIN);
          } else {

            GPIO_ResetBits(GPIOD, LED1_PIN);
          }
  }
}
