#include <stdio.h>
#include <stdlib.h>
#include "func.h"
#include "stu_grade_mgr.h"

node* stu_list = NULL;


//  创建一个链表
node* create(void)
{
	node* n = (node*)malloc(sizeof(node));
	n->next = NULL;
	
	return n;
}



//  销毁链表
void destroy(node* l)
{
	node* p = NULL;

	while(l->next != NULL)
	{
		p = l->next;
		free(l);
		l = p;
	}
}


//  尾插
void push_data(node* l, stu data)
{
	node* n = (node*)malloc(sizeof(node));
	n->next = NULL;
	n->data = data;
	while(l->next != NULL)
	{
		l = l->next;
	}
	l->next = n;
}
