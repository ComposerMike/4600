modname = chardevice
# List all c files with a .o suffix here
$(modname)-y := init.o openclose.o readwrite.o
obj-m += $(modname).o

all:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules

clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean
