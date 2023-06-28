# Day 11-20

This part is the implementation of [日撸 Java 三百行（11-20天，线性数据结构）](https://blog.csdn.net/minfanphd/article/details/116974461).

## Day 11: 顺序表(一)

实现一个顺序表——SequentialList 类, 类的描述如下: 

*   成员变量 length 用于记录表的长度; 
*   成语变量 data[] 用于存储表的数据; 
*   成员函数 to_string() 用于将 data[] 中的数据转换成 string; 
*   成员函数 reset() 用于将表置空.

```cpp
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
```

output:

>   Initialized, the list is: 1, 4, 6, 9
>   Again, the list is: 1, 4, 6, 9
>   After reset, the list is: empty

## Day 12: 顺序表(二)

实现一个顺序表——SequentialList 类, 类的描述如下: 

*   成员变量 length 用于记录表的长度; 
*   成员变量 data[] 用于存储表的数据; 
*   成员函数 to_string() 用于将 data[] 中的数据转换成 string; 
*   成员函数 reset() 用于将表置空; 
*   成员函数 index_of 用于求指定元素的位置, 找不到返回 -1; 
*   成员函数 insert() 用于向指定位置插入元素, 若表满或指定位置不在范围内则插入失败, 可以在第一个元素的前面或最后一个元素的后面插入元素; 
*   成员函数 delete_value() 删除指定位置的元素, 该位置在删除时必须存在元素, 否则不合法.

```cpp
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
```

output:

>   Initialized, the list is: 1, 4, 6, 9
>   Again, the list is: 1, 4, 6, 9
>   The position of 4 is 1
>   The position of 5 is -1
>   The position 5 is out of bounds.
>   After inserting 2 to position 5, the list is: 1, 4, 6, 9
>   The position 10 is out of bounds.
>   After inserting 8 to position 10, the list is: 1, 4, 6, 9
>   After deleting data at position 3, the list is: 1, 4, 6
>   After inserting 0 to position 0, the list is: 0, 1, 4, 6
>   After inserting 1 to position 1, the list is: 0, 1, 1, 4, 6
>   After inserting 2 to position 2, the list is: 0, 1, 2, 1, 4, 6
>   After inserting 3 to position 3, the list is: 0, 1, 2, 3, 1, 4, 6
>   After inserting 4 to position 4, the list is: 0, 1, 2, 3, 4, 1, 4, 6
>   After inserting 5 to position 5, the list is: 0, 1, 2, 3, 4, 5, 1, 4, 6
>   After inserting 6 to position 6, the list is: 0, 1, 2, 3, 4, 5, 6, 1, 4, 6
>   List full.
>   After inserting 7 to position 7, the list is: 0, 1, 2, 3, 4, 5, 6, 1, 4, 6
>   After reset, the list is: empty

## Day 13: 链表

实现一个链表——LinkedList 类, 支持以下操作:

*   初始化链表
*   插入节点
*   删除节点
*   将链表转换为 string

```cpp
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
```

output:

>   Initialized, the list is: empty
>   Inserted, the list is: 4, 3, 2, 1, 0
>   The position 6 is illegal.
>   Deleted, the list is: 4, 3, 1
>   Deleted, the list is: 3, 1
>   Looped delete, the list is: 1
>   Looped delete, the list is: empty
>   Cannot delete an element from an empty list.
>   Looped delete, the list is: empty
>   Cannot delete an element from an empty list.
>   Looped delete, the list is: empty
>   Cannot delete an element from an empty list.
>   Looped delete, the list is: empty

## Day 14: 栈

实现一个栈——CharStack 类, 支持以下操作:

*   push, 从栈顶推入元素
*   pop, 从栈顶弹出元素

```cpp
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
```

>   The current stack is: a
>   The current stack is: ab
>   The current stack is: abc
>   The current stack is: abcd
>   The current stack is: abcde
>   The current stack is: abcdef
>   The current stack is: abcdefg
>   The current stack is: abcdefgh
>   The current stack is: abcdefghi
>   The current stack is: abcdefghij
>   Stack full.
>   The current stack is: abcdefghij
>   Stack full.
>   The current stack is: abcdefghij
>   Poped: j
>   The current stack is: abcdefghi
>   Poped: i
>   The current stack is: abcdefgh
>   Poped: h
>   The current stack is: abcdefg
>   Poped: g
>   The current stack is: abcdef
>   Poped: f
>   The current stack is: abcde
>   Poped: e
>   The current stack is: abcd
>   Poped: d
>   The current stack is: abc
>   Poped: c
>   The current stack is: ab
>   Poped: b
>   The current stack is: a
>   Poped: a
>   The current stack is: 
>   Nothing to pop.
>   Poped: 
>   The current stack is: 
>   Nothing to pop.
>   Poped: 
>   The current stack is: 

## Day 15: 栈的应用(括号匹配)

括号匹配问题: 检查一个字符串的括号是否匹配. 所谓匹配, 是指每个左括号有相应的一个右括号与之对应, 且左括号不可以出现在右括号右边. 可以修改测试字符串, 检查不同情况下的运行.

```cpp
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
bool bracket_matching(std::string str)
{
    CharStack stack;
    stack.push('#');
    char tempChar, tempPopedChar;
    for (int i = 0; str[i] != '\0'; i ++)
    {
        tempChar = str[i];
        switch (tempChar)
        {
        case '(':
        case '[':
        case '{':
            stack.push(tempChar);
            break;
        case ')':
            tempPopedChar = stack.pop();
            if (tempPopedChar != '(') return false;
            break;
        case ']':
            tempPopedChar = stack.pop();
            if (tempPopedChar != '[') return false;
            break;
        case '}':
            tempPopedChar = stack.pop();
            if (tempPopedChar != '{') return false;
            break;
        default:
            break;
        }
    }
    tempPopedChar = stack.pop();
    if (tempPopedChar != '#') return false;
    return true;
}
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

    bool tempMatch;
    std::string tempExpression = "[2 + (1 - 3) * 4]";
    tempMatch = bracket_matching(tempExpression);
    std::cout << "Is the expression " << tempExpression << " bracket matching? " << (tempMatch == true ? "true." : "false.") << std::endl;

    tempExpression = "( ) )";
    tempMatch = bracket_matching(tempExpression);
    std::cout << "Is the expression " << tempExpression << " bracket matching? " << (tempMatch == true ? "true." : "false.") << std::endl;
    
    tempExpression = "()()(())";
    tempMatch = bracket_matching(tempExpression);
    std::cout << "Is the expression " << tempExpression << " bracket matching? " << (tempMatch == true ? "true." : "false.") << std::endl;
    
    tempExpression = "({}[])";
    tempMatch = bracket_matching(tempExpression);
    std::cout << "Is the expression " << tempExpression << " bracket matching? " << (tempMatch == true ? "true." : "false.") << std::endl;
    
    tempExpression = ")(";
    tempMatch = bracket_matching(tempExpression);
    std::cout << "Is the expression " << tempExpression << " bracket matching? " << (tempMatch == true ? "true." : "false.") << std::endl;

    return 0;
}
```

output:

>   The current stack is: a
>   The current stack is: ab
>   The current stack is: abc
>   The current stack is: abcd
>   The current stack is: abcde
>   The current stack is: abcdef
>   The current stack is: abcdefg
>   The current stack is: abcdefgh
>   The current stack is: abcdefghi
>   The current stack is: abcdefghij
>   Stack full.
>   The current stack is: abcdefghij
>   Stack full.
>   The current stack is: abcdefghij
>   Poped: j
>   The current stack is: abcdefghi
>   Poped: i
>   The current stack is: abcdefgh
>   Poped: h
>   The current stack is: abcdefg
>   Poped: g
>   The current stack is: abcdef
>   Poped: f
>   The current stack is: abcde
>   Poped: e
>   The current stack is: abcd
>   Poped: d
>   The current stack is: abc
>   Poped: c
>   The current stack is: ab
>   Poped: b
>   The current stack is: a
>   Poped: a
>   The current stack is: 
>   Nothing to pop.
>   Poped: 
>   The current stack is: 
>   Nothing to pop.
>   Poped: 
>   The current stack is: 
>   Is the expression [2 + (1 - 3) * 4] bracket matching? true.
>   Is the expression ( ) ) bracket matching? false.
>   Is the expression ()()(()) bracket matching? true.
>   Is the expression ({}[]) bracket matching? true.
>   Is the expression )( bracket matching? false.

## Day 16: 递归

实现递归求和, 递归求 fibonacci 数列前 n 项和.

```cpp
#include <iostream>

int sum_to_n(int n)
{
    if (n <= 0) return 0;
    return n + sum_to_n(n - 1);
}

int fibonacci(int n)
{
    if (n <= 0) return 0;
    if (n == 1) return 1;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main()
{
    int tempValue = 5;
    std::cout << "0 sum to " << tempValue << " = " << sum_to_n(tempValue) << std::endl;

    tempValue = -1;
    std::cout << "0 sum to " << tempValue << " = " << sum_to_n(tempValue) << std::endl;

    for (int i = 0; i < 10; i ++)
    {
        std::cout << "Fibonacci " << i << ": " << fibonacci(i) << std::endl;
    }

    return 0;
}
```

output

>   0 sum to 5 = 15
>   0 sum to -1 = 0
>   Fibonacci 0: 0
>   Fibonacci 1: 1
>   Fibonacci 2: 1
>   Fibonacci 3: 2
>   Fibonacci 4: 3
>   Fibonacci 5: 5
>   Fibonacci 6: 8
>   Fibonacci 7: 13
>   Fibonacci 8: 21
>   Fibonacci 9: 34

## Day 17: 链队列

用链表实现一个队列, 其中入队仅操作链尾, 出队仅操作链头.

```cpp
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
```

output:

>   Initialized, the queue is: empty
>   Push, the queue is:1, 2, 3, 4, 5
>   Pop, the queue is: 2, 3, 4, 5
>   Looped pop 2, the new queue is: 3, 4, 5
>   Looped pop 3, the new queue is: 4, 5
>   Looped pop 4, the new queue is: 5
>   Looped pop 5, the new queue is: empty
>   No element in the queue.
>   Looped pop -1, the new queue is: empty
>   Push, the queue is: 10, 11, 12

## Day 18: 循环队列

使用数组实现循环队列, 其中 head 指向循环队列的第一个元素, tail 指向循环队列的最后一个元素的下一个位置.

```cpp
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
```

output:

>   Initialized, the list is: empty
>   Push, the queue is: 1, 2, 3, 4, 5
>   Pop 1, the queue is: 2, 3, 4, 5
>   Push, the queue is: 2, 3, 4, 5, 10
>   Push, the queue is: 2, 3, 4, 5, 10, 11
>   Push, the queue is: 2, 3, 4, 5, 10, 11, 12
>   Push, the queue is: 2, 3, 4, 5, 10, 11, 12, 13
>   Push, the queue is: 2, 3, 4, 5, 10, 11, 12, 13, 14
>   Queue full.
>   Push, the queue is: 2, 3, 4, 5, 10, 11, 12, 13, 14
>   Pop 2, the queue is: 3, 4, 5, 10, 11, 12, 13, 14
>   Pop 3, the queue is: 4, 5, 10, 11, 12, 13, 14
>   Pop 4, the queue is: 5, 10, 11, 12, 13, 14
>   Push, the queue is: 5, 10, 11, 12, 13, 14, 100
>   Push, the queue is: 5, 10, 11, 12, 13, 14, 100, 101
>   Push, the queue is: 5, 10, 11, 12, 13, 14, 100, 101, 102
>   Queue full.
>   Push, the queue is: 5, 10, 11, 12, 13, 14, 100, 101, 102
>   Queue full.
>   Push, the queue is: 5, 10, 11, 12, 13, 14, 100, 101, 102
>   Queue full.
>   Push, the queue is: 5, 10, 11, 12, 13, 14, 100, 101, 102

使用类模板存储 char 类型的数据

```cpp
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
```

output:

>   Initialized, the list is: empty
>   Push, the queue is: 0, 1, 2, 3, 4
>   Pop 0, the queue is: 1, 2, 3, 4
>   Push, the queue is: 1, 2, 3, 4, a
>   Push, the queue is: 1, 2, 3, 4, a, b
>   Push, the queue is: 1, 2, 3, 4, a, b, c
>   Push, the queue is: 1, 2, 3, 4, a, b, c, d
>   Push, the queue is: 1, 2, 3, 4, a, b, c, d, e
>   Pop 1, the queue is: 2, 3, 4, a, b, c, d, e
>   Pop 2, the queue is: 3, 4, a, b, c, d, e
>   Pop 3, the queue is: 4, a, b, c, d, e
>   Push, the queue is: 4, a, b, c, d, e, A
>   Push, the queue is: 4, a, b, c, d, e, A, B
>   Push, the queue is: 4, a, b, c, d, e, A, B, C
>   Queue full.
>   Push, the queue is: 4, a, b, c, d, e, A, B, C
>   Queue full.
>   Push, the queue is: 4, a, b, c, d, e, A, B, C

## Day 19: 字符串匹配

实现一个 MyString 类用于处理字符串, 实现字符串的暴力匹配匹配算法, 实现获取子串的函数并检查边界.

```cpp
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
```

output:

>   The position of "ik" in "I like it." is: 3
>   The position of "ki" in "I like it." is: -1
>   The substring is: " l"
>   The substring is: "e it."
>   The bound is exceeded.
>   The substring is: ""

## Day 20: 小结

Q1: 面向对象与面向过程相比, 有哪些优势? 注: 第 1 - 10 天的程序, 就是面向过程的.

A1: 面向对象更加容易在修改和添加新的功能, 当需要实现新的需求时只需要在原来的类的基础上添加对应的成员函数即可. 并且, 面向对象的复用性更高, 例如存储不同数据类型的矩阵可以用模板类的方法实现.

Q2: 比较顺序表和链表的异同.

A2: 逻辑上顺序表中的数据是连续存放的, 而链表中的数据则不一定. 顺序表适合在已经确定了元素最大数量的情况下使用, 而链表适合在元素数量不确定的情况下使用.

Q3: 分析顺序表和链表的优缺点.

A3: 顺序表的存取速度快, 可以直接使用下标访问, 但是插入和删除元素时需要移动多个元素. 链表是在程序运行的过程中动态的分配空间, 插入和删除数据的时候快, 但是访问指定位置的元素时需要遍历链表的部分节点.

Q4: 分析调试程序常见的问题及解决方案.

A4: 

Q5: 分析链队列与循环队列的优缺点.

A5: 

Q6: 第 18 天建立的两个队列, 其区别仅在于基础数据不同, 一个是 int, 一个是 char. 按这种思路, 对于不同的基础数据类型, 都需要重写一个类, 这样合理吗? 你想怎么样?

A6: 

