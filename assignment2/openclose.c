#include <linux/fs.h>
#include <linux/module.h>
#include "h/init.h"
#include "h/openclose.h"

int isOpen = 0;

int device_open(struct inode *inode, struct file *file)
{
	if(isOpen > 0)
	{
		printk(KERN_WARN "Device already Opened\n");
		return 0;
	}
	isOpen++;
        try_module_get(THIS_MODULE);
	printk(KERN_INFO "Device Opened\n");

	return 1;
}

int device_release(struct inode *inode, struct file *file)
{
	if(isOpen > 0)
	{
		isOpen--;
		module_put(THIS_MODULE);
		printk(KERN_INFO "Device Released\n");
		return 1;
	}
	printk(KERN_WARN "Device already Released\n");
	return 0;
}
