#include <iostream>
#include <string>


class CharStack
{
public:
    const int MAX_DEPTH = 10;
    int depth;
    char* data;
    CharStack()
    {
        this->depth = 0;
        this->data = new char[MAX_DEPTH];
    }
    std::string to_string()
    {
        std::string result = "";
        for (int i = 0; i < depth; i ++)
            result += this->data[i];
        return result;
    }
    bool push(char c)
    {
        if (this->depth == this->MAX_DEPTH)
        {
            std::cout << "Stack full." << std::endl;
            return false;
        }
        this->data[this->depth] = c;
        this->depth ++;
        return true;
    }
    char pop()
    {
        if (this->depth == 0)
        {
            std::cout << "Nothing to pop." << std::endl;
            return '\0';
        }
        char c = this->data[this->depth - 1];
        this->depth --;
        return c;
    }
};
int main()
{
    CharStack tempStack;
    for (char i = 'a'; i < 'm'; i ++)
    {
        tempStack.push(i);
        std::cout << "The current stack is: " << tempStack.to_string() << std::endl;
    }
    char tempChar;
    for (int i = 0; i < 12; i ++)
    {
        tempChar = tempStack.pop();
        std::cout << "Poped: " << tempChar << std::endl;
        std::cout << "The current stack is: " << tempStack.to_string() << std::endl;
    }
    return 0;
}