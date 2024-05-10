DEBUG_FLAG = -O -g -Wall -Wextra -Werror
PROD_FLAG = -O3

debug: main.o map.o map.cpp main.cpp map.hpp main.hpp
	g++ -o map_debug $(DEBUG_FLAG) main.o map.o

main.o : main.cpp main.hpp
	g++ -c -o main.o main.cpp 

map.o : map.cpp map.hpp
	g++ -c -o map.o map.cpp 

prod : main.o map.o
	g++ -o map_prod $(PROD_FLAG) main.o map.o

clean : 
	rm -rf *.o map_debug map_prod 
