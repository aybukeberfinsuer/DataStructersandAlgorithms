DerleCalistir: derle bagla calistir

derle: 
	g++ -I "./include" -c ./src/main.cpp -o ./lib/main.o
	g++ -I 	"./include" -c ./src/Stack.cpp -o ./lib/Stack.o
	g++ -I 	"./include" -c ./src/BinarySearchTree.cpp -o ./lib/BinarySearchTree.o
	g++ -I 	"./include" -c ./src/ListNode.cpp -o ./lib/ListNode.o
	
bagla:
	g++  ./lib/main.o ./lib/Stack.o  ./lib/ListNode.o ./lib/BinarySearchTree.o -o ./bin/program
 
calistir:
	./bin/program
