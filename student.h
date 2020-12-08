#ifndef STUDENT_H_INCLUDED
#define STUDENT_H_INCLUDED
#include <stdint.h>
#include "const.h"

typedef struct _node_ Node;
struct _node_{
	char name[STUDENT_NAME_LEN];
	int32_t marks;
	char program[PROGRAM_NAME_LEN];
	char grade;
	Node *next;
};


typedef struct _slist_ Slist;
struct _slist_{
	Node *head;
	Node *tail;
	Node *max_marks;
	uint32_t length;
};

Slist slist_new();
uint8_t slist_lookup(const Slist *list,int32_t key);
uint32_t slist_length(const Slist *list);
Slist* slist_addnode_tail(Slist *list,int32_t marks, char name[STUDENT_NAME_LEN], char program[PROGRAM_NAME_LEN], char grade);
Node* slist_max(Slist *list);
#endif // STUDENT_H_INCLUDED
