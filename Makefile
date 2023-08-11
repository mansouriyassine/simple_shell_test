CC := gcc
CFLAGS := -Wall -Werror -Wextra -pedantic
TARGET := simple_shell

SRCS := shell.c main.c builtin.c parser.c executor.c utils.c history.c variables.c path.c signals.c error_handling.c
OBJS := $(SRCS:.c=.o)

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)
