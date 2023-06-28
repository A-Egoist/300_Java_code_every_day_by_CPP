#include <iostream>
#include <string>
template<typename T>
class CircleIntQueue
{
public:
    const int TOTAL_SPACE = 10;
    T* data;
    int head, tail;
    CircleIntQueue()
    {
        this->data = new T[this->TOTAL_SPACE];
        this->head = 0;
        this->tail = 0;
    }
    ~CircleIntQueue()
    {
        delete []data;
    }
    void push(T value)
    {
        if ((this->tail + 1) % this->TOTAL_SPACE == this->head)
        {
            std::cout << "Queue full." << std::endl;
            return;
        }
        this->data[this->tail] = value;
        this->tail = (this->tail + 1) % this->TOTAL_SPACE;
    }
    T pop()
    {
        if (this->head == this->tail)
        {
            std::cout << "No element in the queue." << std::endl;
            return -1;
        }
        T value = data[this->head];
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
            if (std::is_same<T, char>::value) result += this->data[i];
            else result += std::to_string(this->data[i]);
            if ((i + 1) % this->TOTAL_SPACE != this->tail) result += ", ";
        }
        return result;
    }
};
int main()
{
    CircleIntQueue<char> tempQueue;
    std::cout << "Initialized, the list is: " << tempQueue.to_string() << std::endl;

    for (int i = '0'; i < '5'; i ++)
    {
        tempQueue.push(i);
    }
    std::cout << "Push, the queue is: " << tempQueue.to_string() << std::endl;

    char tempValue = tempQueue.pop();
    std::cout << "Pop " << tempValue << ", the queue is: " << tempQueue.to_string() << std::endl;

    for (int i = 'a'; i < 'f'; i ++)
    {
        tempQueue.push(i);
        std::cout << "Push, the queue is: " << tempQueue.to_string() << std::endl;
    }

    for (int i = 0; i < 3; i ++)
    {
        tempValue = tempQueue.pop();
        std::cout << "Pop " << tempValue << ", the queue is: " << tempQueue.to_string() << std::endl;
    }
    for (int i = 'A'; i < 'F'; i ++)
    {
        tempQueue.push(i);
        std::cout << "Push, the queue is: " << tempQueue.to_string() << std::endl;
    }
    return 0;
}