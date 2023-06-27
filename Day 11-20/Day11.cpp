#include <iostream>
#include <string>
const int MAX_LENGTH = 10;  // the max length of the list.
class SequentialList
{
public:
    int length;
    int* data;
    SequentialList()
    {
        // the first constructor
        this->data = new int[MAX_LENGTH];
    }
    SequentialList(int* temp_array, int length)
    {
        // the second constructor
        this->data = new int[MAX_LENGTH];
        this->length = length;
        for (int i = 0; i < this->length; i ++)
            this->data[i] = temp_array[i];
    }
    ~SequentialList()
    {
        delete []data;
    }
    std::string to_string()
    {
        if (this->length == 0) return "empty";
        std::string result = "" + std::to_string(this->data[0]);
        for (int i = 1; i < this->length; i ++)
            result += ", " + std::to_string(this->data[i]);
        return result;
    }
    void reset()
    {
        // reset to empty
        this->length = 0;
    }
};
int main()
{
    int tempArray[4] = {1, 4, 6, 9};
    SequentialList tempFirstList(tempArray, 4);
    std::cout << "Initialized, the list is: " << tempFirstList.to_string() << std::endl;
    std::cout << "Again, the list is: " << tempFirstList.to_string() << std::endl;

    tempFirstList.reset();
    std::cout << "After reset, the list is: " << tempFirstList.to_string() << std::endl;
    return 0;
}