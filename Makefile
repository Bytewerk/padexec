output = padexec.$(shell uname -m)

$(output): padexec.c
	c99 *.c -lSDL2 -o $(output)
