#include <iostream>
#include <string>

class LinkedQueue
{
public:
    class Node
    {
    public:
        int data;
        Node* next;
        Node(): next(NULL){}
        Node(int value): data(value), next(NULL){}
    };
    Node* head;
    Node* tail;
    LinkedQueue()
    {
        head = new Node(-1);
        tail = head;
    }
    void push(int value)
    {
        Node* tempNode = new Node(value);
        tail->next = tempNode;
        tail = tempNode;
    }
    int pop()
    {
        if (this->head == this->tail)
        {
            std::cout << "No element in the queue." << std::endl;
            return -1;
        }
        int result = this->head->next->data;
        Node* temp = this->head->next;
        this->head->next = this->head->next->next;
        delete temp;
        if (this->head->next == NULL)
        {
            this->tail = this->head;
        }
        return result;
    }
    std::string to_string()
    {
        std::string result = "";
        if (this->head->next == NULL)
        {
            return "empty";
        }
        Node* tempNode = this->head->next;
        while (tempNode != NULL)
        {
            result += std::to_string(tempNode->data);
            tempNode = tempNode->next;
            if (tempNode != NULL) result += ", ";
        }
        return result;
    }
};
int main()
{
    LinkedQueue tempQueue;
    std::cout << "Initialized, the queue is: " << tempQueue.to_string() << std::endl;

    for (int i = 0; i < 5; i ++)
    {
        tempQueue.push(i + 1);
    }
    std::cout << "Push, the queue is:" << tempQueue.to_string() << std::endl;

    tempQueue.pop();
    std::cout << "Pop, the queue is: " << tempQueue.to_string() << std::endl;

    int tempValue;
    for (int i = 0; i < 5; i ++)
    {
        tempValue = tempQueue.pop();
        std::cout << "Looped pop " << tempValue << ", the new queue is: " << tempQueue.to_string() << std::endl;
    }

    for (int i = 0; i < 3; i ++)
    {
        tempQueue.push(i + 10);
    }
    std::cout << "Push, the queue is: " << tempQueue.to_string() << std::endl;

    return 0;
}