// CodingPractice.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <numeric> // for std::accumulate

//leetcode
#include "Solution2.h"
#include "Solution4.h"

using namespace std;


void Test1()
{
	string test_string;

}

void StringBuilder()
{
	string input="";
	vector<string> stringBuilder;
	string s;

	while (input != "-1")
	{
		cout << "Enter stringinput" << endl;
		cin >> input;
		stringBuilder.push_back(input);
		 s = accumulate(stringBuilder.begin(), stringBuilder.end(), s);
	}

	for (vector<string>::iterator it = stringBuilder.begin();it != stringBuilder.end();it++)
	{
		cout << *it<<" ";
	}
	cout << s;
}

void AllUnique()
{
	string uniqStr;
	cout << "Input string to be checked for uniqueness" << endl;
	cin >> uniqStr;
	//char temp = uniqStr[0];
	string tempstr;
	for (int i = 0;i < uniqStr.length()-1;i++)
	{
		 tempstr = uniqStr.substr(i + 1, uniqStr.length() - 1);
		if (tempstr.find(uniqStr[i],sizeof(char)))
		{
			cout << "not unique"<<endl;
			break;
		}
	}

	cout << "unique" << endl;

}

void testVague()
{
	int x=0, y; y = 20;
	y = y++;
	cout << x<<endl;
	cout << y << endl;

	switch (x)
	{
	case 1: cout << "yo1" << endl; break;
	case 0: cout << "yo0"<<endl; break;
	default: cout << "take that sucker" << endl; 
	}

	enum Color { red, green, blue };
	Color r=red;
	switch (r)
	{
	case red: std::cout << "red\n";   break;
	case green: std::cout << "green\n"; break;
	case blue: std::cout << "blue\n";  break;
	}

	int thearray[10];
	thearray[0] = 0;


}

int main()
{
	//StringBuilder();
	//AllUnique();
	//testVague();

	//Started doing leetcoed
	//Solution2 sol;
	//sol.Test2();

	Solution4 sol4;
	sol4.findMedianSortedArrays();

    return 0;
}

