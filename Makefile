EXECBIN  = sorting

SOURCES  = $(wildcard *.c)
OBJECTS  = $(SOURCES:%.c=%.o)

CC       = clang
CFLAGS   = -Wall -Wpedantic -Werror -Wextra
LIBFLAGS = -lm

.PHONY: all clean format 

all: $(EXECBIN)

$(EXECBIN): $(OBJECTS)
	$(CC) -o $@ $^ $(LIBFLAGS)

%.o : %.c
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f $(EXECBIN) $(OBJECTS) 

format:
	clang-format -i -style=file *.[ch]
