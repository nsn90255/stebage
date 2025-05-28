SRC = src/stebage.c

all: stebage

stebage: ${SRC}

	gcc -o stebage ${SRC}  
