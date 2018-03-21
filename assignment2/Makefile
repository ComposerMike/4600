modname = chardevice
files = init openclose readwrite

$(modname)-y := $(addsuffix .o,$(files))
obj-m += $(modname).o

all:
	make -C /lib/modules/$(shell uname -r)/build M=$(shell pwd) modules

clean:
	rm -rf $(addprefix $(modname),.ko .mod.c .mod.o .o .ko) \
	       $(addprefix .$(modname),.ko.cmd .mod.o.cmd .o.cmd) \
	       $(addsuffix .o.cmd,$(foreach file,$(files),.$(file))) \
	       $(addsuffix .o,$(files)) \
		   modules.order Module.symvers .tmp_versions/
	make -C /lib/modules/$(shell uname -r)/build M=$(shell pwd) clean
