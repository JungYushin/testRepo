CC = gcc
CFLAGS = -W -Wall
TARGET = manager
OBJECTS = main.o user.o menu.o
D_OBJECTS = main_d.o user_d.o menu_d.o

all : $(TARGET)

manager_debug : $(D_OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^

$(TARGET) : $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^

main_d.o : main.c
	$(CC) -DDEBUG_MODE $(CFLAGS) -c -o $@ $^


user_d.o : user.c
	$(CC) -DDEBUG_MODE $(CFLAGS) -c -o $@ $^

menu_d.o : menu.c
	$(CC) -DDEBUG_MODE $(CFLAGS) -c -o $@ $^
clean :
	rm *.o manager manager_debug
