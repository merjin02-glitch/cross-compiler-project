#include <stdio.h>
#include <unistd.h>
#include <mraa/gpio.h>

int main()
{
    mraa_gpio_context sw1, sw2, sw3;
    mraa_gpio_context led1, led2, led3;

    int sw1_state, sw2_state, sw3_state;

    // Initialize switches
    sw1 = mraa_gpio_init(31);
    sw2 = mraa_gpio_init(32);
    sw3 = mraa_gpio_init(41);

    // Initialize LEDs
    led1 = mraa_gpio_init(45);
    led2 = mraa_gpio_init(46);
    led3 = mraa_gpio_init(47);

    // Check GPIO initialization
    if (sw1 == NULL || sw2 == NULL || sw3 == NULL ||
        led1 == NULL || led2 == NULL || led3 == NULL)
    {
        printf("GPIO initialization failed\n");
        return 1;
    }

    // Set switch pins as input
    mraa_gpio_dir(sw1, MRAA_GPIO_IN);
    mraa_gpio_dir(sw2, MRAA_GPIO_IN);
    mraa_gpio_dir(sw3, MRAA_GPIO_IN);

    // Set LED pins as output
    mraa_gpio_dir(led1, MRAA_GPIO_OUT);
    mraa_gpio_dir(led2, MRAA_GPIO_OUT);
    mraa_gpio_dir(led3, MRAA_GPIO_OUT);

    // LEDs initially OFF
    // Active-low: 1 = OFF, 0 = ON
    mraa_gpio_write(led1, 1);
    mraa_gpio_write(led2, 1);
    mraa_gpio_write(led3, 1);

    printf("Switch and LED program started...\n");

    while (1)
    {
        sw1_state = mraa_gpio_read(sw1);
        sw2_state = mraa_gpio_read(sw2);
        sw3_state = mraa_gpio_read(sw3);

        // Switch 1 controls LED 1
        if (sw1_state == 1)
        {
            mraa_gpio_write(led1, 0);   // LED1 ON
        }
        else
        {
            mraa_gpio_write(led1, 1);   // LED1 OFF
        }

        // Switch 2 controls LED 2
        if (sw2_state == 1)
        {
            mraa_gpio_write(led2, 0);   // LED2 ON
        }
        else
        {
            mraa_gpio_write(led2, 1);   // LED2 OFF
        }

        // Switch 3 controls LED 3
        if (sw3_state == 1)
        {
            mraa_gpio_write(led3, 0);   // LED3 ON
        }
        else
        {
            mraa_gpio_write(led3, 1);   // LED3 OFF
        }

        usleep(10000);
    }

    return 0;
}
