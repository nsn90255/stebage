.PHONY: all clean
CC = gcc
CFLAGS = -Wall -Werror
LDFLAGS = -lcjson
SRC = src/stebage.c src/menu.c src/clearLines.c src/printImage.c
BIN = stebage

all: stebage

stebage: ${SRC}

	${CC} -o ${BIN} ${SRC} ${CFLAGS} ${LDFLAGS}

clean:
	
	rm ${BIN}
