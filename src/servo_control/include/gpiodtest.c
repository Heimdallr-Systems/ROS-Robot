#include <stdio.h>
#include <gpiod.h>
#include <time.h>


const struct timespec adc_timeout = {0, 100000};
int waitStatus;

int main()
{
    struct gpiod_chip *chip;
    struct gpiod_line *line;
    int req, value;

    chip = gpiod_chip_open("/dev/gpiochip0");
    if (!chip)
    {
        return -1;
    }

    line = gpiod_chip_get_line(chip, 194);
    if (!line)
    {
        gpiod_chip_close(chip);
        return -1;
    }

    req = gpiod_line_request_falling_edge_events(line, "gpio_state");
    if (req)
    {
        gpiod_chip_close(chip);
        return -1;
    }
    waitStatus = gpiod_line_event_wait(line, NULL);
    if (waitStatus == 0)
    {
        printf("Timed Out\n");
    }
    else if (waitStatus == -1)
    {
        printf("ERROR\n");
    }
    else
    {

        printf("Falling Edge!\n");
    }

    gpiod_chip_close(chip);
}