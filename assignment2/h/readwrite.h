#ifndef READWRITE_H
#define READWRITE_H

#include <linux/fs.h>

#define BUFFER_SZ 1024

extern char Devbuf[];

ssize_t device_read(struct file *filp,
                    char *buffer,
                    size_t length,
                    loff_t *offset);

ssize_t device_write(struct file *filp,
                     const char *buffer,
                     size_t length,
                     loff_t *offset);

#endif // READWRITE_H
