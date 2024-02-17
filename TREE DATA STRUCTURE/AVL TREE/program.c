#include <stdio.h>
#include <stdlib.h>
struct node
{
    int key;
    struct node *left;
    struct node *right;
    int hight;
};

int maxImum(int a, int b)
{
    return (a > b) ? a : b;
}

int getHight(struct node *temp)
{
    if (temp == NULL)
    {
        return 0;
    }

    return temp->hight;
}

struct node *createNode(int key)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->key = key;
    temp->left = NULL;
    temp->right = NULL;
    temp->hight = 1;
}

int getBalancingFactor(struct node *temp)
{
    if (temp == NULL)
    {
        return 0;
    }

    return getHight(temp->left) - getHight(temp->right);
}

/*-----------------------------Before Left Rotation----------------------------------
                                     x
                                    /  \
                                   T1   y
                                      /   \
                                    T2     T3
*/

/*-----------------------------After Left Rotation----------------------------------
                                     y
                                    /  \
                                  x     T3
                                /   \
                               T1   T2
*/

struct node *leftRotate(struct node *x)
{
    struct node *y = x->right;
    struct node *T2 = y->left;

    y->left = x;
    x->right = T2;

    x->hight = maxImum(getHight(x->left), getHight(x->right)) + 1;
    y->hight = maxImum(getHight(y->left), getHight(y->right)) + 1;

    return y;
}

/*-----------------------------Before Right Rotation----------------------------------
                                     y
                                    /  \
                                  x     T3
                                /   \
                               T1   T2
*/

/*-----------------------------After Right Rotation----------------------------------
                                     x
                                    /  \
                                   T1   y
                                      /   \
                                    T2     T3
*/

struct node *rightRotate(struct node *y)
{
    struct node *x = y->left;
    struct node *T2 = x->right;

    x->right = y;
    y->left = T2;

    x->hight = maxImum(getHight(x->left), getHight(x->right)) + 1;
    y->hight = maxImum(getHight(y->left), getHight(y->right)) + 1;

    return x;
}

struct node *insertNode(struct node *temp, int key)
{
    if (temp == NULL)
    {
        return createNode(key);
    }

    if (key < temp->key)
    {
        temp->left = insertNode(temp->left, key);
    }
    else if (key > temp->key)
    {
        temp->right = insertNode(temp->right, key);
    }
    else
    {
        // Handle duplicate key (optional: increment count, throw error, etc.)
        return temp;
    }

    temp->hight = maxImum(getHight(temp->left), getHight(temp->right)) + 1;

    int bf = getBalancingFactor(temp);

    // **Left Rotations:** Handle the four possible imbalances for left-heavy nodes
    if (bf > 1)
    {
        if (getBalancingFactor(temp->left) >= 0)
        { // LL imbalance
            return rightRotate(temp);
        }
        else
        { // LR imbalance
            temp->left = leftRotate(temp->left);
            return rightRotate(temp);
        }
    }

    // **Right Rotations:** Handle the four possible imbalances for right-heavy nodes
    if (bf < -1)
    {
        if (getBalancingFactor(temp->right) <= 0)
        { // RR imbalance
            return leftRotate(temp);
        }
        else
        { // RL imbalance
            temp->right = rightRotate(temp->right);
            return leftRotate(temp);
        }
    }

    return temp;
}

void preOrderTraversal(struct node *temp)
{
    if (temp != NULL)
    {
        printf("%d ", temp->key);
        preOrderTraversal(temp->left);
        preOrderTraversal(temp->right);
    }
}

void postOrderTraversal(struct node *temp)
{
    if (temp != NULL)
    {
        preOrderTraversal(temp->left);
        preOrderTraversal(temp->right);
        printf("%d ", temp->key);
    }
}

void inOrderTraversal(struct node *temp) {
    if (temp != NULL) {
        inOrderTraversal(temp->left);
        printf("%d ", temp->key);
        inOrderTraversal(temp->right);
    }
}

int main()
{
    struct node *rootNode = NULL;
    rootNode = insertNode(rootNode, 25);
    rootNode = insertNode(rootNode, 20);
    rootNode = insertNode(rootNode, 36);
    rootNode = insertNode(rootNode, 10);
    rootNode = insertNode(rootNode, 22);
    rootNode = insertNode(rootNode, 30);
    rootNode = insertNode(rootNode, 40);
    inOrderTraversal(rootNode);
    printf("\n");
    return 0;
} /* END OF MAIN FILE*/