CC = gcc
CFLAGS = -Wall -Wextra -O2
SRC = server.c
TARGET = server


all: $(TARGET)
$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC) -lws2_32
run: $(TARGET)
	./$(TARGET)
clean:
	del $(TARGET).exe
.PHONY: all run clean serve build-and-run