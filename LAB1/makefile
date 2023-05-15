CC = gcc
CFLAGS = -Wall -Werror
LIBRARY = libmatrix.a
SRC_DIR = src

all: main

main: main.o $(LIBRARY)
	$(CC) $(CFLAGS) -o main main.o -L. -lmatrix

main.o: $(SRC_DIR)/main.c
	$(CC) $(CFLAGS) -c $(SRC_DIR)/main.c

$(LIBRARY): m_nums.o m_disp.o
	ar rcs $(LIBRARY) m_nums.o m_disp.o

m_nums.o: $(SRC_DIR)/m_nums.c
	$(CC) $(CFLAGS) -c $(SRC_DIR)/m_nums.c

m_disp.o: $(SRC_DIR)/m_disp.c
	$(CC) $(CFLAGS) -c $(SRC_DIR)/m_disp.c

clean:
	rm -f main *.o $(LIBRARY)
