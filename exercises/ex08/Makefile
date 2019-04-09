CC=gcc 
CFLAGS=-Wall -I/usr/include/glib-2.0 -I/usr/lib/x86_64-linux-gnu/glib-2.0/include -lglib-2.0
SOURCE1=ex_compile.c
SOURCE2=word_count.c

all:
	gcc -o ex_compile $(SOURCE1) $(CFLAGS) && gcc -o word_count $(SOURCE2) $(CFLAGS)
