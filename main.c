#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "student.h"

void test_add_at_tail(){
	Slist s1 = slist_new();
	Slist *list = &s1;
	assert(slist_length(list)==0);
	list = slist_addnode_tail(list,10,"namratha","BDA","C");
	assert(slist_length(list)==1);
	list=slist_addnode_tail(list,20,"ram","ML","B");
	list=slist_addnode_tail(list,30,"bharat","ML","A");
	assert(slist_length(list)==3);
}

void test_max(){
	Slist s1=slist_new();
	Slist *list = &s1;
	assert(slist_length(list)==0);
	list=slist_addnode_tail(list,10,"namratha","BDA","C");
	assert(slist_length(list)==1);
	list=slist_addnode_tail(list,20,"ram","ML","B");
	list=slist_addnode_tail(list,30,"bharat","ML","A");
	assert(slist_length(list)==3);
	Node* max=slist_max(list);
	assert(max->marks==30);
}

int main()
{
    test_add_at_tail();
    test_max();
    //printf("Hello world!\n");
    return 0;
}
