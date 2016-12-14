#include <iostream>

class AvlNode
{
public:
    int element;
    AvlNode *left;
    AvlNode *right;
    int height;

    AvlNode(int ele = 0)
    {
        element = ele;
        height = 0;
    }

};

class AvlTree
{
public:
    void insert(int x)
    {
        insert(x, root);
    }
    void printTree()
    {
        printTree(root);
    }

private:
    AvlNode * root = nullptr;

    void printTree(AvlNode * root)
    {
        if (root)
        {
            printTree(root->left);
            std::cout << root->element << std::endl;
            printTree(root->right);
        }
    }
    int findHeight(AvlNode * t)
    {
        int height_left = 0;
        int height_right = 0;

                if( t->left ) height_left = findHeight( t->left );
                if( t->right ) height_right = findHeight( t->right );

        return height_right > height_left ? ++height_right : ++height_left;
    }

    void insert(int x, AvlNode * & t)
    {
        if(t == nullptr)
        {
            t = new AvlNode(x);
            t->left = nullptr;
            t->right = nullptr;
        }
        else if(x < t->element)
            insert(x,t->left);
        else if (t->element < x)
            insert(x, t->right);

        balance(t);
    }
    int height(AvlNode *t)
    {
        int a;
        if (t)
        a = findHeight(t);
        return t == nullptr ? -1 : a;
    }

    void balance(AvlNode * & t)
    {
        if(t==nullptr)
        {
            return;
        }
        if(height(t->left)-height(t->right) > 1)
        {
            if(height(t->left->left)>= height(t->left->right))
            {
                rotateWithLeftChild(t);
            }
            else
            {
                doubleWithLeftChild(t);
            }
        }
        else
        if(height(t->right)-height(t->left) > 1)
        {
            if(height(t->right->right) >= height(t->right->left))
            {
                rotateWithRightChild(t);
            }
            else
            {
                doubleWithRightChild(t);
            }
        }
        t->height = max(height(t->left), height(t->right));
    }

    int max(int lhs, int rhs)
    {
        return lhs > rhs ? lhs : rhs;
    }

    void rotateWithLeftChild(AvlNode * & k2)
    {
        AvlNode *k1 = k2->left;
        k2->left = k1->right;
        k1->right = k2;
        k2->height = max(height(k2->left), height(k1->right)) + 1;
        k1->height = max(height(k1->left), k2->height) + 1;
        k2 = k1;
    }

    void rotateWithRightChild(AvlNode * & k1)
    {
        AvlNode *k2 = k1->right;
        k1->right = k2->left;
        k2->left = k1;
        k1->height = max(height(k1->left), height(k1->right)) + 1;
        k2->height = max(height(k2->right), k1->height) + 1;
        k1 = k2;

    }
    void doubleWithLeftChild(AvlNode * & k3)
    {
        rotateWithRightChild(k3->left);
        rotateWithLeftChild(k3);
    }
    void doubleWithRightChild(AvlNode * & k1)
    {
        rotateWithLeftChild(k1->right);
        rotateWithRightChild(k1);
    }
};
