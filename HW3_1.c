#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX_LIST_SIZE 5
typedef int element;
typedef struct {
	element array[MAX_LIST_SIZE];
	int size;
} ArrayListType;
void error(char* message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}
void init(ArrayListType* L)
{
	L->size = 0;
}
int is_empty(ArrayListType* L)
{
	return L->size == 0;
}
int is_full(ArrayListType* L)
{
	return L->size == MAX_LIST_SIZE;
}
element get_entry(ArrayListType* L, int pos)
{
	if (pos < 0 || pos >= L->size)
		printf("��ġ ����");
	else
		return L->array[pos];
}
void print_list(ArrayListType* L)
{
	for (int i = 0; i < L->size; i++)
		printf("%d->", L->array[i]);
	printf("����Ʈ��\n");
}
void insert(ArrayListType* L, int pos, element item)
{
	if (!is_full(L) && pos >= 0 && pos <= L->size) {
		for (int i = L->size - 1; i >= pos; i--)
			L->array[i + 1] = L->array[i];
		L->array[pos] = item;
		L->size++;
	}
}
void insert_first(ArrayListType* L, element item)
{
	if (!is_full(L)) {
		for (int i = L->size - 1; i >= 0; i--)
			L->array[i + 1] = L->array[i];
		L->array[0] = item;
		L->size++;
	}
	else
		printf("����Ʈ �����÷ο�\n");
}
void insert_last(ArrayListType* L, element item)
{
	if (is_full(L))
		printf("����Ʈ �����÷ο�\n");
	else
		insert(L, L->size, item);
}
element delete(ArrayListType* L, int pos)
{
	element item;

	if (pos < 0 || pos >= L->size)
		printf("��ġ ����\n");
	else {
		item = L->array[pos];
		for (int i = pos; i < L->size - 1; i++)
			L->array[i] = L->array[i + 1];
		L->size--;
		return item;
	}
}
void clear(ArrayListType* L)
{
	L->size = 0;
}
int get_length(ArrayListType* L)
{
	return L->size;
}
void replace(ArrayListType*L, int pos, element item)
{
	if (pos >= 0 && pos < L->size)
		L->array[pos] = item;
	else
		printf("��ġ ����\n");
}
int is_in_list(ArrayListType* L, element item)
{
	for (int i = 0; i < L->size; i++)
		if (L->array[i] == item)
			return 1;
	return 0;
}
void delete_by_key(ArrayListType* L, element key)
{
	int i;
	int found = 0;
	for (i = 0; i < L->size; i++)
		if (L->array[i] == key) {
			found = 1;
			break;
		}
	if (found)
		delete(L, i);
	else
		printf("�����Ϸ��� key���� %d�� ����Ʈ�� �����ϴ�.\n", key);
}
int main(void)
{
	ArrayListType list1;

	init(&list1);
	insert(&list1, 0, 20);
	insert(&list1, 0, 10); print_list(&list1);
	clear(&list1); print_list(&list1);
	
	insert_last(&list1, 90); print_list(&list1);

	insert(&list1, 0, 30);
	insert(&list1, 0, 20);
	insert(&list1, 0, 10); print_list(&list1);

	delete(&list1, 2); print_list(&list1);

	printf("\n-�� ���Ĵ� HW1_1���� �߰��� �Լ��� �׽�Ʈ-\n");
	insert_first(&list1, 9); print_list(&list1);
	insert_last(&list1, 99); print_list(&list1);
	
	insert_first(&list1, 1); print_list(&list1);
	
	printf("���̴� %d\n", get_length(&list1));
	printf("3��° ����Ÿ�� %d\n", get_entry(&list1, 2));
	
	replace(&list1, 3, 40); print_list(&list1);
	printf("20�� ����Ʈ�� %s\n", is_in_list(&list1, 20) ? "�ֽ��ϴ�" : "�����ϴ�");
	printf("22�� ����Ʈ�� %s\n", is_in_list(&list1, 22) ? "�ֽ��ϴ�" : "�����ϴ�");
	
	delete_by_key(&list1, 20); print_list(&list1);
	delete_by_key(&list1, 22); print_list(&list1);

	return 0;
}