#ifndef FIFO_H
#define FIFO_H

const int FIFO_SIZE = 5;

class Fifo
{
public:
    Fifo();
    ~Fifo();
    int get();
    void put(int item);
    bool is_empty();
    bool is_full();
    void reset();
    int count;
private:
    int buffer[FIFO_SIZE];
    // add variables pointing to the front and back of the buffer
    int *front;
    int *back;

};

#endif // FIFO_H