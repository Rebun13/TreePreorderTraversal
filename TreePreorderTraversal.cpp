#include <iostream>
#include <vector>

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};

class Solution
{
public:
    Node *insert(Node *root, int data)
    {
        if (root == NULL)
        {
            return new Node(data);
        }
        else
        {
            Node *cur;
            if (data <= root->data)
            {
                cur = insert(root->left, data);
                root->left = cur;
            }
            else
            {
                cur = insert(root->right, data);
                root->right = cur;
            }

            return root;
        }
    }

    /*
     * Input: pointer to first node
     */

    void postOrder(Node *root)
    {
        std::vector<Node *> nextLayer{root};
        while (!nextLayer.empty())
        {
            std::vector<Node *> newLayer;
            for (Node *nextNode : nextLayer)
            {
                std::cout << nextNode->data << " ";
                if (nextNode->left != nullptr)
                {
                    newLayer.push_back(nextNode->left);
                }
                if (nextNode->right != nullptr)
                {
                    newLayer.push_back(nextNode->right);
                }
            }
            nextLayer = newLayer;
        }
        std::cout << std::endl;
    }

    /*
     * Input: pointer to first node
     */

    void preOrder(Node *root)
    {
        std::cout << root->data << " ";
        if (root->left != nullptr)
        {
            preOrder(root->left);
        }
        if (root->right != nullptr)
        {
            preOrder(root->right);
        }
    }
}
;

int main()
{

    Solution myTree;
    Node *root = NULL;

    int t;
    int data;

    std::cin >> t;

    while (t-- > 0)
    {
        std::cin >> data;
        root = myTree.insert(root, data);
    }

    myTree.preOrder(root);

    return 0;
}
