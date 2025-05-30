SRC = src/stebage.c
BIN = stebage

all: stebage

stebage: ${SRC}

	gcc -o stebage ${SRC}  

clean: ${BIN}
	
	rm ${BIN}
