CC := clang
CGLAGS := -W -O2 -std=c99
SRCS := $(wildcard *.c)
OBJS := $(SRCS:%.c=%.o)
INCLUDES := -I $(wildcard *.h)
PRG := main_prg

all: clean $(PRG)

$(PRG): $(OBJS)
	$(CC) $(CGLAGS) -o $@ $^

%.o: %.c
	$(CC) -c $^

clean:
	rm -rf $(PRG) $(OBJS)

