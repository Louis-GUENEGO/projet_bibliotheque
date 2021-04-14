CC = g++
CFLAGS = -Wall -Wextra
LDFLAGS =
OBJFILES = src/main.o src/livre.o src/ressource.o
TARGET = exe

all: $(TARGET)

$(TARGET): $(OBJFILES)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJFILES) $(LDFLAGS)

clean:
	rm -f $(OBJFILES) $(TARGET) *~
