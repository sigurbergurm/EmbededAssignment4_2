#For the hello.cpp then run ./hello in terminal to run
# all: hello

# hello:
# 	g++ -o hello src/hello.cpp
#make -B always build 

## all: mutex

## mutex: 
## 	g++ -o mutex -pthread -I include src/mutex.cpp 

output: mutex.o fifo.o decrement.o increment.o
	g++ mutex.o -o output -pthread -I include -I src

mutex.o: src/mutex.cpp
	g++ -c src/mutex.cpp

fifo.o: src/fifo.cpp include/fifo.h
	g++ -c  -pthread -I src -I include src/fifo.cpp

decrement.o: src/decrement.cpp include/decrement.h
	g++ -c  -l include/fifo.o -pthread -I src -I include src/decrement.cpp

increment.o: src/increment.cpp include/increment.h
	g++ -c  -l include/fifo.o -pthread -I src -I include src/increment.cpp

clean:
	rm *.o output