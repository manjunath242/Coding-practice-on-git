#ifndef NODE_H
#define NODE_H

/* node for link list */
//author manjunath shivanna

#endif
class Node
{
public:
	Node * next;
	int value;
	Node();
	Node(int val);
	void Add(int val)
	{
		this->next = new Node(val);
	}
	~Node();
};

