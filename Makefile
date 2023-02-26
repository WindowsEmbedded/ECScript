CC = g++ -I./include/
MAKE = make -r
default:
	$(MAKE) complie
complie:
	$(CC) -c ./src/Main.cpp -o ./out/Main.o 
	$(CC) ./out/Main.o -o ./elf/ecs
run:
	$(MAKE) complie
	./elf/ecs
install:
ifeq ($(shell uname -o),Android)
		mv ./elf/ecs /data/data/com.termux/files/usr/bin
else
		mv ./elf/ecs /usr/local/bin
endif