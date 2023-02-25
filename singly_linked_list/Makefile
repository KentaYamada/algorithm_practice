CC := gcc
CGLAGS := -W -O2 -std=c99
SRCS := $(wildcard *.c)
OBJS := $(SRCS:%.c=%.o)
INCLUDES := -I $(wildcard *.h)
PRG := singly_linked_list_main

all: clean $(PRG)

$(PRG): $(OBJS)
	$(CC) $(CGLAGS) -o $@ $^ $(INCLUDES)

%.o: %.c
	$(CC) -c $^

clean:
	rm -rf $(PRG) $(OBJS)
