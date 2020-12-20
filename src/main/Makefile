CC=gcc
OBJDIR:=$(shell mktemp -d)
CFLAGS=-Wall -Wextra -std=c11 -O2 -fPIC
LDFLAGS=-shared

P=libmain.so
OBJ=main.o

.PHONY: $(P)

$(P): $(patsubst %, $(OBJDIR)/%, $(OBJ))
	$(CC) $(filter %.o, $^) -o $@ $(LDFLAGS)

$(OBJDIR)/%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -rf $(P)