#include <stdio.h>
#include <unistd.h>
#include <mraa/aio.h>

#define AIO_PORT 6

int main()
{
    mraa_aio_context aio;
    int value;

    aio = mraa_aio_init(AIO_PORT);

    while (1)
    {
        value = mraa_aio_read(aio);

        printf("ADC Value : %d\n", value);

        sleep(2);
    }

    return 0;
}
