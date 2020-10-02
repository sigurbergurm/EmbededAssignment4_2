#For the hello.cpp then run ./hello in terminal to run
# all: hello

# hello:
# 	g++ -o hello src/hello.cpp
#make -B always build 

## all: mutex

## mutex: 
## 	g++ -o mutex -pthread -I include src/mutex.cpp 

output: mutex.o fifo.o decrement.h increment.h
	g++ mutex.o -o output -pthread -I include -I src

mutex.o: src/mutex.cpp
	g++ -c src/mutex.cpp

fifo.o: src/fifo.cpp include/fifo.h
	g++ -c src/fifo.cpp include/fifo.h -pthread -I src -I include 

decrement.h: include/decrement.h
	g++ -c  -l include/fifo.h -pthread -I src -I include

increment.h: include/increment.h
	g++ -c  -l include/fifo.h -pthread -I src -I include

clean:
	rm *.o output