#include <linux/device.h>
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

static struct device *dv;
static struct class *cl;

MODULE_LICENSE("GPL");

static int __init init(void)
{
	int Major = register_chrdev(0, DEVICE_NAME, &fops);

	if(Major < 0) // Registering the device failed
	{
		printk(KERN_ERR "Failed to register a device.\n");
		return Major;
	}

	cl = class_create(THIS_MODULE, CLASS_NAME);
	if(IS_ERR(cl))
	{
		unregister_chrdev(Major, DEVICE_NAME);
		printk(KERN_ERR "Failed to register device class.\n");
		return PTR_ERR(cl);
	}

	dv = device_create(cl, NULL, MKDEV(Major, 0), NULL, DEVICE_NAME);
	if(IS_ERR(dv))
	{
		class_destroy(cl);
		unregister_chrdev(Major, DEVICE_NAME);
		printk(KERN_ERR "Failed to create device.\n");
	}

	return 0;
}

static void __exit deinit(void)
{
	device_destroy(cl, MKDEV(Major, 0));
	class_unregister(cl);
	class_destroy(cl);
	// According to
	// https://stackoverflow.com/questions/3237384
	//     /how-to-find-if-unregister-chrdev-call-was-successful
	// unregister_chrdev is always expected to succeed, thus its void signature
	unregister_chrdev(Major, DEVICE_NAME);
}

module_init(init);
module_exit(deinit);
