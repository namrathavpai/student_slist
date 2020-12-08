#include <stdlib.h>
#include <assert.h>
#include "student.h"


Slist  slist_new(){
	Slist s1 = {NULL,NULL,0,NULL};
	return s1;
}

uint32_t slist_length(const Slist *list){
    assert(list != NULL);
	return list->length;
}

static Node* _get_new_node_(int32_t marks, char name[STUDENT_NAME_LEN], char program[PROGRAM_NAME_LEN], char grade){
	Node *newnode = (Node*)malloc(sizeof(Node));
	newnode->name[STUDENT_NAME_LEN]=name[STUDENT_NAME_LEN];
	newnode->program[PROGRAM_NAME_LEN]=program[PROGRAM_NAME_LEN];
	newnode->grade=grade;
	newnode->marks=marks;
	newnode->next=NULL;
	return newnode;
}

Slist* slist_addnode_tail(Slist *list, int32_t marks, char name[STUDENT_NAME_LEN] ,char program[PROGRAM_NAME_LEN], char grade){
	assert(list!=NULL);
	Node *new_node = _get_new_node_(marks,name,program,grade);
	if(list->tail !=NULL){
		list->tail->next=new_node;
		list->tail=new_node;
	}else{
		list->head = list->tail = new_node;       // when we add node for first time
	}
	++list->length;
	if(list->max_marks == NULL){
        list->max_marks=new_node;
	}
	else if (list->max_marks->marks < new_node->marks){
        list->max_marks = new_node;
	}

	assert( (list->length == 1) && (list->head == list->tail) || (list->length>1) && (list->head)!=list->tail);
	return list;
}

Node* slist_max(Slist *list){
    assert(list!=NULL);
	return list->max_marks;
}
