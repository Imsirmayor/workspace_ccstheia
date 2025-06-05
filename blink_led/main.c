// #include <msp430.h>  // Include device-specific definitions

// void delay_ms(unsigned int ms);

// int main(void) {
//     WDTCTL = WDTPW | WDTHOLD;   // Stop watchdog timer

//     P1DIR |= BIT0;              // Set P1.0 (red LED) as output
//     P1DIR |= BIT6;              // Set P1.6 (green LED) as output
    

//     while (1) {
//         int i;  // ✅ Declare loop variable

//         for (i = 0; i < 2; i++) {
//             P1OUT ^= BIT0;      // Toggle red LED
//             delay_ms(700);      // Short delay
//             P1OUT ^= BIT6;      // Toggle green LED
//             delay_ms(1000);      // Short delay
//         }

//         // Turn both LEDs off (optional)
//         P1OUT &= ~(BIT0 | BIT6);

//         // Pause after 2 quick blinks
//         delay_ms(1000);         // Long delay
//     }
// }

// void delay_ms(unsigned int ms) {
//     while (ms--) {
//         __delay_cycles(1000);  // Approx 1 ms delay at 1 MHz
//     }
// }


#include <msp430.h>

int main(void) {
    WDTCTL = WDTPW | WDTHOLD;   // Stop watchdog timer

    P1DIR |= BIT0;              // Set P1.0 as output (LED1)
    P1DIR &= ~BIT3;             // Set P1.3 as input (Button S2)
    P1REN |= BIT3;              // Enable pull-up/down resistor on P1.3
    P1OUT |= BIT3;              // Pull-up resistor on P1.3 (button not pressed = HIGH)

    while (1) {
        if ((P1IN & BIT3) == 0) {   // If button S2 is pressed (P1.3 = LOW)
            P1OUT |= BIT0;          // Turn ON LED1
        } else {
            P1OUT &= ~BIT0;         // Turn OFF LED1
        }
    }
}
