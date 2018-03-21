#ifndef OPENCLOSE_H
#define OPENCLOSE_H

#include <linux/fs.h>

int device_open(struct inode *inode, struct file *file);
int device_release(struct inode *inode, struct file *file);
extern int isOpen = 0;
#endif // OPENCLOSE_H
