CC = gcc
CFLAGS = -Wall -Werror
LDFLAGS = -lcjson
SRC = src/stebage.c
BIN = stebage

all: stebage

stebage: ${SRC}

	${CC} -o ${BIN} ${SRC} ${CFLAGS} ${LDFLAGS}

clean: ${BIN}
	
	rm ${BIN}
