#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#define MAX_STRING_SIZE 100
typedef struct {
	char name[MAX_STRING_SIZE];
	char gender;
} element;
typedef struct QueueNode {
	element data;
	struct QueueNode* link;
} QueueNode;
typedef struct {
	QueueNode* front, * rear;
} LinkedQueueType;
void init(LinkedQueueType* q)
{
	q->front = q->rear = NULL;
}
int is_empty(LinkedQueueType* q)
{
	return (q->front == NULL);
}
int is_full(LinkedQueueType* q) 
{
	return 0;
}
void enqueue(LinkedQueueType* q, element item)
{
	QueueNode* temp = (QueueNode*)malloc(sizeof(QueueNode));
	if (temp == NULL)
		printf("메모리를 할당할 수 없습니다");
	else {
		temp->data = item; 
		temp->link = NULL;
		if (is_empty(q)) {
			q->front = temp;
			q->rear = temp;
		}
		else {
			q->rear->link = temp; 
			q->rear = temp;
		}
	}
}
// 삭제 함수
element dequeue(LinkedQueueType* q)
{
	QueueNode* temp = q->front;
	element item;
	if (is_empty(q))
		printf("큐가 비어 있습니다");
	else {
		item = temp->data; 
		q->front = q->front->link; 
		if (q->front == NULL) 
			q->rear = NULL;
		free(temp); 
		return item;
	}
}
void print_queue(LinkedQueueType* q)
{
	QueueNode* p;
	for (p = q->front; p != NULL; p = p->link)
		printf("%s ", p->data.name);
	printf("\n");
}
int get_count(LinkedQueueType* q)
{
	QueueNode* p;
	int count = 0;
	for (p = q->front; p != NULL; p = p->link)
		count++;
	return count;
}
void match(LinkedQueueType* q1, LinkedQueueType* q2, element e)
{
	enqueue(q1, e);
	if (is_empty(q2))
		printf("아직 대상자가 없습니다. 기다려 주십시오.\n");
	else
		printf("커플이 탄생했습니다! %s과 %s\n", dequeue(q1).name, dequeue(q2).name);
}
void main()
{
	LinkedQueueType manQ;
	LinkedQueueType womanQ;
	element newPerson;
	char choice;

	init(&manQ);
	init(&womanQ);

	printf("미팅 주선 프로그램입니다.\n");
	printf("i(nsert, 고객입력), c(heck, 대기자 체크), q(uit): ");
	scanf("%c", &choice);
	while (choice != 'q') {
		if (choice == 'i') {
			printf("이름을 입력: ");
			scanf("%s", newPerson.name);
		//	while (getchar() != '\n');
			printf("성별을 입력(m or f): ");
			scanf(" %c", &newPerson.gender);

			if (newPerson.gender == 'm')
				match(&manQ, &womanQ, newPerson);
			else
				match(&womanQ, &manQ, newPerson);
		}
		else if (choice == 'c') {
			printf("남성 대기자 %d명 ", get_count(&manQ));
			print_queue(&manQ);
			printf("여성 대기자 %d명 ", get_count(&womanQ));
			print_queue(&womanQ);
		}
		while (getchar() != '\n');
		printf("i(nsert, 고객입력), c(heck, 대기자 체크), q(uit): ");
		scanf("%c", &choice);
	}
	return 0;
}