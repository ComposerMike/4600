#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>

#include "h/init.h"

static int __init init()
{
	printk(KERN_INFO "Hello world 1.\n");

	return 0;
}

static void __exit deinit()
{
	printk(KERN_INFO "Goodbye world 1.\n");
}

module_init(init);
module_exit(deinit);
