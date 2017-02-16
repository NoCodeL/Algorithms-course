#include <iostream>
#include<cstdio>
#include<cstdlib>

using namespace std;

struct node
{
	int low, high;
};

struct treeNode
{
	node *interval;
	int max;
	treeNode *left, *right;
};

treeNode * newNode(node interval)
{
	treeNode *temp = new treeNode;
	temp->interval = new node(interval);
	temp->max = interval.high;
	temp->left = temp->right = NULL;
};

treeNode *insert(treeNode *root, node interval)
{
	if (root == NULL)
		return newNode(interval);

	int l = root->interval->low;


	if (interval.low < l)
		root->left = insert(root->left, interval);

	else
		root->right = insert(root->right, interval);

	if (root->max < interval.high)
		root->max = interval.high;

	return root;
}
treeNode *minValueNode(struct treeNode* treeNode)
{
    struct treeNode* current = treeNode;

    while (current->left != NULL)
        current = current->left;

    return current;
}

treeNode *deleteNode(treeNode *root, int key)
{
    if (root == NULL) return root;
    if (key < root->interval->low)
        root->left = deleteNode(root->left, key);
    else if (key > root->interval->low)
        root->right = deleteNode(root->right, key);
    else
    {
        if (root->left == NULL)
        {
            treeNode *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            treeNode *temp = root->left;
            free(root);
            return temp;
        }

        treeNode *temp = minValueNode(root->right);

        root->interval->low = temp->interval->low;
        root->interval->high = temp->interval->high;

        root->right = deleteNode(root->right, temp->interval->low);
    }
    return root;
}
bool overlap(node interval1, node interval2)
{
	if (interval1.low <= interval2.high && interval2.low <= interval1.high)
		return true;
	return false;
}

node *overlapSearch(treeNode *root, node interval)
{
	if (root == NULL) return NULL;

	if (overlap(*(root->interval), interval))
		{
		    cout << "\nOverlaps with [" << root->interval->low << ", " << root->interval->high << "]";
		}
	if (root->left != NULL && root->left->max >= interval.low)
        overlapSearch(root->left, interval);
        overlapSearch(root->right, interval);
}

void inorder(treeNode *root)
{
	if (root == NULL) return;

	inorder(root->left);

	cout << "[" << root->interval->low << ", " << root->interval->high << "]"
		<< " max = " << root->max << endl;

	inorder(root->right);
}
int update_max(treeNode* root)
{
    if(root==NULL)
        return 0;
    if(root->left==NULL&&root->right==NULL)
    {
        root->max=root->interval->high;
        return root->max;
    }

    int templ=update_max(root->left);
    int tempr=update_max(root->right);
    root->max=max(root->interval->high,max(templ,tempr));

    return root->max;


}
int main()
{
    int n;
    n=6;
    cout << "Number of nodes to start the tree "<<n<<endl;
	node intervals[] = {{15, 20}, {10, 30}, {17, 19},{5, 20}, {12, 15}, {30, 40}};
	treeNode *root = NULL;
	for (int i = 0; i < n; i++)
		root = insert(root, intervals[i]);

	cout << "In-order traversal of constructed Interval Tree is\n";
	inorder(root);

	node x1 = {14,16};
	cout << "\n\nSearching for interval [" << x1.low << "," << x1.high << "]";
	node *res1 = overlapSearch(root, x1);
	node x2 = {21,23};
	cout << "\n\nSearching for interval [" << x2.low << "," << x2.high << "]";
    node *res2 = overlapSearch(root, x2);
    cout<<"\n\n\n\n";
    //Pass the low-value of the interval to be deleted
    cout << "\nDeleting interval [30,40]"<<endl;
    root = deleteNode(root,10);
    int new_max;
    new_max = update_max(root);
    cout << "In-order traversal of updated Interval Tree is\n";
    inorder(root);
    cout << "\n\nSearching for interval [" << x1.low << "," << x1.high << "]";
	node *res3 = overlapSearch(root, x1);
	cout << "\n\nSearching for interval [" << x2.low << "," << x2.high << "]";
    node *res4 = overlapSearch(root, x2);
	if (res4 == NULL)
		cout << "  No Overlapping Interval";
}
