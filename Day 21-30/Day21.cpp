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