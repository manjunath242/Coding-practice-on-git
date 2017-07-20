#include "stdafx.h"
#include "Node.h"


Node::Node()
{
}
Node::Node(int val)
{
	this->value = val;
}


Node::~Node()
{
	delete next;
}
