#include <iostream>
#include <vector>
#include <queue>

template <typename T>
class Tree
{
public:
    struct TreeNode
    {
        T val;
        std::vector<TreeNode*> vec;

        TreeNode(const T& v) : val(v)
        {}

        void addChild(TreeNode* node)
        {
             vec.push_back(node);
        }
    };

    void printTree(TreeNode* root)
    {
        if (nullptr == root) return;

        std::queue<TreeNode*> q;
        q.push(root);

        while(!q.empty())
        {
            TreeNode* temp = q.front();
            q.pop();

            for(auto i = 0; i < temp -> vec.size(); ++i)
            {
                q.push(temp -> vec[i]);
            }

            std::cout << "val = " << temp -> val << std::endl;
        }  
    }

};


int main(int argc, char* argv[])
{
    Tree<int>::TreeNode* root = new Tree<int>::TreeNode(1);

    Tree<int>::TreeNode* node2 = new Tree<int>::TreeNode(2);

    Tree<int>::TreeNode* node3 = new Tree<int>::TreeNode(3);
    Tree<int>::TreeNode* node4 = new Tree<int>::TreeNode(4);
    Tree<int>::TreeNode* node5 = new Tree<int>::TreeNode(5);

    Tree<int>::TreeNode* node6 = new Tree<int>::TreeNode(6);

    Tree<int>::TreeNode* node7 = new Tree<int>::TreeNode(7);
    Tree<int>::TreeNode* node8 = new Tree<int>::TreeNode(8);

    root -> addChild(node2);
    root -> addChild(node6);

    node2 -> addChild(node3);
    node2 -> addChild(node4);
    node2 -> addChild(node5);

    node6 -> addChild(node7);
    node6 -> addChild(node8);

    Tree<int> t;
    t.printTree(root);

    return 0;

}