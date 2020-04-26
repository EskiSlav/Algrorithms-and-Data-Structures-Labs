#include <iostream>
#include <queue>
#include <stack>


using namespace std;

struct  TreeNode
{
    double data; // ключ/данные
    TreeNode *left; // указатель на левого потомка
    TreeNode *right; // указатель на правого потомка
};

void levelOrderPrint(TreeNode *root) {
    if (root == NULL)
    {
       return;
    }
    queue<TreeNode *> q; // Создаем очередь
    q.push(root); // Вставляем корень в очередь

    while (!q.empty() ) // пока очередь не пуста
    {
        TreeNode* temp = q.front(); // Берем первый элемент в очереди
        q.pop();  // Удаляем первый элемент в очереди
        cout << temp->data << " "; // Печатаем значение первого элемента в очереди

        if ( temp->left != NULL )
            q.push(temp->left);  // Вставляем  в очередь левого потомка

        if ( temp->right != NULL )
            q.push(temp->right);  // Вставляем  в очередь правого потомка
   }
}

void preorderPrint(TreeNode *root)
{
    if (root == NULL)   // Базовый случай
    {
       return;
    }
    cout << root->data << " ";
    preorderPrint(root->left);   //рекурсивный вызов левого поддерева
    preorderPrint(root->right);  //рекурсивный вызов правого поддерева
}
// Функция печатает значения бинарного дерева поиска в прямом порядке.
// Вместо печати первой инструкцией функции может быть любое действие
// с данным узлом

void inorderPrint(TreeNode *root)
{
    if (root == NULL)   // Базовый случай
    {
       return;
    }
    preorderPrint(root->left);   //рекурсивный вызов левого поддерева
    cout << root->data << " ";
    preorderPrint(root->right);  //рекурсивный вызов правого поддерева
}
// Функция печатает значения бинарного дерева поиска в симметричном порядке.
// То есть в отсортированном порядке

void postorderPrint(TreeNode *root)
{
    if (root == NULL)   // Базовый случай
    {
       return;
    }
    preorderPrint(root->left);   //рекурсивный вызов левого поддерева
    preorderPrint(root->right);  //рекурсивный вызов правого поддерева
    cout << root->data << " ";
}
// Функция печатает значения бинарного дерева поиска в обратном порядке.
// Не путайте обратный и обратноотсортированный (обратный симметричный).

void reverseInorderPrint(TreeNode *root)
{
    if (root == NULL)   // Базовый случай
    {
       return;
    }
    preorderPrint(root->right);  //рекурсивный вызов правого поддерева
    cout << root->data << " ";
    preorderPrint(root->left);   //рекурсивный вызов левого поддерева

}
// Функция печатает значения бинарного дерева поиска в обратном симметричном порядке.
// То есть в обратном отсортированном порядке

void iterativePreorder(TreeNode *root)
{
    if (root == NULL)
    {
       return;
    }
    stack<TreeNode *> s;  // Создаем стек
    s.push(root);  // Вставляем корень в стек
    /* Извлекаем из стека один за другим все элементы.
       Для каждого извлеченного делаем следующее
       1) печатаем его
       2) вставляем в стек правого! потомка
          (Внимание! стек поменяет порядок выполнения на противоположный!)
       3) вставляем в стек левого! потомка */
    while (s.empty() == false)
    {
        // Извлекаем вершину стека и печатаем
        TreeNode *temp = s.top();
        s.pop();
        cout << temp->data << " ";

        if (temp->right)
            s.push(temp->right); // Вставляем в стек правого потомка
        if (temp->left)
            s.push(temp->left);  // Вставляем в стек левого потомка
    }
}
// В симметричном и обратном итеративном обходах просто меняем инструкции
// местами по аналогии с рекурсивными функциями.


int main ()
{
    TreeNode * root;
    root = new TreeNode;
    TreeNode * current = root;
    current->data = 2.25;
    current->left = new TreeNode;
    current->right = new TreeNode;
    current->left->data = 2;
    current->right->data = 3;
    current = current->left;

    current->left = new TreeNode;
    current->right = new TreeNode;
    current->left->data = 4;
    current->right->data = 5;
    current = current->right;
    
    current->left = new TreeNode;
    current->right = new TreeNode;
    current->left->data = 6;
    current->right->data = 7;
    current = root->right;

    current->left = new TreeNode;
    current->right = new TreeNode;
    current->left->data = 8;
    current->right->data = 9;
    cout << "Level order print:\n";
    levelOrderPrint(root);
    cout << endl;
    cout << "Preorder print:\n";
    preorderPrint(root);
    cout << endl;
    cout << "Inorder print:\n";
    inorderPrint(root);
    cout << endl;
    cout << "Postorder print:\n";
    postorderPrint(root);
    cout << endl;
    cout << "IterativePreorder\n";
    iterativePreorder(root);
    cout << endl;
}