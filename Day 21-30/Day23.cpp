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