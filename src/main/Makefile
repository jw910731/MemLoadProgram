CC=gcc
OBJDIR:=$(shell [ -d ../../obj/src/main ] || mkdir -p ../../obj/src/main && echo "../../obj/src/main")
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