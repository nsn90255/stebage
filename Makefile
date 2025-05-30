SRC = src/stebage.c
BIN = stebage

all: stebage

stebage: ${SRC}

	gcc -o stebage ${SRC} -Wall -Werror

clean: ${BIN}
	
	rm ${BIN}
