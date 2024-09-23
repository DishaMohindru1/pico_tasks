#include "pico/stdlib.h"
#include "hardware/adc.h"

#define LED_PIN 15       // Onboard LED pin
#define JOYSTICK_X_PIN 26 // Assuming joystick X-axis is connected to ADC0 (GP26)

int main() {
    // Initialize stdio and the LED pin
    stdio_init_all();
    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);

    // Initialize ADC for joystick
    adc_init();
    adc_gpio_init(JOYSTICK_X_PIN); // Initialize ADC pin for joystick
    adc_select_input(0);           // Select ADC channel 0 (corresponding to GP26)

    // Infinite loop to read the joystick and control the LED
    while (1) {
        // Read the joystick position (analog signal)
        uint16_t joystick_value = adc_read(); // Get 12-bit value (0-4095)

        // Convert the joystick value to a PWM duty cycle (0-255 for 8-bit PWM)
        uint8_t brightness = joystick_value >> 4; // Dividing by 16 to convert to 8-bit

        // Control LED brightness using PWM technique (simple on/off toggling)
        for (int i = 0; i < 255; i++) {
            if (i < brightness) {
                gpio_put(LED_PIN, 1); // Turn LED ON
            } else {
                gpio_put(LED_PIN, 0); // Turn LED OFF
            }
        }

        // Print the LED state and brightness level
        if (brightness > 0) {
            printf("LED is ON, Brightness Level: %d/255\n", brightness);
        } else {
            printf("LED is OFF\n");
        }

        // Add a small delay to avoid too fast toggling
        sleep_ms(500); // Increased delay to make the output readable
    }

    return 0;
}


