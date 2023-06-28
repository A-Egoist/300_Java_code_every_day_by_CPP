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
    int index_of(int value)
    {
        // find the index of the given value
        for (int i = 0; i < this->length; i ++)
            if (value == this->data[i]) return i;
        return -1;
    }
    bool insert(int position, int value)
    {
        // insert a value to a position
        if (this->length == MAX_LENGTH)
        {
            std::cout << "List full." << std::endl;
            return false;
        }
        if (position < 0 || position > length)
        {
            std::cout << "The position " << position << " is out of bounds." << std::endl;
            return false;
        }
        for (int i = this->length; i > position; i --)
            this->data[i] = this->data[i - 1];
        this->data[position] = value;
        this->length ++;
        return true;
    }
    bool delete_value(int position)
    {
        if (position < 0 || position >= this->length)
        {
            std::cout << "The position " << position << " is out of bounds." << std::endl;
            return false;
        }
        for (int i = position; i < this->length - 1; i ++)
            this->data[i] = this->data[i + 1];
        this->length --;
        return true;
    }
};
int main()
{
    int tempArray[4] = {1, 4, 6, 9};
    SequentialList tempFirstList(tempArray, 4);
    std::cout << "Initialized, the list is: " << tempFirstList.to_string() << std::endl;
    std::cout << "Again, the list is: " << tempFirstList.to_string() << std::endl;

    int tempValue = 4;
    int tempPosition = tempFirstList.index_of(tempValue);
    std::cout << "The position of " << tempValue << " is " << tempPosition << std::endl;
    
    tempValue = 5;
    tempPosition = tempFirstList.index_of(tempValue);
    std::cout << "The position of " << tempValue << " is " << tempPosition << std::endl;

    tempValue = 2;
    tempPosition = 5;
    tempFirstList.insert(tempPosition, tempValue);
    std::cout << "After inserting " << tempValue << " to position " << tempPosition << ", the list is: " << tempFirstList.to_string() << std::endl;
    
    tempValue = 8;
    tempPosition = 10;
    tempFirstList.insert(tempPosition, tempValue);
    std::cout << "After inserting " << tempValue << " to position " << tempPosition << ", the list is: " << tempFirstList.to_string() << std::endl;

    tempPosition = 3;
    tempFirstList.delete_value(tempPosition);
    std::cout << "After deleting data at position " << tempPosition << ", the list is: " << tempFirstList.to_string() << std::endl;

    for (int i = 0; i < 8; i ++)
    {
        tempFirstList.insert(i, i);
        std::cout << "After inserting " << i << " to position " << i << ", the list is: " << tempFirstList.to_string() << std::endl;
    }

    tempFirstList.reset();
    std::cout << "After reset, the list is: " << tempFirstList.to_string() << std::endl;
    return 0;
}