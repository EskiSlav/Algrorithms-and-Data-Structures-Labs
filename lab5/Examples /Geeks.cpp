#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;

struct TreeNode
{
	char sign;
	int count;
	TreeNode* left;
	TreeNode* right;
	TreeNode* parent;
	TreeNode(char x, TreeNode* p)
	{
		count = 1;
		parent = p;
		sign = x;
		left = right = 0;
	};

	void AddNode(char x, TreeNode**tree, TreeNode* parent)
	{
		if (*tree == 0)
		{
			*tree = new TreeNode(x, parent);
		}
		else
		{
			if (x < (*tree)->sign)
				AddNode(x, &(*tree)->left, *tree);
			else if (x > (*tree)->sign)
				AddNode(x, &(*tree)->right, *tree);
			else
				(*tree)->count++;
		}
	}

	TreeNode* FindMin(TreeNode*tree)
	{
		if (tree->left != 0)
			FindMin(tree->left);
		else
			return tree;
	}

	TreeNode* TreeSuccsessor(TreeNode*tree)
	{
		if (tree->right != 0)
			return FindMin(tree->right);
		else
		{
			TreeNode* child = tree;
			TreeNode* par   = tree->parent;
			while ((par != 0)&&(par->left!=child))
			{
				child = par;
				par = par->parent;
			}
			return par;
		}
	}

	bool IsRightChild(TreeNode*tree)
	{
		if (tree->parent->left == tree)
			return 0;
		else
			return 1;
	}

	void DeleteNode(TreeNode*tree)
	{
		if ((tree->left==0)&&(tree->right ==0))
		{
			if (IsRightChild(tree))
				tree->parent->right = 0;
			else
				tree->parent->left = 0;
		}
		if ((tree->left != 0) && (tree->right == 0))
		{
			if (IsRightChild(tree))
				tree->parent->right = tree->left;
			else
				tree->parent->left = tree->left;
		}
		if ((tree->left == 0) && (tree->right != 0))
		{
			if (IsRightChild(tree))
				tree->parent->right = tree->right;
			else
				tree->parent->left = tree->right;
		}
		if ((tree->left != 0) && (tree->right != 0))
		{
			TreeNode* temp = TreeSuccsessor(tree);
			tree->sign = temp->sign;
			DeleteNode(temp);
		}
		delete tree;
	}

	void FindDublicates(TreeNode*tree)
	{
		if (tree != NULL)
		{
			FindDublicates(tree->left);
			FindDublicates(tree->right);
			if (tree->count > 1)
			{
				DeleteNode(tree);
				cout << endl;
				cout << endl;
			}
		}
	}

	void Show(TreeNode*tree, int height)
	{
		if (tree != NULL)
		{
			height += 5;
			Show(tree->left, height++);
			for (int i = 0; i < height; i++)
				cout << " ";
			cout << tree->sign << "(" << tree->count << ")" << endl;
			Show(tree->right, height++);
		}
	
	}
};



int main()
{
	
	string line;
	getline(cin, line);
	int size = line.length();
	TreeNode* Tree = new TreeNode(line[0], 0);
	for (int i = 1; i < size; i++)
	{
		Tree->AddNode(line[i], &Tree, 0);
	}
	Tree->Show(Tree, 6);
	/*Tree->FindDublicates(Tree);
	Tree->Show(Tree, 6);*/
	return 0;
}
