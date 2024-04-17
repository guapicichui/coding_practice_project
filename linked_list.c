#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

LinkedList* create_linked_list()
{
	LinkedList* list = (LinkedList*)malloc(sizeof(LinkedList));
	if (list == NULL) {
		printf("error: malloc failed.\n");
		exit(-1);
	}
	list->head = NULL;
	list->size = 0;
	list->tail = NULL;
	return list;

}


void destroy_linked_list(LinkedList* list)
{
	Node* temp;
	while (list->head != NULL)
	{
		temp = list->head;
		list->head = list->head->next;
		free(temp);
	}
	list->tail = NULL;
	free(list);
	return;
}

static Node* create_node(DataType val) // 私有 创建一个结点
{
	Node* new_node = (Node*)malloc(sizeof(Node));
	if (new_node == NULL) {
		printf("error: malloc failed.\n");
		return NULL;
	}
	new_node->data = val;
	new_node->next = NULL;
	return new_node;
}

bool insert_at_head(LinkedList* list, DataType data) //头插法
{
	Node* new_node = create_node(data);
	if (new_node == NULL)
	{
		printf("error: insert_head failed.\n");
		return false;
	}
	if (list->size == 0)
	{
		new_node->next = list->head;
		list->head = new_node;
		list->tail = new_node;
		list->size++;
		return true;
	}
	new_node->next = list->head;
	list->head = new_node;
	list->size++;
	return true;
}

bool insert_at_tail(LinkedList* list, DataType data)  //尾插法
{
	Node* new_node = create_node(data);
	if (new_node == NULL)
	{
		printf("error: insert_tail failed.\n");
		return false;
	}
	if (list->tail == NULL)
	{
		list->head = new_node;
		list->tail = new_node;
		list->size++;
		return true;
	}
	new_node->next = list->tail->next;
	list->tail->next = new_node;
	list->tail = list->tail->next;
	list->size++;
	return true;

}

bool insert_at_index(LinkedList* list, int index, DataType data) //按索引插入
{
	if (index<0 || index>list->size)
	{
		printf("error! illegal index!\n");
		return false;
	}
	if (list->head == NULL)
	{
		printf("error! linkedlist is null!\n");
	}
	if (list->head == NULL)
	{
		Node* new = create_node(data);
		if (new == NULL)
		{
			printf("error: insert_index failed.\n");
			return false;
		}
		new->next = list->head;
		list->head = new;
		list->size++;
		return true;
	}
	Node* temp = list->head;
	if (index == 0)
	{
		Node* new = create_node(data);
		new->next = list->head;
		list->head = new;
		list->size++;
		return true;
	}
	for (int i = 0; i < index - 1; i++)
	{
		temp = temp->next;
	}
	Node* new = create_node(data);
	if (new == NULL)
	{
		printf("error: insert_index failed.\n");
		return false;
	}
	new->next = temp->next;
	temp->next = new;
	if (index == list->size)
		list->tail = new;
	list->size++;

	return true;
}


Node* search_by_index(LinkedList* list, int index)  //按索引查找
{
	if (index<0 || index>list->size)
	{
		printf("error! illegal index!\n");
		return NULL;
	}

	if (list->head == NULL)
	{
		printf("error! linkedlist is null!\n");
		return NULL;
	}

	Node* temp = list->head;
	for (int i = 0; i < index; i++)
	{
		temp = temp->next;
	}
	return temp;

}
Node* search_by_value(LinkedList* list, DataType val) // 按值查找
{
	if (list->head == NULL)
	{
		printf("error! linkedlist is null!\n");
		return NULL;
	}
	Node* temp = list->head;
	while (temp != NULL)
	{
		if (temp->data == val)
			return temp;
		temp = temp->next;
	}
	printf("the value %d not exist!\n", val);
	return NULL;
}

static void delete_node(Node* prev_node)
{
	Node* temp = prev_node->next;
	prev_node->next = prev_node->next->next;
	free(temp);
	return;
}

static void delete_head(LinkedList* list)
{
	if (list->size == 1)
	{
		Node* temp = list->head;
		list->head = NULL;
		list->tail = NULL;
		list->size--;
		free(temp);
		return;
	}

	Node* temp = list->head;
	list->head = list->head->next;
	list->size--;
	free(temp);
	return;
}

bool delete_node_by_val(LinkedList* list, DataType val) //按值删除结点
{
	if (list->head == NULL)
	{
		printf("error! linkedlist is null!\n");
		return false;
	}
	Node* temp = list->head;
	if (temp->data == val)
	{
		delete_head(list);
		return true;
	}
	Node* prev = temp;
	temp = temp->next;
	while (temp != NULL)
	{
		if (temp->data == val)
		{
			delete_node(prev);
			list->size--;
			return true;
		}
		prev = temp;
		temp = temp->next;
	}
	printf("the value %d is not exist", val);
	return false;
}

bool delete_by_idx(LinkedList* list, int index)  //按索引删除
{
	if (list->head == NULL)
	{
		printf("error! linkedlist is null!\n");
		return false;
	}

	if (index<0 || index>list->size)
	{
		printf("error! illegal index!\n");
		return false;
	}
	if (index == 0)
	{
		delete_head(list);
		return true;
	}

	Node* temp = list->head;
	for (int i = 0; i < index - 1; i++)
	{
		temp = temp->next;
	}

	delete_node(temp);
	list->size--;

	return true;
}

bool traverse_list(LinkedList* list)
{
	if (list == NULL)
	{
		printf("the list is null\n");
		return false;
	}
	Node* temp = list->head;
	for (int i = 0; i < list->size; i++)
	{
		printf("%d->", temp->data);
		temp = temp->next;
	}
	printf("NULL\n");
	return true;
}

bool removeConsecutiveDuplicates(LinkedList* list)
{
	if (list == NULL || list->head == NULL)
		return false;
	Node* prev = list->head;
	Node* curr = list->head->next;
	bool test = false;
	while (curr != NULL)
	{
		if (curr->data == prev->data)
		{
			Node* temp = curr;
			prev->next = curr->next;
			curr = curr->next;
			free(temp);
			list->size--;
			test = true;
			continue;
		}
		prev = curr;
		curr = curr->next;
	}
	return test;
}

bool is_palindrome_linked_list(LinkedList* list)
{
	if (list == NULL || list->head == NULL)
		return false;
	Node* fast, * slow, * temp;
	slow = temp = list->head;
	fast = list->head;
	while (fast != NULL && fast->next != NULL)
	{
		fast = fast->next->next;
		temp = slow;
		slow = slow->next;
	}
	if (slow == list->head && fast->next == NULL)
	{
		return true;
	}
	//至此只有一个结点的特殊情况已经考虑完，fast走到了链表末尾，判断链表是奇数还是偶数
	if (fast == NULL)
	{
		slow = temp;//如果链表偶数 回溯slow指针
	}
	//反转后半部分链表，固定slow不动，使用头插法，将后续结点插入slow后面
	temp = temp->next;
	Node* q = temp;
	while (temp != NULL)
	{
		Node* p = temp->next;
		temp->next = slow->next;
		slow->next = temp;
		temp = p;
	}
	q->next = NULL;
	//反转完成 开始判断
	fast = list->head;
	slow = slow->next;
	while (slow != NULL)
	{
		if (slow->data == fast->data) {
			slow = slow->next;
			fast = fast->next;
			continue;
		}
		return false;
	}

	return true;
}