#ifndef LINKED_LIST_H
#define LINKED_LIST_H


#include <stdbool.h>

typedef int DataType;
typedef struct node Node;

typedef struct node {
	DataType data;           
	Node* next;  
} Node;

// 定义链表结构
typedef struct {
	Node* head;  // 头指针
	Node* tail;  // 尾指针
	int size;  // 用于记录链表的长度
} LinkedList;

LinkedList* create_linked_list(); // 创建链表

void destroy_linked_list(LinkedList* list);           // 销毁链表

bool insert_at_head(LinkedList* list, DataType data);        // 头部插入结点
bool insert_at_tail(LinkedList* list, DataType data);        // 尾部插入结点
bool insert_at_index(LinkedList* list, int index, DataType data); // 按索引插入结点

Node* search_by_index(LinkedList* list, int index);          // 根据索引搜索结点
Node* search_by_value(LinkedList* list, DataType val);             // 根据数据搜索结点

bool delete_node_by_val(LinkedList* list, DataType val);         // 根据数据删除结点
bool delete_by_idx(LinkedList* list, int idx);         // 根据索引删除结点

bool delete_at_head(LinkedList* list);
bool delete_at_tail(LinkedList* list);

bool removeConsecutiveDuplicates(LinkedList* list);
bool is_palindrome_linked_list(LinkedList* list);

bool traverse_list(LinkedList* list); //遍历输出链表

#endif // !LINKED_LIST_H