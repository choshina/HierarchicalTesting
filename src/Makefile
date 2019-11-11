exe:main.o MCTS.o Node.o Parser.o SearchSpace.o mycmaes.o cmaes.o boundary_transformation.o
	g++ -o exe main.o MCTS.o Node.o Parser.o SearchSpace.o mycmaes.o cmaes.o boundary_transformation.o
main.o:main.cpp 
	g++ -c main.cpp
MCTS.o:MCTS.cpp
	g++ -c MCTS.cpp
Node.o:Node.cpp
	g++ -c Node.cpp
Parser.o:Parser.cpp
	g++ -c Parser.cpp
SearchSpace.o:SearchSpace.cpp
	g++ -c SearchSpace.cpp
mycmaes.o:mycmaes.c
	gcc -c mycmaes.c 
cmaes.o:cmaes.c
	gcc -c cmaes.c
boundary_transformation.o:boundary_transformation.c
	gcc -c boundary_transformation.c
clean:
	rm *.o
