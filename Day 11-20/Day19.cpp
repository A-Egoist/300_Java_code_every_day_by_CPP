#include <iostream>
#include <string>
#include <stdlib.h>
class MyString
{
public:
    const int MAX_LENGTH = 20;
    int length;
    char* data;
    MyString()
    {
        this->length = 0;
        this->data = new char[MAX_LENGTH];
    }
    MyString(std::string str)
    {
        this->length = str.length();
        this->data = new char[MAX_LENGTH];
        for (int i = 0; i < this->length; i ++)
            this->data[i] = str[i];
    }
    MyString(const MyString& temp)
    {
        // https://blog.csdn.net/weixin_46338291/article/details/117849057
        this->length = temp.length;
        this->data = new char[MAX_LENGTH];
        strcpy(this->data, temp.data);
    }
    ~MyString()
    {
        // std::cout << "destructor" << std::endl;
        delete []this->data;
    }
    std::string to_string()
    {
        std::string result = "";
        for (int i = 0; i < this->length; i ++)
        {
            result += this->data[i];
        }
        return result;
    }
    int locate(MyString str)
    {
        bool tempMatch = false;
        for (int i = 0; i < this->length - str.length + 1; i ++)
        {
            tempMatch = true;
            for (int j = 0; j < str.length; j ++)
            {
                if (this->data[i + j] != str.data[j])
                {
                    tempMatch = false;
                    break;
                }
            }
            if (tempMatch) return i;
        }
        return -1;
    }
    MyString substring(int position, int length)
    {
        MyString result;
        if (position + length > this->length)
        {
            std::cout << "The bound is exceeded." << std::endl;
            return result;
        }
        result.length = length;
        for (int i = 0; i < length; i ++)
        {
            result.data[i] = this->data[position + i];
        }
        return result;
    }
    void operator=(MyString temp)
    {
        this->length = temp.length;
        strcpy(this->data, temp.data);

    }
};
int main()
{
    MyString tempFirstString("I like it.");
    MyString tempSecondString("ik");
    int tempPosition = tempFirstString.locate(tempSecondString);
    std::cout << "The position of \"" << tempSecondString.to_string() << "\" in \"" << tempFirstString.to_string() << "\" is: " << tempPosition << std::endl;

    MyString tempThirdString("ki");
    tempPosition = tempFirstString.locate(tempThirdString);
    std::cout << "The position of \"" << tempThirdString.to_string() << "\" in \"" << tempFirstString.to_string() << "\" is: " << tempPosition << std::endl;

    tempThirdString = tempFirstString.substring(1, 2);
    std::cout << "The substring is: \"" << tempThirdString.to_string() << "\"" << std::endl;

    tempThirdString = tempFirstString.substring(5, 5);
    std::cout << "The substring is: \"" << tempThirdString.to_string() << "\"" << std::endl;

    tempThirdString = tempFirstString.substring(5, 6);
    std::cout << "The substring is: \"" << tempThirdString.to_string() << "\"" << std::endl;

    return 0;
}