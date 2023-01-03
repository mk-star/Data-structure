#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
typedef int element;
typedef struct ListNode {
	element data;
	struct ListNode* link;
}ListNode;
void error(char* message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}
int is_in_list(ListNode* head, element item)
{
	ListNode* p = head;
	while (p != NULL) {
		if (p->data == item)
			return 1;
		p = p->link;
	}
	return 0;
}
int get_length(ListNode* head)
{
	ListNode* p = head;
	int len = 0;
	while (p != NULL) {
		p = p->link;
		len++;
	}
	return len;
}
int get_total(ListNode* head)
{
	ListNode* p = head;
	int total = 0;
	while (p != NULL) {
		total += p->data;
		p = p->link;
	}
	return total;
}
ListNode* insert_first(ListNode* head, int value)
{
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	p->data = value;
	p->link = head;
	head = p;
	return head;
}
ListNode* insert_pos(ListNode* head, int pos, element value)
{
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	ListNode* temp = head;
	ListNode* pre = NULL;
	p->data = value;
	p->link = NULL;
	int index = 0;
	if (pos < 0 || get_length(head) < pos)
		printf("위치 오류\n");
	else {
		if (head == NULL)
			head = p;
		else {
			while (temp != NULL) {
				if (pos == index) {
					p->link = pre->link;
					pre->link = p;
				}
				pre = temp;
				temp = temp->link;
				index++;
			}
		}
		return head;
	}
}
ListNode* delete_first(ListNode* head)
{
	ListNode* removed;
	if (head == NULL)
		printf("삭제할 항목이 없음\n");
	else {
		removed = head;
		head = removed->link;
		free(removed);
	}
	return head;
}
ListNode* delete_last(ListNode* head)
{
	ListNode* temp = head;
	ListNode* prevTemp = NULL;
	ListNode* removed;
	if (head == NULL)
		printf("삭제할 항목이 없음");
	else {
		if (head->link == NULL) {
			removed = head;
			head = NULL;
		}
		else {
			while (temp->link != NULL) {
				prevTemp = temp;
				temp = temp->link;
			}
			removed = temp;
			prevTemp->link = NULL;
		}
		free(removed);
	}
	return head;
}
ListNode* delete_by_key(ListNode* head, int key)
{
	ListNode* temp = head;
	ListNode* prevTemp;
	ListNode* removed = NULL;
	int index = 0;
	if (!is_in_list(temp, key))
		printf("잘못된 입력");
	else {
		if (head->data == key)
			head = delete_first(head);
		else {
			while (temp->link != NULL) {
				prevTemp = temp;
				temp = temp->link;
				if (temp->data == key) {
					removed = temp;
					prevTemp->link = temp->link;
				}
			}
			free(removed);
		}
	}
	return head;
}
ListNode* delete_pos(ListNode* head, int pos)
{
	ListNode* temp = head;
	ListNode* prevTemp;
	ListNode* removed = NULL;
	int index = 0;
	if (pos < 0 || get_length(temp) <= pos)
		printf("잘못된 위치");
	else {
		if (pos == 0)
			head = delete_first(head);
		else if (pos == get_length(temp) - 1)
			head = delete_last(head);
		else {
			while (temp->link != NULL) {
				index++;
				prevTemp = temp;
				temp = temp->link;
				if (pos == index) {
					prevTemp->link = temp->link;
					removed = temp;
				}
			}
			free(removed);
		}
	}
	return head;
}
element get_entry(ListNode* head, int pos)
{
	ListNode* p = head;
	int index = 0;
	if (head == NULL)
		error("찾을 항목이 없음");
	while (p != NULL) {
		if (pos == index)
			return p->data;
		p = p->link;
		index++;
	}
}
ListNode* concat(ListNode* head1, ListNode* head2)
{
	ListNode* p = head1;
	if (head1 == NULL)
		return head2;
	else if (head2 == NULL)
		return head1;
	else {
		while (p->link != NULL)
			p = p->link;
		p->link = head2;
		return head1;
	}
}
void print_list(ListNode* head)
{
	for (ListNode* p = head; p != NULL; p = p->link)
		printf("%d->", p->data);
	printf("NULL\n");
}
int main(void)
{
	ListNode* list1 = NULL, * list2 = NULL, * list3 = NULL;

	list1 = insert_first(list1, 10);
	list1 = insert_first(list1, 20);
	list1 = insert_first(list1, 30);
	printf("list1 = ");
	print_list(list1);

	list1 = delete_first(list1);
	printf("list1 = ");
	print_list(list1);

	list2 = insert_first(list2, 44);
	list2 = insert_first(list2, 33);
	list2 = insert_first(list2, 22);
	list2 = insert_first(list2, 11);
	printf("list2 = ");
	print_list(list2);
	
	list2 = delete_last(list2);
	printf("list2 = ");
	print_list(list2);

	int len = get_length(list2);
	for (int i = 0; i < len; i++)
		list3 = insert_first(list3, get_entry(list2, i));
	printf("list3 = ");
	print_list(list3);

	list1 = concat(list1, list3);
	printf("list1 = ");
	print_list(list1);

	printf("is in list? ");
	if (is_in_list(list1, 10))
		printf("Yes\n");
	else
		printf("No\n");

	printf("list1의 length: %d\n", get_length(list1));
	printf("list1의 total: %d\n", get_total(list1));
	printf("list1의 %d자리 값은 %d\n", 3, get_entry(list1, 2));
	list1 = delete_by_key(list1, 11);
	print_list(list1);
	list1 = insert_pos(list1, 2, 50);
	print_list(list1);
	list1 = delete_pos(list1, 0);
	print_list(list1);

	return 0;
}