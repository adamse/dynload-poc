
.PHONY: run
run: main obj.so
	./main

FLAGS = -Wall -Werror
obj.so: obj.c iface.h
	gcc $(FLAGS) -c -fpic obj.c
	gcc $(FLAGS) -shared -o obj.so obj.o

main: main.c iface.h dynamic_exports.txt
	gcc $(FLAGS) main.c -o main -ldl -Wl,--dynamic-list=dynamic_exports.txt

.PHONY: clean
clean:
	$(RM) main main.o obj.o obj.so
