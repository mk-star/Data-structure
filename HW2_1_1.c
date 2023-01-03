#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 3
#define MAX_SIZE 100
typedef struct {
	char name[MAX_SIZE];
} element;
typedef struct {
	int front, rear;
	element data[MAX_QUEUE_SIZE];
} QueueType;
void error(char* message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}
void init(QueueType* q)
{
	q->front = q->rear = 0;
}
int is_empty(QueueType* q)
{
	return (q->front == q->rear);
}
int is_full(QueueType* q)
{
	return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}
void enqueue(QueueType* q, element item)
{
	if (is_full(q))
		error("큐가 포화상태입니다");
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->data[q->rear] = item;
}
element dequeue(QueueType* q)
{
	if (is_empty(q))
		error("큐가 공백상태입니다");
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->data[q->front];
}
element peek(QueueType* q)
{
	if (is_empty(q))
		error("큐가 공백상태입니다");
	return q->data[(q->front + 1) % MAX_QUEUE_SIZE];
}
int get_count(QueueType* q)
{
	int count = q->rear - q->front;
	if (count < 0)
		count += MAX_QUEUE_SIZE;
	return count;
}
void match(element p, QueueType* myQ, QueueType* partnerQ)
{
	if (is_full(myQ))
		printf("아직 대상자가 없습니다. 대기자가 꽉찼으니 담기회를 이용\n");
	else {
		enqueue(myQ, p);
		if (is_empty(partnerQ))
			printf("아직 대상자가 없습니다. 기다려주십시요.\n");
		else {
			printf("커플이 탄생했습니다! %s와 %s\n", myQ->data[(myQ->front + 1) % MAX_QUEUE_SIZE].name, partnerQ->data[(partnerQ->front + 1) % MAX_QUEUE_SIZE].name);
			dequeue(myQ);
			dequeue(partnerQ);
		}
	}
}
void print_queue(QueueType* q)
{
	int i;

	for (i = (q->front + 1) % MAX_QUEUE_SIZE; i <= q->rear; i++)
		printf("%s ", q->data[i].name);
	printf("\n");
}
int main(void)
{
	QueueType manQ;
	QueueType womanQ;
	element newPerson;
	char answer, gender;

	init(&manQ);
	init(&womanQ);
	printf("미팅 주선 프로그램입니다.\n");
	do {
		printf("i<nsert, 고객입력>, c<heck, 대기자 체크>, q<uit>: ");
		scanf("%c", &answer);

		if (answer == 'i') {
			printf("이름을 입력: ");
			scanf("%s", newPerson.name);
			while (getchar() != '\n');
			printf("성별을 입력<m or f>: ");
			scanf("%c", &gender);
			if (gender == 'm')
				match(newPerson, &manQ, &womanQ);
			else 
				match(newPerson, &womanQ, &manQ);
		}
		else if (answer == 'c') {
			printf("남성 대기자 %d명: ", get_count(&manQ));
			print_queue(&manQ);
			printf("여성 대기자 %d명: ", get_count(&womanQ));
			print_queue(&womanQ);
		}
		while (getchar() != '\n');
	} while (answer != 'q');
	return 0;
}