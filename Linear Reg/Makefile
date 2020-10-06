
all: main.o cost_func.o grad_desc.o
	g++ main.o cost_func.o grad_desc.o -o linear.exe

main.o: main.cpp
	g++ -c -Wall main.cpp

cost_func.o: cost_func.cpp
	g++ -c -Wall cost_func.cpp

grad_desc.o: grad_desc.cpp
	g++ -c -Wall grad_desc.cpp

clear:
	rm -f *.o linear.exe