#include <linux/module.h>
#include <linux/kernel.h>

#include "h/init.h"

int init_module()
{
	printk(KERN_INFO "Hello world 1.\n");

	return 0;
}

void cleanup_module()
{
	printk(KERN_INFO "Goodbye world 1.\n");
}
