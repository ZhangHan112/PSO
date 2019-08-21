all: PSO

PSO: PSO.o main.o 
	g++ -ggdb -O3 -o PSO PSO.o main.o

PSO.o: PSO.cpp
	g++ -ggdb -O3 -c PSO.cpp

main.o: main.cpp
	g++ -ggdb -O3 -c main.cpp

plot: 
	gnuplot pic.gp

dep:
	echo "Do nothing"

clean:
	rm -f PSO PSO *.o

cleanDat:
	rm -f *.dat
