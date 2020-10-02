#include <iostream>
#include <unistd.h>
#include <sys/types.h>

#ifndef FIFO_H
#define FIFO_H

extern int32_t gSharedVariable;
const int FIFO_SIZE = 5;

class Fifo{
    public:
        Fifo()
        {
            count = 0;
        }

        int get()
        {
            // return buffer[0];
            if(!is_empty())
            {
                int first = buffer[0];
                std::cout << "Getting ";
                std::cout << buffer[0] << std::endl;
                std::cout << "The buffer is:" << std::endl;
                for(int i = 0; i < count; i++){
                    buffer[i] = buffer[i + 1];
                    std::cout << buffer[i] << std::endl;
                }
                std::cout << "Da end" << std::endl;
                highest--;
                count--;
                return first;
            }
            else
            {
                // Serial.println("Something wrong reached end of buffer");
                std::cout << "Something wrong reached end of buffer" <<std::endl;
                return 0;
            }   
        }

        void put(int item)
        {
            if(!is_full())
            {
                buffer[count] = item;
                // Serial.println(buffer[count]);
                std::cout << buffer[count] << std::endl;
                count++;
                highest++;  
            }
            else
            {
                std::cout << "Queue is full !" << std::endl;
            }  
        }

        bool is_empty()
        {
            std::cout<<count<<std::endl;
            return (count == 0);
        }

        bool is_full()
        {
            return (count == FIFO_SIZE);
        }

        void reset()
        {
            while(!is_empty())
            {
                get();
            }
            highest = 0;
            lowest = 0;
            count = 0;
        }

    private:
        int count;
        int buffer[FIFO_SIZE];
        int highest = 0;
        int lowest = 0;
};

#endif // FIFO_H