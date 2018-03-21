headers = init.h openclose.h readwrite.h
files = init.c openclose.c readwrite.c
outputfile = as2
zipfile = assignment2.zip

make: $(files) $(addprefix h/,$(headers))
	gcc -g -Wall -o $(outputfile) $(files)

.PHONY: clean zip
clean:
	rm -f $(outputfile) $(zipfile)
zip:
	zip $(zipfile) $(files) $(addprefix h/,$(headers)) Makefile
