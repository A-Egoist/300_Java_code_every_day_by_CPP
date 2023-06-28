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
    BinaryCharTree* tree = new BinaryCharTree('a');
    BinaryCharTree* treeB = new BinaryCharTree('b');
    BinaryCharTree* treeC = new BinaryCharTree('c');
    BinaryCharTree* treeD = new BinaryCharTree('d');
    BinaryCharTree* treeE = new BinaryCharTree('e');
    BinaryCharTree* treeF = new BinaryCharTree('f');
    BinaryCharTree* treeG = new BinaryCharTree('g');
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

>   Preorder visit: a b d f g c e 
>   In-order visit: b f d g a e c 
>   Post-order visit: f g d b e c a 
>   The depth is: 4
>   The number of nodes is: 7

## Day 22: 二叉树的存储

## Day 23: 使用具有通用性的队列

## Day 24: 二叉树的建立

## Day 25: 二叉树的深度遍历的栈实现(中序)

## Day 26: 二叉树的深度遍历的栈实现(前序)

## Day 27: Hanoi 塔问题

## Day 28: Huffman 编码(节点定义与文件读取)

## Day 29: Huffman 编码(建树)

## Day 30: Huffman 编码(编码与解码)