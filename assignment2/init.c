#include <linux/fs.h>
#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>

#include "h/init.h"

struct file_operations fops = {
	.read = device_read,
	.write = device_write,
	.open = device_open,
	.release = device_release
};

int __init init()
{
	int res = register_chrdev(0, DEVICE_NAME, &fops);

	if(res < 0) // Registering the device failed
	{
		printk(KERN_ERR "Failed to register a device.\n");
		return res;
	}

	return 0;
}

void __exit deinit()
{
	printk(KERN_INFO "Goodbye world!\n");
}

module_init(init);
module_exit(deinit);
