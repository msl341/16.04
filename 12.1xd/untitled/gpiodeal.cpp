#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "gpiodeal.h"


#define SYSFS_GPIO_DIR  "/sys/class/gpio"
#define MAX_BUF         64

/**
 * function: gpio export
 */
int ss_gpio_export(unsigned int gpio)
{
    int fd, len;
    char buf[MAX_BUF];

    fd = open(SYSFS_GPIO_DIR "/export", O_WRONLY);
    if (fd < 0) {
        perror("gpio/export");
        return fd;
    }

    len = snprintf(buf, sizeof(buf), "%d", gpio);
    write(fd, buf, len);
    close(fd);

    return 0;
}

/**
 * function: gpio unexport
 */
int ss_gpio_unexport(unsigned int gpio)
{
    int fd, len;
    char buf[MAX_BUF];

    fd = open(SYSFS_GPIO_DIR "/unexport", O_WRONLY);
    if (fd < 0) {
        perror("gpio/export");
        return fd;
    }

    len = snprintf(buf, sizeof(buf), "%d", gpio);
    write(fd, buf, len);
    close(fd);
    return 0;
}

/**
 * function:  gpio set direction
 * parameter: out_flag = 1 -- out
 *            out_flag = 0 -- in
 */
int ss_gpio_set_dir(unsigned int gpio, unsigned int out_flag)
{
    int fd;
    char buf[MAX_BUF];

    snprintf(buf, sizeof(buf), SYSFS_GPIO_DIR  "/gpio%d/direction", gpio);

    fd = open(buf, O_WRONLY);
    if (fd < 0) {
        perror("gpio/direction");
        return fd;
    }

    if (out_flag)
        write(fd, "out", 4);
    else
        write(fd, "in", 3);

    close(fd);
    return 0;
}

/**
 * function:  gpio set value
 * parameter: value = 1 -- high
 *            value = 0 -- low
 */
int ss_gpio_set_value(unsigned int gpio, unsigned int value)
{
    int fd;
    char buf[MAX_BUF];

    snprintf(buf, sizeof(buf), SYSFS_GPIO_DIR "/gpio%d/value", gpio);

    fd = open(buf, O_WRONLY);
    if (fd < 0) {
        perror("gpio/set-value");
        return fd;
    }

    if (value)
        write(fd, "1", 2);
    else
        write(fd, "0", 2);

    close(fd);
    return 0;
}

/**
 * function: gpio get value
 */
int ss_gpio_get_value(unsigned int gpio, unsigned int *value)
{
    int fd;
    char buf[MAX_BUF];
    char ch;

    snprintf(buf, sizeof(buf), SYSFS_GPIO_DIR "/gpio%d/value", gpio);

    fd = open(buf, O_RDONLY);
    if (fd < 0) {
        perror("gpio/get-value");
        return fd;
    }

    read(fd, &ch, 1);

    if (ch != '0') {
        *value = 1;
    } else {
        *value = 0;
    }

    close(fd);
    return 0;
}


/**
 * function:  gpio_set edge
 * parameter: edge = "none", "rising", "falling", "both"
 */
int ss_gpio_set_edge(unsigned int gpio, char *edge)
{
    int fd;
    char buf[MAX_BUF];

    snprintf(buf, sizeof(buf), SYSFS_GPIO_DIR "/gpio%d/edge", gpio);

    fd = open(buf, O_WRONLY);
    if (fd < 0) {
        perror("gpio/set-edge");
        return fd;
    }

    write(fd, edge, strlen(edge) + 1);
    close(fd);
    return 0;
}

/**
 * function: gpio open fd
 */
int ss_gpio_open(unsigned int gpio)
{
    int fd;
    char buf[MAX_BUF];

    snprintf(buf, sizeof(buf), SYSFS_GPIO_DIR "/gpio%d/value", gpio);

#ifdef SYS_WIN
    fd = open(buf, O_RDONLY);
#else
    fd = open(buf, O_RDONLY | O_NONBLOCK);
#endif
    if (fd < 0) {
        perror("gpio/fd_open");
    }
    return fd;
}

/**
 * function: gpio close fd
 */
int ss_gpio_close(int fd)
{
    return close(fd);
}


//读Gpio值
int GetGpioValue(int iGpioNum)
{
    int iValue = 0;
    ss_gpio_export(iGpioNum);
    ss_gpio_set_dir(iGpioNum, 0);
    ss_gpio_get_value(iGpioNum, (unsigned int *)&iValue);
    ss_gpio_unexport(iGpioNum);

    return iValue;
}

//写Gpio值
void SetGpioValue(int iGpioNum,int iValue)
{
    ss_gpio_export(iGpioNum);
    ss_gpio_set_dir(iGpioNum, 1);
    ss_gpio_set_value(iGpioNum, iValue);
    ss_gpio_unexport(iGpioNum);
}

