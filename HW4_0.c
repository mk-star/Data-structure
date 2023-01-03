#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
typedef struct TreeNode {
	int data;
	struct TreeNode* left, * right;
} TreeNode;

//스택을 위한 타입 정의 
typedef TreeNode* element;
typedef struct StackNode {
	element data;
	struct StackNode* link;
} StackNode;
typedef struct {
	StackNode* top;
} LinkedStackType;
void init(LinkedStackType* s)
{
	s->top = NULL;
}
int is_empty(LinkedStackType* s)
{
	return s->top == NULL;
}
void push(LinkedStackType* s, element item)
{
	StackNode* temp = (StackNode*)malloc(sizeof(StackNode));
	if (temp == NULL) {
		fprintf(stderr, "메모리 할당에러\n");
		return;
	}
	else {
		temp->data = item;
		temp->link = s->top;
		s->top = temp;
	}
}
element pop(LinkedStackType* s)
{
	if (is_empty(s)) {
		exit(1);
	}
	else {
		StackNode* temp = s->top;
		element e = temp->data;
		s->top = s->top->link;
		free(temp);
		return e;
	}
}
void inorder_iter(LinkedStackType* s, TreeNode* root)
{
	while (1) {
		for (; root; root = root->left)
			push(s, root);
		root = pop(s);
		if (!root)
			break;
		printf("[%d] ", root->data);
		root = root->right;
	}
}
//		  15
//	   4		 20
//    1	      16  25
TreeNode n1 = { 1,  NULL, NULL };
TreeNode n2 = { 4,  &n1,  NULL };
TreeNode n3 = { 16, NULL, NULL };
TreeNode n4 = { 25, NULL, NULL };
TreeNode n5 = { 20, &n3,  &n4 };
TreeNode n6 = { 15, &n2,  &n5 };
TreeNode* root = &n6;

int main(void)
{
	LinkedStackType s;
	init(&s);
	printf("중위 순회=");
 	inorder_iter(&s, root);
	printf("\n");

	return 0;
}