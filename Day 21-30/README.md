# Day 21-30

This part is the implementation of [日撸 Java 三百行（21-30天，树与二叉树）](https://blog.csdn.net/minfanphd/article/details/116975721).

## Day 21: 二叉树的深度遍历的递归实现

实现一个 BinaryCharTree 类, 并手动构建一个二叉树. 使用递归实现二叉树的前序遍历、中序遍历、后序遍历. 使用递归实现获取二叉树的层数、节点数函数.

<img src="https://amonologue-image-bed.oss-cn-chengdu.aliyuncs.com/202303/202306281849899.jpg" alt="BinaryCharTree" style="zoom: 25%;" />

```cpp
#include <iostream>
class BinaryCharTree
{
public:
    char value;
    BinaryCharTree* left_child;
    BinaryCharTree* right_child;
    BinaryCharTree()
    {
        this->left_child = NULL;
        this->right_child = NULL;
    }
    BinaryCharTree(char name)
    {
        this->value = name;
        this->left_child = NULL;
        this->right_child = NULL;
    }
    void pre_order_visit()
    {
        std::cout << this->value << " ";
        if (this->left_child != NULL) this->left_child->pre_order_visit();
        if (this->right_child != NULL) this->right_child->pre_order_visit();
    }
    void in_order_visit()
    {
        if (this->left_child != NULL) this->left_child->in_order_visit();
        std::cout << this->value << " ";
        if (this->right_child != NULL) this->right_child->in_order_visit();
    }
    void post_order_visit()
    {
        if (this->left_child != NULL) this->left_child->post_order_visit();
        if (this->right_child != NULL) this->right_child->post_order_visit();
        std::cout << this->value << " ";
    }
    int get_depth()
    {
        if (this->left_child == NULL && this->right_child == NULL)
        {
            return 1;
        }
        int temp_left_depth = 0;
        if (this->left_child != NULL) temp_left_depth = this->left_child->get_depth();
        int temp_right_depth = 0;
        if (this->right_child != NULL) temp_right_depth = this->right_child->get_depth();

        return 1 + std::max(temp_left_depth, temp_right_depth);
    }
    int get_num_nodes()
    {
        if (this->left_child == NULL && this->right_child == NULL) return 1;

        int temp_left_nodes = 0;
        if (this->left_child != NULL) temp_left_nodes = this->left_child->get_num_nodes();
        int temp_right_nodes = 0;
        if (this->right_child != NULL) temp_right_nodes = this->right_child->get_num_nodes();
        return temp_left_nodes + temp_right_nodes + 1;
    }
};
BinaryCharTree* manual_construct_tree()
{
    BinaryCharTree* tree = new BinaryCharTree('A');
    BinaryCharTree* treeB = new BinaryCharTree('B');
    BinaryCharTree* treeC = new BinaryCharTree('C');
    BinaryCharTree* treeD = new BinaryCharTree('D');
    BinaryCharTree* treeE = new BinaryCharTree('E');
    BinaryCharTree* treeF = new BinaryCharTree('F');
    BinaryCharTree* treeG = new BinaryCharTree('G');
    tree->left_child = treeB;
    tree->right_child = treeC;
    treeB->right_child = treeD;
    treeC->left_child = treeE;
    treeD->left_child = treeF;
    treeD->right_child = treeG;
    return tree;
}
int main()
{
    BinaryCharTree* tree = manual_construct_tree();
    std::cout << "Preorder visit: ";
    tree->pre_order_visit();
    std::cout << std::endl;
    std::cout << "In-order visit: ";
    tree->in_order_visit();
    std::cout << std::endl;
    std::cout << "Post-order visit: ";
    tree->post_order_visit();
    std::cout << std::endl;

    std::cout << "The depth is: " << tree->get_depth() << std::endl;
    std::cout << "The number of nodes is: " << tree->get_num_nodes() << std::endl;

    return 0;
}
```

output:

>   Preorder visit: A B D F G C E 
>   In-order visit: B F D G A E C 
>   Post-order visit: F G D B E C A 
>   The depth is: 4
>   The number of nodes is: 7

## Day 22: 二叉树的存储

对于任意一棵二叉树, 我们可以将其转换为满二叉树来存储. 以 Day 21 的数据为例, 将其转换为满二叉树并编号的结果如图所示:

![FullBinaryTree](https://amonologue-image-bed.oss-cn-chengdu.aliyuncs.com/202303/202306301138273.jpg)

其中, N 表示空节点. 设根结点的编号为 $1$, 对于任意一个节点 $i$, 其左儿子的编号为 $i\times2$ 右儿子的编号为 $i\times2+1$. 然后用两个数组分别存储节点的值和节点的编号.

value array: [A, B, C, D, E, F, G]

index array: [1, 2, 3, 5, 6, 10, 11]

```cpp
#include <iostream>
#include <vector>
#include <queue>
class BinaryCharTree
{
public:
    int index;
    char value;
    BinaryCharTree* left_child;
    BinaryCharTree* right_child;
    BinaryCharTree()
    {
        this->index = 1;
        this->left_child = NULL;
        this->right_child = NULL;
    }
    BinaryCharTree(char name)
    {
        this->index = 1;
        this->value = name;
        this->left_child = NULL;
        this->right_child = NULL;
    }
    void pre_order_visit()
    {
        std::cout << this->value << " ";
        if (this->left_child != NULL) this->left_child->pre_order_visit();
        if (this->right_child != NULL) this->right_child->pre_order_visit();
    }
    void in_order_visit()
    {
        if (this->left_child != NULL) this->left_child->in_order_visit();
        std::cout << this->value << " ";
        if (this->right_child != NULL) this->right_child->in_order_visit();
    }
    void post_order_visit()
    {
        if (this->left_child != NULL) this->left_child->post_order_visit();
        if (this->right_child != NULL) this->right_child->post_order_visit();
        std::cout << this->value << " ";
    }
    int get_depth()
    {
        if (this->left_child == NULL && this->right_child == NULL)
        {
            return 1;
        }
        int temp_left_depth = 0;
        if (this->left_child != NULL) temp_left_depth = this->left_child->get_depth();
        int temp_right_depth = 0;
        if (this->right_child != NULL) temp_right_depth = this->right_child->get_depth();

        return 1 + std::max(temp_left_depth, temp_right_depth);
    }
    int get_num_nodes()
    {
        if (this->left_child == NULL && this->right_child == NULL) return 1;

        int temp_left_nodes = 0;
        if (this->left_child != NULL) temp_left_nodes = this->left_child->get_num_nodes();
        int temp_right_nodes = 0;
        if (this->right_child != NULL) temp_right_nodes = this->right_child->get_num_nodes();
        return temp_left_nodes + temp_right_nodes + 1;
    }
};
BinaryCharTree* manual_construct_tree()
{
    BinaryCharTree* tree = new BinaryCharTree('A');
    BinaryCharTree* treeB = new BinaryCharTree('B');
    BinaryCharTree* treeC = new BinaryCharTree('C');
    BinaryCharTree* treeD = new BinaryCharTree('D');
    BinaryCharTree* treeE = new BinaryCharTree('E');
    BinaryCharTree* treeF = new BinaryCharTree('F');
    BinaryCharTree* treeG = new BinaryCharTree('G');
    tree->left_child = treeB;
    treeB->index = tree->index * 2;
    tree->right_child = treeC;
    treeC->index = tree->index * 2 + 1;
    treeB->right_child = treeD;
    treeD->index = treeB->index * 2 + 1;
    treeC->left_child = treeE;
    treeE->index = treeC->index * 2;
    treeD->left_child = treeF;
    treeF->index = treeD->index * 2;
    treeD->right_child = treeG;
    treeG->index = treeD->index * 2 + 1;
    return tree;
}
void binary_tree_to_array(BinaryCharTree* tree, std::vector<char>& value_array, std::vector<int>& index_array)
{
    std::queue<BinaryCharTree*> child_tree_queue;
    if (tree->left_child != NULL && tree->right_child != NULL) child_tree_queue.push(tree);
    while (!child_tree_queue.empty())
    {
        BinaryCharTree* tree = child_tree_queue.front();
        child_tree_queue.pop();
        value_array.push_back(tree->value);
        index_array.push_back(tree->index);
        if (tree->left_child != NULL) child_tree_queue.push(tree->left_child);
        if (tree->right_child != NULL) child_tree_queue.push(tree->right_child);
    }
}
int main()
{
    BinaryCharTree* tree = manual_construct_tree();
    std::cout << "Preorder visit: ";
    tree->pre_order_visit();
    std::cout << std::endl;
    std::cout << "In-order visit: ";
    tree->in_order_visit();
    std::cout << std::endl;
    std::cout << "Post-order visit: ";
    tree->post_order_visit();
    std::cout << std::endl;

    std::cout << "The depth is: " << tree->get_depth() << std::endl;
    std::cout << "The number of nodes is: " << tree->get_num_nodes() << std::endl;

    std::vector<char> value_array;
    std::vector<int> index_array;
    binary_tree_to_array(tree, value_array, index_array);
    std::cout << "value array: ";
    for (int i = 0; i < value_array.size(); i ++) std::cout << value_array[i] << ' ';
    std::cout << std::endl;
    std::cout << "index array: ";
    for (int i = 0; i < index_array.size(); i ++) std::cout << index_array[i] << ' ';
    std::cout << std::endl;
    return 0;
}
```

output:

>   Preorder visit: A B D F G C E 
>   In-order visit: B F D G A E C 
>   Post-order visit: F G D B E C A 
>   The depth is: 4
>   The number of nodes is: 7
>   value array: A B C D E F G 
>   index array: 1 2 3 5 6 10 11 

## Day 23: 使用具有通用性的队列

使用 CPP 类模板实现一个循环队列, 替换 Day 22 使用的 std::vector 和 std::queue.

```cpp
#include <iostream>
#include <sstream>
class BinaryCharTree
{
public:
    int index;
    char value;
    BinaryCharTree* left_child;
    BinaryCharTree* right_child;
    BinaryCharTree()
    {
        this->index = 1;
        this->left_child = NULL;
        this->right_child = NULL;
    }
    BinaryCharTree(char name)
    {
        this->index = 1;
        this->value = name;
        this->left_child = NULL;
        this->right_child = NULL;
    }
    void pre_order_visit()
    {
        std::cout << this->value << " ";
        if (this->left_child != NULL) this->left_child->pre_order_visit();
        if (this->right_child != NULL) this->right_child->pre_order_visit();
    }
    void in_order_visit()
    {
        if (this->left_child != NULL) this->left_child->in_order_visit();
        std::cout << this->value << " ";
        if (this->right_child != NULL) this->right_child->in_order_visit();
    }
    void post_order_visit()
    {
        if (this->left_child != NULL) this->left_child->post_order_visit();
        if (this->right_child != NULL) this->right_child->post_order_visit();
        std::cout << this->value << " ";
    }
    int get_depth()
    {
        if (this->left_child == NULL && this->right_child == NULL)
        {
            return 1;
        }
        int temp_left_depth = 0;
        if (this->left_child != NULL) temp_left_depth = this->left_child->get_depth();
        int temp_right_depth = 0;
        if (this->right_child != NULL) temp_right_depth = this->right_child->get_depth();

        return 1 + std::max(temp_left_depth, temp_right_depth);
    }
    int get_num_nodes()
    {
        if (this->left_child == NULL && this->right_child == NULL) return 1;

        int temp_left_nodes = 0;
        if (this->left_child != NULL) temp_left_nodes = this->left_child->get_num_nodes();
        int temp_right_nodes = 0;
        if (this->right_child != NULL) temp_right_nodes = this->right_child->get_num_nodes();
        return temp_left_nodes + temp_right_nodes + 1;
    }
};
BinaryCharTree* manual_construct_tree()
{
    BinaryCharTree* tree = new BinaryCharTree('A');
    BinaryCharTree* treeB = new BinaryCharTree('B');
    BinaryCharTree* treeC = new BinaryCharTree('C');
    BinaryCharTree* treeD = new BinaryCharTree('D');
    BinaryCharTree* treeE = new BinaryCharTree('E');
    BinaryCharTree* treeF = new BinaryCharTree('F');
    BinaryCharTree* treeG = new BinaryCharTree('G');
    tree->left_child = treeB;
    treeB->index = tree->index * 2;
    tree->right_child = treeC;
    treeC->index = tree->index * 2 + 1;
    treeB->right_child = treeD;
    treeD->index = treeB->index * 2 + 1;
    treeC->left_child = treeE;
    treeE->index = treeC->index * 2;
    treeD->left_child = treeF;
    treeF->index = treeD->index * 2;
    treeD->right_child = treeG;
    treeG->index = treeD->index * 2 + 1;
    return tree;
}
template<typename T>
class MyQueue
{
public:
    const static int MAX_LENGTH = 20;
    T* data;
    int head;
    int tail;
    MyQueue()
    {
        data = new T[MAX_LENGTH];
        this->head = 0;
        this->tail = 0;
    }
    ~MyQueue()
    {
        delete []data;
    }
    void push(T value)
    {
        if ((this->tail + 1) % MAX_LENGTH == this->head)
        {
            std::cout << "The queue is full." << std::endl;
            return;
        }
        this->data[this->tail] = value;
        this->tail = (this->tail + 1) % MAX_LENGTH;
    }
    void pop()
    {
        if (this->tail == this->head)
        {
            std::cout << "The queue is empty." << std::endl;
            return;
        }
        this->head = (this->head + 1) % MAX_LENGTH;
    }
    T front()
    {
        return this->data[this->head];
    }
    bool empty()
    {
        if (this->head == this->tail) return true;
        return false;
    }
    std::string to_string()
    {
        std::stringstream ss;
        for (int i = this->head; i != this->tail; i = (i + 1) % MAX_LENGTH)
            ss << this->data[i] << ' ';
        return ss.str();
    }
};
void binary_tree_to_array(BinaryCharTree* tree, MyQueue<char>& value_array, MyQueue<int>& index_array)
{
    MyQueue<BinaryCharTree*> child_tree_queue;
    if (tree->left_child != NULL && tree->right_child != NULL) child_tree_queue.push(tree);
    while (!child_tree_queue.empty())
    {
        BinaryCharTree* tree = child_tree_queue.front();
        child_tree_queue.pop();
        value_array.push(tree->value);
        index_array.push(tree->index);
        if (tree->left_child != NULL) child_tree_queue.push(tree->left_child);
        if (tree->right_child != NULL) child_tree_queue.push(tree->right_child);
    }
}
int main()
{
    BinaryCharTree* tree = manual_construct_tree();
    std::cout << "Preorder visit: ";
    tree->pre_order_visit();
    std::cout << std::endl;
    std::cout << "In-order visit: ";
    tree->in_order_visit();
    std::cout << std::endl;
    std::cout << "Post-order visit: ";
    tree->post_order_visit();
    std::cout << std::endl;

    std::cout << "The depth is: " << tree->get_depth() << std::endl;
    std::cout << "The number of nodes is: " << tree->get_num_nodes() << std::endl;

    MyQueue<char> value_array;
    MyQueue<int> index_array;
    binary_tree_to_array(tree, value_array, index_array);
    std::cout << "value array: " << value_array.to_string() << std::endl;
    std::cout << "index array: " << index_array.to_string() << std::endl;
    return 0;
}
```

output:

>   Preorder visit: A B D F G C E 
>   In-order visit: B F D G A E C 
>   Post-order visit: F G D B E C A 
>   The depth is: 4
>   The number of nodes is: 7
>   value array: A B C D E F G 
>   index array: 1 2 3 5 6 10 11 

## Day 24: 二叉树的建立

## Day 25: 二叉树的深度遍历的栈实现(中序)

## Day 26: 二叉树的深度遍历的栈实现(前序)

## Day 27: Hanoi 塔问题

## Day 28: Huffman 编码(节点定义与文件读取)

## Day 29: Huffman 编码(建树)

## Day 30: Huffman 编码(编码与解码)