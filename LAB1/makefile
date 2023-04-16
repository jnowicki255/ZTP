CFLAGS=I.

all: make_lib main clean

make_lib: ./src/m_nums.c ./src/m_disp.c
	gcc -fPIC -c ./src/m_nums.c
	gcc -fPIC -c ./src/m_disp.c
	# gcc -shared -o ./lib/m_lib.so ./src/m_nums.c ./src/m_disp.c
	# gcc -shared -o ./lib/m_lib.so ./m_nums.o ./m_disp.o
	gcc -shared -o m_lib.so ./m_nums.o ./m_disp.o

main: ./src/main.c
	gcc ./src/main.c -L. -lutil -o launch

clean:
	rm -rf *.o