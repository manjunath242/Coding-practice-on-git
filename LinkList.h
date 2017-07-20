#ifndef LINKLIST_H
#define LINKLIST_H
#endif 

#include "Node.h"



class LinkList
{
private:
	Node * end=NULL;
	Node * start = NULL;
	
public:
	LinkList();
	~LinkList();
	void Add(int val);
	int Delete();
};

