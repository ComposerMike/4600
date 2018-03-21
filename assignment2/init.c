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

int Major;

int __init init()
{
	int Major = register_chrdev(0, DEVICE_NAME, &fops);

	if(Major < 0) // Registering the device failed
	{
		printk(KERN_ERR "Failed to register a device.\n");
		return Major;
	}

	return 0;
}

void __exit deinit()
{
	// According to
	// https://stackoverflow.com/questions/3237384
	//     /how-to-find-if-unregister-chrdev-call-was-successful
	// unregister_chrdev is always expected to succeed, thus its void signature
	unregister_chrdev(Major, DEVICE_NAME);
}

module_init(init);
module_exit(deinit);
