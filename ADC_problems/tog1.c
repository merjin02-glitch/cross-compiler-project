#include <stdio.h>
#include <mraa/gpio.h>
#include <unistd.h>

int main()
{
    mraa_gpio_context led1, led2, led3;

    int state1 = 0;
    int state2 = 0;
    int state3 = 0;

    int time1 = 0;
    int time2 = 0;
    int time3 = 0;

    // Initialize LEDs
    led1 = mraa_gpio_init(61);
    led2 = mraa_gpio_init(62);
    led3 = mraa_gpio_init(63);

    if (led1 == NULL || led2 == NULL || led3 == NULL)
    {
        printf("GPIO initialization failed\n");
        return 1;
    }

    // Set LEDs as output
    mraa_gpio_dir(led1, MRAA_GPIO_OUT);
    mraa_gpio_dir(led2, MRAA_GPIO_OUT);
    mraa_gpio_dir(led3, MRAA_GPIO_OUT);

    // Initially OFF
    mraa_gpio_write(led1, 0);
    mraa_gpio_write(led2, 0);
    mraa_gpio_write(led3, 0);

    printf("Three LED Toggle Program Started\n");

    while (1)
    {
        // Wait 100 milliseconds
        usleep(100000);

        time1 += 100;
        time2 += 100;
        time3 += 100;

        // LED1 -> toggle every 1 second
        if (time1 >= 1000)
        {
            state1 = !state1;
            mraa_gpio_write(led1, state1);

            time1 = 0;
        }

        // LED2 -> toggle every 800 milliseconds
        if (time2 >= 800)
        {
            state2 = !state2;
            mraa_gpio_write(led2, state2);

            time2 = 0;
        }

        // LED3 -> toggle every 400 milliseconds
        if (time3 >= 400)
        {
            state3 = !state3;
            mraa_gpio_write(led3, state3);

            time3 = 0;
        }
    }

    mraa_gpio_close(led1);
    mraa_gpio_close(led2);
    mraa_gpio_close(led3);

    return 0;
}
