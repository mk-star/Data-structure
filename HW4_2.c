#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
typedef int element;
typedef struct TreeNode {
	element key;
	struct TreeNode* left, * right;
}TreeNode;
TreeNode* search_node(TreeNode* node, int key) 
{
	if (node == NULL)
		return NULL;
	if (key == node->key)
		return node;
	else if (key < node->key)
		return search_node(node->left, key);
	else
		return search_node(node->right, key);
}
TreeNode* new_node(int item)
{
	TreeNode* temp = (TreeNode*)malloc(sizeof(TreeNode));
	temp->key = item;
	temp->left = temp->right = NULL;
	return temp;
}
TreeNode* insert_node(TreeNode* node, int key)
{
	if (node == NULL)
		return new_node(key);
	if (key < node->key)
		node->left = insert_node(node->left, key);
	else if (key > node->key)
		node->right = insert_node(node->right, key);
	return node;
}
TreeNode* min_value_node(TreeNode* node)
{
	TreeNode* current = node;
	while (current->left != NULL)
		current = current->left;
	return current;
}
TreeNode* max_value_node(TreeNode* node)
{
	TreeNode* current = node;
	while (current->right != NULL)
		current = current->right;
	return current;
}
TreeNode* delete_node(TreeNode* root, int key)
{
	if (root == NULL)
		return root;
	if (key < root->key)
		root->left = delete_node(root->left, key);
	else if (key > root->key)
		root->right = delete_node(root->right, key);
	else { //key == root->key �и��� �� ��ġ��
		if (root->left == NULL) { //���� Ʈ���� �ϳ��ų� �ܸ� ���!
			TreeNode* temp = root->right;
			free(root);
			return temp;
		}
		else if (root->right == NULL) {
			TreeNode* temp = root->left;
			free(root);
			return temp;
		}
		TreeNode* temp = min_value_node(root->right);
		root->key = temp->key;
		root->right = delete_node(root->right, temp->key);
	}
	return root;
}
void print_node(TreeNode* root)
{
	if (root != NULL) {
		printf("%d ", root->key);
		print_node(root->left);
		print_node(root->right);
	}
}
int get_height(TreeNode* node)
{
	int height = 0;
	if (node != NULL)
		height = 1 + get_max(get_height(node->left), get_height(node->right));
	return height;
}
int get_count(TreeNode* node)
{
	int count = 0;
	if (node != NULL)
		count = 1 + get_count(node->left) + get_count(node->right);
	return count;
}
int main(void)
{
	TreeNode* root = NULL;
	int key;
	char choice;

	printf("Enter i<nsert>, d<elete>, s<earch>, p<rint>, h<eight>, c<ount>, m<ax>, m<in>, q<uit>: ");
	scanf("%c", &choice);
	while (choice != 'q') {
		if (choice == 'i') {
			printf("������ key�� �Է�: ");
			scanf("%d", &key);
			root = insert_node(root, key);
		}
		else if (choice == 'h')
			printf("Ʈ���� ���̴� %d\n", get_height(root));
		else if (choice == 'c')
			printf("����� ������ %d\n", get_count(root));
		else if (choice == 'p') {
			print_node(root);
			printf("\n");
		}
		else if (choice == 'd') {
			printf("������ key�� �Է�: ");
			scanf("%d", &key);
			root = delete_node(root, key);
		}
		else if (choice == 's') {
			printf("Ž���� key�� �Է�: ");
			scanf("%d", &key);
			if (search_node(root, key) != NULL)
				printf("����\n");
			else
				printf("����\n");
		}
		else if (choice == 'm')
			printf("���� ū ���� %d\n", get_maximum(root));
		else if (choice == 'n')
			printf("���� ���� ���� %d\n", get_miminum(root));

		while (getchar() != '\n');
		printf("Enter i<nsert>, d<elete>, s<earch>, p<rint>, h<eight>, c<ount>, m<ax>, m<in>, q<uit>: ");
		scanf("%c", &choice);
	}
	return 0;
}