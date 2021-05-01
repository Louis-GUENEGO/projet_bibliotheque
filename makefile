CC = g++
CFLAGS = -Wall  -Wextra
LDFLAGS =
OBJFILES = src/main.o src/livre.o src/ressource.o src/revue.o src/vhs.o src/cd.o src/dvd.o src/resnum.o src/bibliotheque.o
TARGET = exe

all: $(TARGET)

$(TARGET): $(OBJFILES)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJFILES) $(LDFLAGS)

clean:
	rm -f $(OBJFILES) $(TARGET) *~
