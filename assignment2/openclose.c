#include <linux/fs.h>
#include "h/init.h"
#include "h/openclose.h"

int isOpen = 0;

int device_open(struct inode *inode, struct file *file)
{
	if(isOpen > 0)
	{
		printk(KERN_INFO "Device already Opened\n");
		return 0;
	}
	isOpen++;
	printk(KERN_INFO "Device Opened\n");
	return 1;
}

int device_release(struct inode *inode, struct file *file)
{
	if(isOpen > 0)
	{
		isOpen--;
		printk(KERN_INFO "Device Released\n");
		return 1;
	}
	printk(KERN_INFO "Device already Released\n");
	return 0;
}
