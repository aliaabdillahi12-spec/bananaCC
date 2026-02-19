all: bcc
CC=gcc
CFLAGS=-O1
bcc:
	$(CC) $(CFLAGS) bcc.c x86_asm.c -o bcc
