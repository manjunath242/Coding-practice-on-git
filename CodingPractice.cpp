// CodingPractice.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <numeric> // for std::accumulate
#include<math.h>

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

int Solution8(string str)
{
	long overflow = 2147483647;
	long result = 0;
	bool negative = false;
	int temp = -1;

	//str.erase(std::remove(str.begin(), str.end(), ' '),
   //str.end());

	if ((str.size() >= 2) && (str.at(0) == '-'))
	{
		negative = true;
	}

	for (int i = 0;i<str.size();i++)
	{
		if (i == 0 && (str.at(i) == '-' || str.at(i) == '+'))
		{
			continue;
		}

		temp = CharToInt(str.at(i));
		if (temp == -1) break;
		else if (temp == 0)
			if (result == 0) continue;
			else result = result * 10;

		else
		{
			result = (result * 10) + temp;
		}

	}

	if (negative)
	{
		result = result*-1;

		if (result<-2147483647) return 0;
	}

	if (result > 2147483647) return 0;
	if (result == 0) return 0;

	return (int)result;

}

int CharToInt(const char c)
{
	switch (c)
	{
	case '0':
		return 0;
	case '1':
		return 1;
	case '2':
		return 2;
	case '3':
		return 3;
	case '4':
		return 4;
	case '5':
		return 5;
	case '6':
		return 6;
	case '7':
		return 7;
	case '8':
		return 8;
	case '9':
		return 9;
	default:
		return -1;
	}
}
	

int Solution7(int x) {

	long result = 0;
	int place = 0;
	int temp ;
	bool contin = true, negative = false;


	if ((x> INT_MAX) || (x< INT_MIN) || x == 0)
	{
		return 0;
	}

	if (x<0)
	{
		negative = true;
		x = (x*-1);
	}

	temp = x;

	while (temp >= 10)
	{
		temp = temp / 10;
		place++;
	}

	while (place>=0)
	{
			result = result + ((x % 10)*(pow(10, place)));
			x = x / 10;
			place--;
	}
	if (negative) result = result *(-1);

	if (result > INT_MAX || result < INT_MIN)
	{
		return 0;
	}

	return result;

}

//zig zag string convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR". PAHNAPLSIIGYIR
//P   A   H   N
//A P L S I I G
//Y   I   R

//0          11         21         31
//1 7         12 18     22 28      32
//a          k          u          f
//b g        l q        v a        g
//c   h      m   r      w   b      h
//d     i    n     s    x     c    
//e       j  o       t  y       d  
//f          p          z       

//akubglqvchmrwdinsxejotyfpz
//akubglqvchmrwdinsxejotyfpz
//a             p
//b  j          q
//c    k        r
//d      l      s
//e        m    t
//f          n  u
//g             v

//A 
//B 
//C E
//D
string Solution6(string input, int rows)
{
	string result;
	int size = input.length();
	int columnDeterminer ;

	if (size == 0 || size == 1 || rows == 1 || rows>=size )
	{
		return input;
	}


		columnDeterminer = rows + (rows - 2);
	
	int appxTowers = size / columnDeterminer;


	//appxTowers = size / ((rows*2)-1);



	//for columns
	for (int i = 0;i < rows;i++)
	{
		int isAccecible;

		if (((i) % (rows - 1)) == 0)
		{
			for (int j = 0;j <= (appxTowers);j++)
			{
				isAccecible = (columnDeterminer * j)+i ;
				if (isAccecible < size)
				{
					result.push_back(input.at((columnDeterminer * j) +i));
				}
				
			}
		}
		else
		{
			for (int j = 0;j <= (appxTowers);j++)
			{
				 isAccecible = ((columnDeterminer * j) + i) ;
				if (isAccecible < size)
				{
					result.push_back(input.at((columnDeterminer * j) + i));
				}
				isAccecible = ((columnDeterminer * j) + i) + (rows - 1);

				if (isAccecible < size)
				{
					result.push_back(input.at(((columnDeterminer * j) + i) + (rows - 1)));
				}

			}
		}

	}

	return result;
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

	//Solution5("aaaa");

	//Solution6("ABCDE", 4);

	Solution7(-2147483648);

    return 0;
}

