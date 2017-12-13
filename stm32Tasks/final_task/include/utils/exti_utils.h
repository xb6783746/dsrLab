#ifndef EXTI_UTILS
#define EXTI_UTILS

/* чтобы можно было в макросы передавать не только числа, но и дефайны*/
#define GET_EXTI_HANDLER_NAME2(n) EXTI ## n ## _IRQHandler
#define GET_EXTI_LINE2(n) EXTI_Line ## n
#define GET_EXTI_PIN_SOURCE2(n) EXTI_PinSource ## n
#define GET_EXTI_IRQ_CHANNEL2(n) EXTI ## n ## _IRQn 

#define GET_EXTI_HANDLER_NAME(n) GET_EXTI_HANDLER_NAME2(n)
#define GET_EXTI_LINE_NAME(n) GET_EXTI_LINE2(n)
#define GET_EXTI_PIN_SOURCE(n) GET_EXTI_PIN_SOURCE2(n)
#define GET_EXTI_IRQ_CHANNEL(n) GET_EXTI_IRQ_CHANNEL2(n)

#endif
