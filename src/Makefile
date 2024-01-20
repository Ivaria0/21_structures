all: door_struct list_test stack_test

door_struct: dmanager_module.o
	gcc -Wall -Wextra -Werror -o ../build/Quest_1 ../build/dmanager_module.o

list_test: list_test.o list.o
	gcc -Wall -Wextra -Werror -o ../build/Quest_2 ../build/list_test.o ../build/list.o

stack_test: stack_test.o stack.o
	gcc -Wall -Wextra -Werror -o ../build/Quest_3 ../build/stack_test.o ../build/stack.o

dmanager_module.o:
	gcc -Wall -Wextra -Werror -c -o ../build/dmanager_module.o dmanager_module.c

list_test.o:
	gcc -Wall -Wextra -Werror -c -o ../build/list_test.o list_test.c

list.o:
	gcc -Wall -Wextra -Werror -c -o ../build/list.o list.c

stack_test.o:
	gcc -Wall -Wextra -Werror -c -o ../build/stack_test.o stack_test.c

stack.o:
	gcc -Wall -Wextra -Werror -c -o ../build/stack.o stack.c

clean:
	rm -rf *.o ../build/*

rebuild: clean all
