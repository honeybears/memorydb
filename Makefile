CC      = clang
CFLAGS  = -g -Wall -Wextra -Isrc
SRCS    = $(wildcard src/*.c)
OBJS    = $(SRCS:.c=.o)
TARGET  = memorydb

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: clean
