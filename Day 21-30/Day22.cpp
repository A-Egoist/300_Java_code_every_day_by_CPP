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