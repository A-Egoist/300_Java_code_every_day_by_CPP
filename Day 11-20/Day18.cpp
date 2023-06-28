#include <iostream>
#include <string>

class CircleIntQueue
{
public:
    const int TOTAL_SPACE = 10;
    int* data;
    int head, tail;
    CircleIntQueue()
    {
        this->data = new int[this->TOTAL_SPACE];
        this->head = 0;
        this->tail = 0;
    }
    ~CircleIntQueue()
    {
        delete []data;
    }
    void push(int value)
    {
        if ((this->tail + 1) % this->TOTAL_SPACE == this->head)
        {
            std::cout << "Queue full." << std::endl;
            return;
        }
        this->data[this->tail] = value;
        this->tail = (this->tail + 1) % this->TOTAL_SPACE;
    }
    int pop()
    {
        if (this->head == this->tail)
        {
            std::cout << "No element in the queue." << std::endl;
            return -1;
        }
        int value = data[this->head];
        this->head = (this->head + 1) % this->TOTAL_SPACE;
        return value;
    }
    std::string to_string()
    {
        std::string result = "";
        if (this->head == this->tail)
        {
            return "empty";
        }
        for (int i = this->head; i != this->tail; i = (i + 1) % this->TOTAL_SPACE)
        {
            result += std::to_string(this->data[i]);
            if ((i + 1) % this->TOTAL_SPACE != this->tail) result += ", ";
        }
        return result;
    }
};
int main()
{
    CircleIntQueue tempQueue;
    std::cout << "Initialized, the list is: " << tempQueue.to_string() << std::endl;

    for (int i = 0; i < 5; i ++)
    {
        tempQueue.push(i + 1);
    }
    std::cout << "Push, the queue is: " << tempQueue.to_string() << std::endl;

    int tempValue = tempQueue.pop();
    std::cout << "Pop " << tempValue << ", the queue is: " << tempQueue.to_string() << std::endl;

    for (int i = 0; i < 6; i ++)
    {
        tempQueue.push(i + 10);
        std::cout << "Push, the queue is: " << tempQueue.to_string() << std::endl;
    }

    for (int i = 0; i < 3; i ++)
    {
        tempValue = tempQueue.pop();
        std::cout << "Pop " << tempValue << ", the queue is: " << tempQueue.to_string() << std::endl;
    }
    for (int i = 0; i < 6; i ++)
    {
        tempQueue.push(i + 100);
        std::cout << "Push, the queue is: " << tempQueue.to_string() << std::endl;
    }
    return 0;
}