#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#define MAX_STRING_SIZE 100
typedef struct {
	int num;
	char word[MAX_STRING_SIZE];
}element;
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
int is_full(LinkedStackType* s)
{
	return 0;
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
		fprintf(stderr, "스택이 비어있음\n");
		exit(1);
	}
	else {
		StackNode* temp = s->top;
		element data = temp->data;
		s->top = s->top->link;
		free(temp);
		return data;
	}
}
element peek(LinkedStackType* s)
{
	if (is_empty(s)) {
		fprintf(stderr, "스택이 비어있음\n");
		exit(1);
	}
	else
		return s->top->data;
}
void stack_print(LinkedStackType* s)
{
	if (is_empty(s))
		printf("(empty)\n");
	else {
		for (StackNode* p = s->top; p != NULL; p = p->link) {
			printf("[%d, %s]", p->data.num, p->data.word);
			if (p == s->top)
				printf("<- top");
			printf("\n");
		}
	}
	printf("--\n");
}
void main()
{
	LinkedStackType s;
	element e;
	init(&s); stack_print(&s);
	e.num = 10;
	strcpy(e.word, "ten");
	push(&s, e); stack_print(&s);
	e.num = 20;
	strcpy(e.word, "twenty");
	push(&s, e); stack_print(&s);
	e.num = 30;
	strcpy(e.word, "thirty");
	push(&s, e); stack_print(&s);
	e.num = 40;
	strcpy(e.word, "forty");
	push(&s, e); stack_print(&s);
	pop(&s); stack_print(&s);
	e.num = 50;
	strcpy(e.word, "fifty");
	push(&s, e); stack_print(&s);
	pop(&s); stack_print(&s);
	pop(&s); stack_print(&s);
	pop(&s); stack_print(&s);
	pop(&s); stack_print(&s);

	return 0;
}