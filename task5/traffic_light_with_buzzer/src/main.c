#include <ch32v00x.h>  // Include CH32V003 hardware headers
#include <system_ch32v00x.h>

#define RED_LED GPIO_Pin_0    // PC0 - Red LED
#define YELLOW_LED GPIO_Pin_1 // PC1 - Yellow LED
#define GREEN_LED GPIO_Pin_2  // PC2 - Green LED
#define BUZZER GPIO_Pin_3     // PC3 - Buzzer

void delay_ms(uint32_t ms) {
    for (volatile uint32_t i = 0; i < ms * 8000; i++) {
        __NOP();  // No Operation (ensures delay)
    }
}

void TrafficLight_Init() {
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);  // Enable GPIOC clock

    GPIO_InitTypeDef GPIO_InitStruct;
    GPIO_InitStruct.GPIO_Pin = RED_LED | YELLOW_LED | GREEN_LED | BUZZER;
    GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;  // Push-Pull Output
    GPIO_InitStruct.GPIO_Speed = GPIO_Speed_10MHz;
    GPIO_Init(GPIOC, &GPIO_InitStruct);
}

void beep_buzzer(uint32_t duration) {
    GPIO_SetBits(GPIOC, BUZZER);
    delay_ms(duration);
    GPIO_ResetBits(GPIOC, BUZZER);
    delay_ms(200);
}

void TrafficLight_Run() {
    while (1) {
        // RED ON, YELLOW & GREEN OFF (STOP)
        GPIO_SetBits(GPIOC, RED_LED);
        GPIO_ResetBits(GPIOC, YELLOW_LED | GREEN_LED | BUZZER);
        delay_ms(5000); // Wait 5 seconds

        // YELLOW ON, BUZZER BEEPS, RED & GREEN OFF (READY)
        GPIO_SetBits(GPIOC, YELLOW_LED);
        GPIO_ResetBits(GPIOC, RED_LED | GREEN_LED);
        for (int i = 0; i < 3; i++) {  // Beep 3 times
            beep_buzzer(500);
        }
        delay_ms(2000); // Wait 2 seconds

        // GREEN ON, RED & YELLOW OFF (GO)
        GPIO_SetBits(GPIOC, GREEN_LED);
        GPIO_ResetBits(GPIOC, RED_LED | YELLOW_LED | BUZZER);
        delay_ms(5000); // Wait 5 seconds
    }
}

int main(void) {
    SystemInit();  // Initialize system clock
    TrafficLight_Init();  // Initialize GPIOs
    TrafficLight_Run();  // Run Traffic Light System

    while (1);  // Keep running
}
