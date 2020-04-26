#include <iostream>
#include <vector>
#include <map>
using namespace std;

struct TreeNode{
    char letter;
    int repetitions;
    TreeNode * left;
    TreeNode * right;
    TreeNode * parent;
};

class Tree{
private:
    int depth;
    char * text;
    TreeNode * head;
    TreeNode * current;
    void addVertex(char letter, int curDepth, int repetitions);
    void deleteNode(TreeNode * curr);

public:
    Tree();
    void fillTree(char * text);
    void printTree(TreeNode * curr, int curDepth);
    int getMaxDepth();
    void findDuplicates(TreeNode * curr);
    TreeNode * getTop();
    TreeNode * getMin(TreeNode * curr);
    TreeNode * findNextElement(TreeNode* curr);
};

Tree::Tree()
{
    this->text = NULL;
    this->head = NULL;
    this->current = NULL;
}

TreeNode * Tree::getTop()
{
    return head;
}
int Tree::getMaxDepth()
{
    return this->depth;
}

TreeNode* Tree::getMin(TreeNode* curr)
{
    if(curr != NULL)
    {
        if(curr->left != NULL)
            getMin(curr->left);
        else 
            return curr;
    }
}

void Tree::fillTree(char* text)
{
    this->text = text;
    if(head == NULL)
    {
        head = new TreeNode;
        head->letter = text[0];
        head->parent = NULL;
        head->left = NULL;
        head->right = NULL;
        head->repetitions = 0;
        current = head;
    }

    for(int i = 1; text[i] != '\0'; i++)
    {
        addVertex(text[i], 0, 0);
    }
}

void Tree::addVertex(char letter, int curDepth, int repetitions)
{
    curDepth++;
    if(curDepth > depth)
        this->depth = curDepth;

    if (letter == current->letter)
    {
        repetitions++;
        current->repetitions++;
    }

    if(current->letter > letter)
        if(current->left != NULL)
        {  
            current = current->left;
            addVertex(letter, curDepth, repetitions);
        }
        else
        {
            current->left = new TreeNode;
            current->left->letter = letter;
            current->left->repetitions = repetitions;
            current->left->parent = current;
            current->left->left = NULL;
            current->left->right = NULL;
            current = head;
        }
    else
        if(current->right != NULL)
        {
            current = current->right;
            addVertex(letter, curDepth, repetitions);
        }
        else
        {
            current->right = new TreeNode;
            current->right->letter = letter;
            current->right->repetitions = repetitions;
            current->right->parent = current;
            current->right->left = NULL;
            current->right->right = NULL;
            current = head;
        }
        
}

void Tree::printTree(TreeNode * curr, int curDepth)
{
    if(curr != NULL)
    {
        curDepth += 1;
        printTree(curr->right, curDepth);

        for(int i = 0; i < curDepth-1; i++)
            printf("     ");

            printf("%c %d\n", curr->letter, curr->repetitions);
        printTree(curr->left, curDepth);
    }
}


void Tree::deleteNode(TreeNode* curr)
{
    TreeNode * parent = curr->parent; 
    TreeNode * leftChild = curr->left;
    TreeNode * rightChild = curr->right;

    if(curr->left == NULL && curr->right == NULL)
    {
        if (curr == parent->right)
            parent->right = NULL;
        else
            parent->left = NULL;
        delete curr;
    }
    else if (curr->left != NULL && curr->right == NULL)
    {
        if(curr == parent->right)
        {
            parent->right = curr->left;
        }
        else
            parent->left = curr->left;
        delete curr;
        
    }
    else if (curr->left == NULL && curr->right != NULL)
    {
        if(curr == parent->right)
            parent->right = curr->right;
        else
            parent->left = curr->right;
        delete curr;
    }
    else if (curr->right != NULL)
    {
        TreeNode * node = getMin(curr->right);
        curr->letter = node->letter;
        curr->repetitions = node->repetitions;
        if(node->parent->right == node)
            node->parent->right = NULL;
        else 
            node->parent->left = NULL;
        curr->left = leftChild;
        curr->right = rightChild;
        
        deleteNode(node);

    }
    printf(" \n.......................\n");
    printTree(getTop(), 0);
    
}

void Tree::findDuplicates(TreeNode* curr)
{   
    if (curr != NULL)
    {
            
        findDuplicates(curr->right);
        findDuplicates(curr->left);

        if(curr->repetitions > 0)
            deleteNode(curr);
        
    }
}

TreeNode* Tree::findNextElement(TreeNode * curr)
{
    if(curr->right != NULL)
        return getMin(curr->right);
    else
    {
        TreeNode* child = curr;
        TreeNode* parent = curr->parent;
        while(parent != NULL && parent->left != child)
        {
            child = parent;
            parent = parent->parent;
        }
    }
    

}

int main(int argv, char * argc[])
{
    char text[255] = { 0 };
    cin.getline(text, 255);

    Tree head = Tree();
    head.fillTree(text);
    head.printTree(head.getTop(), 0);
    printf(" .......................");
    head.findDuplicates(head.getTop());
    printf("\n\n");
    head.printTree(head.getTop(), 0);
    // printf("Letter %c\n", head.getMin(head.getTop())->letter);
    cout << "Tree depth: " << head.getMaxDepth() << endl;

    return 0;
}