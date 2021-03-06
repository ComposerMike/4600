#ifndef INIT_H
#define INIT_H

#include <linux/fs.h>
#include <linux/init.h>

#include "openclose.h"
#include "readwrite.h"

#define CLASS_NAME "chd"
#define DEVICE_NAME "chardevice"

extern struct file_operations fops;

extern int Major;

//int __init init(void);
//void __exit deinit(void);

#endif // INIT_H
