#pragma once
#include "Node.h"
class Solution2
{
public:
	Solution2();
	~Solution2();

	void Test()
	{
		Node *l1, *l2;
		l1 = new Node(9);
		l2 = new Node(9);
		Node *l3 = addTwoNumbers(l1, l2);
	}

	Node* Test2()
	{
		Node *l1, *l2,*start1,*start2;
		l1 = new Node(1);
		start1 = l1;
		l1->next = new Node(8);
		l1 = start1;

		l2 = new Node(0);
		start2 = l2;


		Node * l3 = NULL;
		Node * start = NULL;
		int carry = 0;
		int temp = 0;

		while (1)
		{

			Node * first, *second;

			if (start == NULL)
			{
				temp = l1->value + l2->value;
				carry = temp / 10;
				temp = temp % 10;
				l3 = new Node(temp);
				start = l3;


			}
			else {
				if ((l1->next == NULL) || (l2->next == NULL))
				{
					if ((l1->next == NULL) && (l2->next == NULL))
					{
						//temp = l1->value + l2->value + carry;
						//l3->next = new Node(temp);
						//carry = temp / 10;
						if (carry != 0)
						{
							l3->next = new Node(carry);
						}
						break;
					}

					if (l1->next == NULL) { 
						first = l1; second = l2; 
					second = second->next;
					l2 = l2->next;
					temp = second->value + carry;
					}
					else { 
						first = l2; second = l1; 
					second = second->next;
					l1 = l1->next;
					temp = second->value + carry;
					}

				}

				else {
					l1 = l1->next;
					l2 = l2->next;
					temp = l1->value+l2->value + carry;


				}


				carry = temp / 10;
				temp = temp % 10;

				if ((carry != 0) && (temp == 0))
				{
					l3->next = new Node(0);
					l3 = l3->next;
				}

				else
				{
					l3->next = new Node(temp);
					l3 = l3->next;
				}



			}

		}
		return start;
	}

	Node* addTwoNumbers(Node* l1, Node* l2) {
		Node* result = nullptr;
		Node* start = nullptr;

		int exp = 1;

		long num1 = 0;
		long num2 = 0;
		int tempval = 0;

		if (l1->next == NULL)
		{
			num1 = l1->value;
		}

		else
		{
			while (l1->next != NULL)
			{
				num1 = num1 + ((l1->value)*exp);
				exp = exp * 10;
				l1 = l1->next;

			}
			num1 = num1 + ((l1->value)*exp);
		}

		exp = 1;

		if (l2->next == NULL)
		{
			num2 = l2->value;

		}

		else
		{
			while (l2->next != NULL)
			{
				num2 = num2 + ((l2->value)*exp);
				exp = exp * 10;
				l2 = l2->next;

			}
			num2 = num2 + ((l2->value)*exp);

		}

		num2 = num2 + num1;
		while ((num2 / 10) != 0)
		{
			tempval = num2 % 10;
			if (result == nullptr)
			{
				result = new Node(tempval);
				start = result;
			}
			else {
				result->next = new Node(tempval);
				result = result->next;
			}

			num2 = num2 / 10;

		}

		if (result == nullptr)
		{
			result = new Node(num2);
			start = result;
		}

		else
		{
			result->next = new Node(num2);
		}

		return start;

	}
};

