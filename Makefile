CC=gcc
OBJDIR:=$(shell mktemp -d)
CFLAGS=-Wall -Wextra -std=c11 -O2
LDFLAGS=-ldl

P=main.out
OBJ=src/main.o src/mem_load.o libmain.o

.PHONY: $(P)

$(P): $(OBJDIR)/src $(patsubst %, $(OBJDIR)/%, $(OBJ))

	$(CC) $(filter %.o, $^) -o $@ $(LDFLAGS)


$(OBJDIR)/libmain.o: src/main/libmain.so
	ld -r -b binary -o $@ $^

src/main/libmain.so:
	$(MAKE) -C src/main

$(OBJDIR)/%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

$(OBJDIR)/src:
	mkdir -p $@

clean:
	$(MAKE) -C src/main clean
	rm -rf $(P)