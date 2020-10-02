#include "../include/fifo.h"
// #include <Arduino.h>
#include <iostream>
#include <unistd.h>
#include <sys/types.h>

extern int32_t gSharedVariable;

Fifo::Fifo()
{
    count = 0;
}
Fifo::~Fifo()
{
    delete front;
    delete back;
}

int Fifo::get()
{
    // return buffer[0];
    if(!is_empty())
    {
        int first = buffer[0];
        std::cout << "Getting ";
        std::cout << buffer[0] << std::endl;
        if(count <= 1)
        {
            *front = buffer[1];
        }
        std::cout << "The buffer is:" << std::endl;
        for(int i = 0; i < count; i++){
            buffer[i] = buffer[i + 1];
            std::cout << buffer[i] << std::endl;
        }
        std::cout << "Da end" << std::endl;

        count--;
        return first;
    }
    else
    {
        // Serial.println("Something wrong reached end of buffer");
        return 0;
    }   
}

void Fifo::put(int item)
{
    if(!is_full())
    {
        buffer[count] = item;
        // Serial.println(buffer[count]);
        std::cout << buffer[count] << std::endl;
        *back = buffer[count];
        if(count == 0)
        {
            *front = buffer[count];
        }
        count++;  
    }
    else
    {
        get();
        put(item);
    }  
}

bool Fifo::is_empty()
{
    return count == 0;
}

bool Fifo::is_full()
{
    return count == FIFO_SIZE;
}

void Fifo::reset()
{
    while(!is_empty())
    {
        get();
    }
    count = 0;
}