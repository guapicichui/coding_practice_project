#ifndef LINKED_LIST_H
#define LINKED_LIST_H


#include <stdbool.h>

typedef int DataType;
typedef struct node Node;

typedef struct node {
	DataType data;           
	Node* next;  
} Node;

// ��������ṹ
typedef struct {
	Node* head;  // ͷָ��
	Node* tail;  // βָ��
	int size;  // ���ڼ�¼����ĳ���
} LinkedList;

LinkedList* create_linked_list(); // ��������

void destroy_linked_list(LinkedList* list);           // ��������

bool insert_at_head(LinkedList* list, DataType data);        // ͷ��������
bool insert_at_tail(LinkedList* list, DataType data);        // β��������
bool insert_at_index(LinkedList* list, int index, DataType data); // ������������

Node* search_by_index(LinkedList* list, int index);          // ���������������
Node* search_by_value(LinkedList* list, DataType val);             // ���������������

bool delete_node_by_val(LinkedList* list, DataType val);         // ��������ɾ�����
bool delete_by_idx(LinkedList* list, int idx);         // ��������ɾ�����

bool delete_at_head(LinkedList* list);
bool delete_at_tail(LinkedList* list);

bool removeConsecutiveDuplicates(LinkedList* list);
bool is_palindrome_linked_list(LinkedList* list);

bool traverse_list(LinkedList* list); //�����������

#endif // !LINKED_LIST_H