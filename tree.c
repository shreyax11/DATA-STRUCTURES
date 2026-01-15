#include <stdio.h> 
#include <stdlib.h>
#include <math.h>


typedef struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
}node;
node* createnode(int data)
{
    node *nn;
    nn=(node*)malloc(sizeof(node));
    if(nn==NULL)
    {
        printf("memory is not allocated!!!!\n");
        return NULL;
    }
    nn->left=NULL;
    nn->right=NULL;
    nn->data=data;
    return nn;
}
node* insert(node *root, int data)
{
    /* node *nn=NULL;
    if (root == NULL)
    {
        return createnode(data); 
    }
        if(data==root->data)
        {
            printf("Node %d already exists. Skipping insertion.\n", data);
            return root;
        }
        else if(data<root->data)
        {
            root->left = insert(root->left,data);
        }
        else
        {
            root->right = insert(root->right,data);
        }
    return root;*/

    if(root == NULL)
        return createnode(data);

    if(data < root->data)
        root->left = insert(root->left, data);
    else if(data > root->data)
        root->right = insert(root->right, data);
    else
        printf("Duplicate value\n");

    return root;
}
void preorder(node *root)
{
    if(root == NULL)
    {
        return;
    }
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
    
}
void postorder(node *root)
{
    if(root!=NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ",root->data);
    }
}
void inorder(node *root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}
// Find the smallest node 
node* findMin(node *root)
{
    if (root == NULL)
        return NULL;
    while (root->left != NULL)
        root = root->left;
    return root;
}
node* deleteNode(node *root, int data)
{
    if (root == NULL)
    {
        printf("Node not found.\n");
        return root;
    }

    if (data < root->data)
        root->left = deleteNode(root->left, data);
    else if (data > root->data)
        root->right = deleteNode(root->right, data);
    else
    {
        // Case 1: Leaf node
        if (root->left == NULL && root->right == NULL)
        {
            printf("Deleting leaf node %d\n", root->data);
            free(root);
            return NULL;
        }
        // Case 2: One child
        else if (root->left == NULL)
        {
            printf("Deleting node %d with right child\n", root->data);
            node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            printf("Deleting node %d with left child\n", root->data);
            node *temp = root->left;
            free(root);
            return temp;
        }
        // Case 3: Two children
        else
        {
            node *temp = findMin(root->right);
            printf("Deleting node %d with two children. Replacing with %d\n", root->data, temp->data);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }
    return root;
}

void printTree(node *root, int space)
{
    if (root == NULL)
        return;

    // Increase distance between levels
    space += 5;

    // Print right child first
    printTree(root->right, space);

    // Print current node after spaces
    printf("\n");
    for (int i = 5; i < space; i++)
        printf(" ");
    printf("%d\n", root->data);

    // Print left child
    printTree(root->left, space);
}
node* search(node* root, int data)
{
	while(root)
	{
		if(data == root->data)
			return root;
		else if(data < root->data)
			root = root->left;
		else if(data > root->data)
			root = root->right;
	}
	return NULL;
}
node* findMax(node *root)
{
    if (root == NULL) return NULL;
    while (root->right != NULL)
        root = root->right;
    return root;
}
int countNodes(node *root)
{
    if (!root) return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}
int countLeaves(node *root)
{
    if (!root) return 0;
    
    if (!root->left && !root->right)
        return 1;

    return countLeaves(root->left) + countLeaves(root->right);
}
/*int height(node *root)
{
    if (!root) return -1; 
    int l = height(root->left);
    int r = height(root->right);
    return (l > r ? l : r) + 1;
}*/
int height(node *root)
{
    if (root == NULL)
        return 0;   // height of empty tree = 0

    int lh = height(root->left);
    int rh = height(root->right);

    if (lh > rh)
        return lh + 1;
    else
        return rh + 1;
}
void printTreeVertical(node *root)
{
    if (root == NULL)
    {
        printf("Tree is empty.\n");
        return;
    }
    node* queue[100];
    int front = 0, rear = 0;
    queue[rear++] = root;

    while (front < rear)
    {
        int count = rear - front;
        while (count > 0)
        {
            node *curr = queue[front++];
            printf("%d ", curr->data);
            if (curr->left)
                queue[rear++] = curr->left;
            if (curr->right)
                queue[rear++] = curr->right;
            count--;
        }
        printf("\n"); 
    }
}

void printTreeCentered(node* root) 
{
    if (!root) 
    {
        printf("Tree is empty.\n");
        return;
    }
    int h = height(root) + 1; 
    int maxWidth = (int)pow(2, h) - 1;
    int level = 1;
    node* queue[1024];
    int front = 0, rear = 0;
    queue[rear++] = root;

    while (level <= h) {
        int nodesInLevel = (int)pow(2, level - 1);
        int space = maxWidth / nodesInLevel; 
        for (int i = 0; i < nodesInLevel; i++) {
            if (front < rear) {
                node* curr = queue[front++];
                if (curr) {
                    printf("%*d%*s", space/2, curr->data, space/2, "");
                    queue[rear++] = curr->left;
                    queue[rear++] = curr->right;
                } else {
                    printf("%*s%*s", space/2, "", space/2, "");
                    queue[rear++] = NULL;
                    queue[rear++] = NULL;
                }
            }
        }
        printf("\n\n"); 
        level++;
    }
}
int main()
{
    int choice, data;
    node *root = NULL;
    node *temp; 

    do
    {
        printf("\n\n--- Binary Tree Menu ---\n");
        printf("1.  Insert Node\n");
        printf("2.  Preorder Traversal (Root-Left-Right)\n");
        printf("3.  Inorder Traversal (Left-Root-Right)\n");
        printf("4.  Postorder Traversal (Left-Right-Root)\n");
        printf("5.  Smallest Node\n");
        printf("6.  Delete Node\n");
        printf("7.  Display Tree Structure\n");
        printf("8.  Search\n");
        printf("9.  Find Maximum Node\n");
        printf("10. Count Total Nodes\n");
        printf("11. Count Leaf Nodes\n");
        printf("12. Tree Height\n");
        printf("13. Display Tree Vertically\n");
        printf("14. Display Tree Vertically (Centered)\n");
        printf("15. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                printf("Enter data for the new node: ");
                scanf("%d", &data);
                root = insert(root, data);
                if (root != NULL) {
                    printf("Insertion complete.\n");
                }
                break;
            
            case 2:
                printf("\n--- Preorder Traversal ---\n");
                if (root == NULL)
                    printf("Tree is empty.\n");
                else
                    preorder(root);
                printf("\n");
                break;

            case 3:
                printf("\n--- Inorder Traversal ---\n");
                if (root == NULL)
                    printf("Tree is empty.\n");
                else
                    inorder(root);
                printf("\n");
                break;

            case 4:
                printf("\n--- Postorder Traversal ---\n");
                if (root == NULL)
                    printf("Tree is empty.\n");
                else
                    postorder(root);
                printf("\n");
                break;

            case 5:
                if (root == NULL)
                    printf("Tree is empty.\n");
                else
                {
                    node *minNode = findMin(root);
                    printf("Smallest node value: %d\n", minNode->data);
                }
                break;
            
            case 6:
                printf("Enter the node value to delete: ");
                scanf("%d", &data);
                root = deleteNode(root, data);
                break;
            
            case 7:
                if (root == NULL)
                    printf("Tree is empty.\n");
                else
                {
                    printf("\n--- Tree Structure (sideways) ---\n");
                    printTree(root, 0);
                }
                break;
            case 8:
				printf("Enter the value:");
				scanf("%d", &data);
				temp = search(root,data);
				if(temp)
					printf("Value Found");
				else
					printf("Value not Found");
				break;
            case 9:
                if (!root) printf("Tree is empty.\n");
                else {
                    node* maxNode = findMax(root);
                    printf("Maximum Node = %d\n", maxNode->data);
                }
                break;

            case 10:
                printf("Total Nodes = %d\n", countNodes(root));
                break;

            case 11:
                printf("Leaf Nodes = %d\n", countLeaves(root));
                break;

            case 12:
                printf("Tree Height = %d\n", height(root));
                break;
            case 13:
                printTreeVertical(root);
                break;
            case 14:
                printTreeCentered(root);
                printf("\n");
                break;
            case 15:
                printf("Exiting program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while(choice != 15);

    return 0;
}
