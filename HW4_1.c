#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#define TRUE 1
#define FALSE 0
#define MAX_TREE_SIZE 20

typedef struct TreeNode {
	int data;
	struct TreeNode* left, * right;
} TreeNode;
// root
//    15
// 4    15
//15   16 25
//root2
//  15
// 4   15
//15  16 25
//        28
TreeNode n1 = { 15, NULL, NULL };
TreeNode n2 = { 4, &n1, NULL };
TreeNode n3 = { 16, NULL, NULL };
TreeNode n4 = { 25, NULL, NULL };
TreeNode n5 = { 15, &n3, &n4 };
TreeNode n6 = { 15, &n2, &n5 };
TreeNode* root = &n6;

TreeNode m1 = { 15, NULL, NULL };
TreeNode m2 = { 4, &m1, NULL };
TreeNode m3 = { 16, NULL, NULL };
TreeNode m7 = { 28, NULL, NULL };
TreeNode m4 = { 25, NULL, &m7};
TreeNode m5 = { 15, &m3, &m4 };
TreeNode m6 = { 15, &m2, &m5 };
TreeNode* root2 = &m6;
int get_nonleaf_count(TreeNode* t)
{
	if (t == NULL)
		return 0;
	else{
		if (t->left == NULL && t->right == NULL)
			return get_nonleaf_count(t->left) + get_nonleaf_count(t->right);
		else
			return get_nonleaf_count(t->left) + get_nonleaf_count(t->right) + 1;
	}
}
int equal(TreeNode* t1, TreeNode* t2)
{
	if (t1 == NULL && t2 == NULL)
		return TRUE;
	if ((t1 != NULL && t2 == NULL) || (t1 == NULL && t2 != NULL))
		return FALSE;
	else if (t1->data != t2->data)
		return FALSE;
	return equal(t1->left, t2->left) && equal(t1->right, t2->right);
}
int get_oneleaf_count(TreeNode* node)
{
	if (node == NULL)
		return 0;
	else{
		if ((node->left == NULL && node->right != NULL) || (node->left != NULL && node->right == NULL))
			return get_nonleaf_count(node->left) + get_nonleaf_count(node->right) + 1;
		else
			return get_oneleaf_count(node->left) + get_oneleaf_count(node->right);
	}
}
int get_twoleaf_count(TreeNode* node)
{
	if (node == NULL)
		return 0;
	else{
		if (node->left != NULL && node->right != NULL)
			return 1 + get_twoleaf_count(node->left) + get_twoleaf_count(node->right);
		else
			return get_twoleaf_count(node->left) + get_twoleaf_count(node->right);
	}
}
int get_max(TreeNode* node)
{
	if (node == NULL)
		return INT_MIN;
	int max_value = node->data;
	if (max_value < get_max(node->left))
		max_value = get_max(node->left);
	if (max_value < get_max(node->right))
		max_value = get_max(node->right);
	return max_value;
}
int get_min(TreeNode* node)
{
	if (node == NULL)
		return INT_MAX;
	int min_value = node->data;
	if(min_value > get_min(node->left))
		min_value = get_min(node->left);
	if(min_value > get_min(node->right))
		min_value = get_min(node->right);
	return min_value;
}
void node_increase(TreeNode* node)
{
	if (node != NULL) {
		node->data++;
		node_increase(node->left);
		node_increase(node->right);
	}
}
void preorder(TreeNode* root)
{
	if (root != NULL) {
		printf("%d ", root->data);
		preorder(root->left);
		preorder(root->right);
	}
}
TreeNode* copy(TreeNode* root)
{
	if (root == NULL)
		return NULL;
	else {
		TreeNode* temp = (TreeNode*)malloc(sizeof(TreeNode));
		temp->data = root->data;
		temp->left = copy(root->left);
		temp->right = copy(root->right);
		return temp;
	}
}
int main(void)
{
	TreeNode* result[MAX_TREE_SIZE];
	TreeNode* clone;
	int i, num;

	printf("가)\n");
	printf("트리 root 중 비단말노드의 개수는 %d.\n", get_nonleaf_count(root));
	printf("트리 root2 중 비단말노드의 개수는 %d.\n", get_nonleaf_count(root2));

	printf("트리 root 중 자식이 하나만 있는 노드의 개수는 %d.\n", get_oneleaf_count(root));
	printf("트리 root2 중 자식이 하나만 있는 노드의 개수는 %d.\n", get_oneleaf_count(root2));

	printf("트리 root 중 자식이 둘이 있는 노드의 개수는 %d.\n", get_twoleaf_count(root));
	printf("트리 root2 중 자식이 둘이 있는 노드의 개수는 %d.\n", get_twoleaf_count(root2));

	printf("트리 root 에서 가장 큰 수는 %d.\n", get_max(root));
	printf("트리 root2 에서 가장 큰 수는 %d.\n", get_max(root2));
	printf("트리 root 에서 가장 작은 수는 %d.\n", get_min(root));
	printf("트리 root2 에서 가장 작은 수는 %d.\n", get_min(root2));

	printf("\n 나)\n");
	preorder(root);
	//node_increase(root);
	printf("\n");
	preorder(root2);
	printf("\n");
	printf("%s\n", equal(root, root) ? "같다" : "다르다");
	printf("%s\n", equal(root2, root2) ? "같다" : "다르다");
	printf("%s\n", equal(root, root2) ? "같다" : "다르다");

	printf("\n 다)\n");
	clone = copy(root);
	preorder(root);
	printf("\n");
	preorder(clone);
	printf("\n");

	return 0;
}