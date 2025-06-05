
## ✅ Test Documentation

### 📁 Project: MSP430 Learning – Phase 2: C Programming + Testing

**Student Name:** Adeyemi Mayowa
**Board:** MSP430 LaunchPad (MSP430G2553)
**Date:** Day 1 to Day 3
**Tools:** Code Composer Studio (CCS), C Language
**Goal:** Learn embedded C in the context of test engineering by completing basic GPIO projects using LED and button interaction.

---

### 🧪 Task 1: Blink LED1 (P1.0)

**Objective:**
Write C code to blink the red LED (P1.0) in a 1-second on/off cycle.
**Test Conditions:**

* LED should toggle on and off every second.
* Visual confirmation on LaunchPad.

**Code Summary:**

```c
P1DIR |= BIT0;          // Configure P1.0 as output
while (1) {
    P1OUT ^= BIT0;      // Toggle LED
    delay_ms(1000);     // 1 second delay
}
```

**Result:** ✅
LED1 blinks on/off every second — working as expected.

---

### 🧪 Task 2: Blink LED1 and LED2 Twice Quickly

**Objective:**
Blink both LEDs (P1.0, P1.6) rapidly two times, then delay.
**Test Conditions:**

* Both LEDs blink twice in fast succession.
* 1-second delay follows.

**Fix Summary:**
Initial code failed due to missing variable declaration (`i`) and incorrect delay function usage. Fixed by declaring the loop variable and adjusting the `delay_ms` function.

**Final Result:** ✅
LED1 and LED2 blink twice quickly, then pause — works correctly.

---

### 🧪 Task 3: Button Input to Control LED1

**Objective:**
Use onboard push button **S2 (P1.3)** to control **LED1 (P1.0)**.
**Behavior:**

* When button is pressed, LED1 turns **on**.
* When button is released, LED1 turns **off**.

**Code Summary:**

```c
P1DIR |= BIT0;       // LED1 as output
P1DIR &= ~BIT3;      // Button as input
P1REN |= BIT3;       // Enable resistor
P1OUT |= BIT3;       // Set pull-up
if ((P1IN & BIT3) == 0) {
    P1OUT |= BIT0;   // LED on
} else {
    P1OUT &= ~BIT0;  // LED off
}
```

**Test Steps:**

* Press and hold S2 → LED1 lights up.
* Release S2 → LED1 turns off.

**Result:** ✅
Button input condition works as expected, tested repeatedly.

---

### 🧾 Lessons Learned

* Always declare loop variables (`int i`) properly.
* Use pull-up resistors when reading active-low buttons.
* Delay functions must match clock configuration.
* C requires explicit setup — no `pinMode()` or `digitalWrite()` like Energia.

---

