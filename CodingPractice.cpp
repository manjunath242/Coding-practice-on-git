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

//give longest unique substring
string Solution3(string input)
{
	string lngUnique="";
	string tmpUnique="";
	int length=0;




	for (int i = 0;i < input.length();i++)
	{
		auto pos = tmpUnique.find(input.at(i));
			if (pos<tmpUnique.length())
			{

				if (i != (input.length() - 1))
				{
					i = i - (length);
				}
				length = 0;
				tmpUnique = "";
			}
			else
			{
				tmpUnique.append(&input.at(i),1);
				length++;

			}

			if ((tmpUnique != lngUnique) && (length > lngUnique.length()))
			{
				lngUnique = tmpUnique;
			}


	}

	return lngUnique;
	// abcdabcdefabd
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

//longest palindrome substring in input
string Solution5(string input)
{
	int length = 0;
	string tempPalin="";
	string longestPalin="";


	if ((input.length()==1)|| (input.length()==0))
	{
		return input;
	}

	else if (input.length() == 2)
	{
		//string tempstr = input;
		//	reverse(toBeReversed.begin(),
		//		toBeReversed.end());

		if (input.at(0)==input.at(1))
		{
			return input;
		}
		else
		{
			return input.substr(0, 1);
		}
	}
	else
	{
		//abcdabbaa
		//abdbbddbb 9-6
		for (int i = 1;i < (input.length());i++)
		{
			tempPalin = input.at(0);

			if (((input.length() - i)*2)> longestPalin.length())
			{

				if (input.at(i) == input.at(i - 1))
				{
					length = 2;
					tempPalin = input.substr(i - 1, length);
					for (int j = 1;j < input.length();j++)
					{
						if (((i - j - 1) < 0) || ((i + j) >= input.length()))
						{
							break;
						}
						else if ((input.at(i + j) == input.at(i - j - 1)))
						{
							length = length + 2;
							tempPalin = input.substr(i - j - 1, length);
						}
						else
						{
							break;
						}
					}

				}

				//abcdcba

					if ((i+1)<input.length())
					{
						if (input.at(i + 1) == input.at(i - 1))
						{
							length = 3;
							tempPalin = input.substr(i - 1, length);
							for (int j = 2;j < input.length();j++)
							{
								if (((i - j) <= 0) || ((i + j) >= input.length()))
								{

									break;
								}
								else if ((input.at(i + j) == input.at(i - j)))
								{
									length = length + 2;
									tempPalin = input.substr(i - j, length);

								}

								else
								{
									break;
								}
							}
						}

					}
					if ((i + 2) < input.length())
					{
						if ((input.at(i + 1) == input.at(i)) &&(input.at(i)== input.at(i - 1)))
						{
							length = 3;
							tempPalin = input.substr(i - 1, length);
							for (int j = i+2;j < input.length();j++)
							{
								if (input.at(i) == input.at(j) )
								{
									length = length ++;
									tempPalin = input.substr(i - 1, length);

								}

								else
								{
									break;
								}
							}
						}
					}

				if (tempPalin.length() > longestPalin.length())
				{
					longestPalin = tempPalin;
				}

			}
			else
			{
				break;
			}
		}
	}

	return longestPalin;
	//abcddcba

}

int main()
{
	//StringBuilder();
	//AllUnique();
	//testVague();

	//Started doing leetcoed
	//Solution2 sol;
	//sol.Test2();

	//Solution4 sol4;
	//sol4.findMedianSortedArrays();

	//Solution3("abcdabcde");

	Solution5("aaaa");

    return 0;
}

