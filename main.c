#include "pico/stdlib.h"

// Define GPIO pins for LEDs
#define LED_PIN_0 7  // Least Significant Bit (LSB)
#define LED_PIN_1 8
#define LED_PIN_2 9
#define LED_PIN_3 10  // Most Significant Bit (MSB)

void display_binary(uint8_t number) {
    // Set each LED according to the bit value in the number
    gpio_put(LED_PIN_0, number & 0b0001);  // LSB
    gpio_put(LED_PIN_1, number & 0b0010);
    gpio_put(LED_PIN_2, number & 0b0100);
    gpio_put(LED_PIN_3, number & 0b1000);  // MSB
}

int main() {
    // Initialize the GPIO subsystem
    stdio_init_all();

    // Initialize GPIO pins for LEDs as outputs
    gpio_init(LED_PIN_0);
    gpio_set_dir(LED_PIN_0, GPIO_OUT);

    gpio_init(LED_PIN_1);
    gpio_set_dir(LED_PIN_1, GPIO_OUT);

    gpio_init(LED_PIN_2);
    gpio_set_dir(LED_PIN_2, GPIO_OUT);

    gpio_init(LED_PIN_3);
    gpio_set_dir(LED_PIN_3, GPIO_OUT);

    uint8_t count = 0;

    while (true) {
        // Display the binary representation of the count
        display_binary(count);

        // Print the binary number to the console (for verification)
        printf("Binary count: %04b\n", count);

        // Increment the count and wrap around at 16 (for 4 LEDs)
        count = (count + 1) % 16;

        // Wait for 1 second before the next count
        sleep_ms(1000);
    }

    return 0;
}
