#include <linux/fs.h>
#include "h/init.h"
#include "h/openclose.h"

int device_open(struct inode *inode, struct file *file)
{
	printk(KERN_INFO "Device Opened\n");
	return 0;
}

int device_release(struct inode *inode, struct file *file)
{
	printk(KERN_INFO "Device Released\n");
	return 0;
}
