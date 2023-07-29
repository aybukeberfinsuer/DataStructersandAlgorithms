DerleCalistir: derle bagla calistir

derle: 
	g++ -I "./include" -c ./src/main.cpp -o ./lib/main.o
	g++ -I 	"./include" -c ./src/FileReader.cpp -o ./lib/FileReader.o
	g++ -I "./include" -c ./src/LinkedList.cpp -o ./lib/LinkedList.o
	g++ -I "./include" -c ./src/calculateFunctions.cpp -o ./lib/calculateFunctions.o


bagla:
	g++  ./lib/main.o ./lib/LinkedList.o ./lib/FileReader.o ./lib/calculateFunctions.o -o ./bin/program
 
calistir:
	./bin/program
