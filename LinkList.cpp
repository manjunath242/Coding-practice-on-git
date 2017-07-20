#include "stdafx.h"
#include "LinkList.h"


LinkList::LinkList()
{
}


LinkList::~LinkList()
{
}

void LinkList::Add(int val)
{
	if (start == NULL)
	{
		start = new Node(val);
		end = start;
		end->next = NULL;
	}
	if (start != NULL)
	{
		end->next = new Node(val);
		end = end->next;
	}
}

int LinkList::Delete()
{
	return 0;
}
