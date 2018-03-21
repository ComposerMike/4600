#include "h/readwrite.h"

ssize_t device_read(struct file *filp,
                    char *buffer,
                    size_t length,
                    loff_t *offset)
{
	return 0;
}

ssize_t device_write(struct file *filp,
                     const char *buffer,
                     size_t length,
                     loff_t *offset)
{
	return 0;
}
