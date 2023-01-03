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
		error("ť�� ��ȭ�����Դϴ�");
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->data[q->rear] = item;
}
element dequeue(QueueType* q)
{
	if (is_empty(q))
		error("ť�� ��������Դϴ�");
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->data[q->front];
}
element peek(QueueType* q)
{
	if (is_empty(q))
		error("ť�� ��������Դϴ�");
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
		printf("���� ����ڰ� �����ϴ�. ����ڰ� ��á���� ���ȸ�� �̿�\n");
	else {
		enqueue(myQ, p);
		if (is_empty(partnerQ))
			printf("���� ����ڰ� �����ϴ�. ��ٷ��ֽʽÿ�.\n");
		else {
			printf("Ŀ���� ź���߽��ϴ�! %s�� %s\n", myQ->data[(myQ->front + 1) % MAX_QUEUE_SIZE].name, partnerQ->data[(partnerQ->front + 1) % MAX_QUEUE_SIZE].name);
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
	printf("���� �ּ� ���α׷��Դϴ�.\n");
	do {
		printf("i<nsert, ���Է�>, c<heck, ����� üũ>, q<uit>: ");
		scanf("%c", &answer);

		if (answer == 'i') {
			printf("�̸��� �Է�: ");
			scanf("%s", newPerson.name);
			while (getchar() != '\n');
			printf("������ �Է�<m or f>: ");
			scanf("%c", &gender);
			if (gender == 'm')
				match(newPerson, &manQ, &womanQ);
			else 
				match(newPerson, &womanQ, &manQ);
		}
		else if (answer == 'c') {
			printf("���� ����� %d��: ", get_count(&manQ));
			print_queue(&manQ);
			printf("���� ����� %d��: ", get_count(&womanQ));
			print_queue(&womanQ);
		}
		while (getchar() != '\n');
	} while (answer != 'q');
	return 0;
}