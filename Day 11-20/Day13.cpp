#include <iostream>
#include <string>
class LinkedList
{
public:
    struct Node
    {
        int data;
        Node* next;
        Node(): next(NULL){}
        Node(int value): data(value), next(NULL){}
    };
    Node* header;
    LinkedList()
    {
        this->header = new Node(0);
    }
    std::string to_string()
    {
        std::string result = "";
        if (this->header->next == NULL)
        {
            return "empty";
        }
        Node* tempNode = this->header->next;
        while (tempNode != NULL)
        {
            result += std::to_string(tempNode->data);
            tempNode = tempNode->next;
            if (tempNode != NULL) result += ", ";
        }
        return result;
    }
    void reset()
    {
        this->header = NULL;
    }
    int locate(int value)
    {
        Node* tempNode = this->header->next;
        int tempCurrentPosition = 0;
        while (tempNode != NULL)
        {
            if (tempNode->data == value)
            {
                return tempCurrentPosition;
            }
            tempNode = tempNode->next;
            tempCurrentPosition ++;
        }
        return -1;
    }
    bool insert(int position, int value)
    {
        Node* tempNode = this->header;
        Node* newNode;
        for (int i = 0; i < position; i ++)
        {
            if (tempNode->next == NULL)
            {
                std::cout << "The position " << position << " is illegal." << std::endl;
                return false;
            }
            tempNode = tempNode->next;
        }
        newNode = new Node(value);
        newNode->next = tempNode->next;
        tempNode->next = newNode;
        return true;
    }
    bool delete_node(int position)
    {
        if (this->header->next == NULL)
        {
            std::cout << "Cannot delete an element from an empty list." << std::endl;
            return false;
        }
        Node* tempNode = this->header;
        for (int i = 0; i < position; i ++)
        {
            if (tempNode->next == NULL)
            {
                std::cout << "The position " << position << " is illegal." << std::endl;
                return false;
            }
            tempNode = tempNode->next;
        }
        Node* temp = tempNode->next;
        tempNode->next = tempNode->next->next;
        delete temp;
        return true;
    }
};
int main()
{
    LinkedList tempFirstList;
    std::cout << "Initialized, the list is: " << tempFirstList.to_string() << std::endl;

    for (int i = 0; i < 5; i ++)
    {
        tempFirstList.insert(0, i);
    }
    std::cout << "Inserted, the list is: " << tempFirstList.to_string() << std::endl;

    tempFirstList.insert(6, 9);

    tempFirstList.delete_node(4);
    
    tempFirstList.delete_node(2);
    std::cout << "Deleted, the list is: " << tempFirstList.to_string() << std::endl;

    tempFirstList.delete_node(0);
    std::cout << "Deleted, the list is: " << tempFirstList.to_string() << std::endl;

    for (int i = 0; i < 5; i ++)
    {
        tempFirstList.delete_node(0);
        std::cout << "Looped delete, the list is: " << tempFirstList.to_string() << std::endl;
    }

    return 0;
}