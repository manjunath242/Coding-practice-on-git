// CodingPractice.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <numeric> // for std::accumulate
#include<math.h>
#include <sstream>
#include <unordered_map>

//leetcode
#include "Solution2.h"
#include "Solution4.h"

using namespace std;


//Sorted BST problem
 struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	
};

TreeNode* FormHeightBalancedBST(TreeNode* root,vector<int> sortedInput)
{
	int mid;
	TreeNode* tr;

	if (sortedInput.size() % 2 == 0)
	{
		mid = sortedInput.size() / 2;
	}
	else
	{
		mid = (sortedInput.size() / 2)+1;
	}

	 
	vector<int> newSortedInputL = vector<int>(sortedInput.begin(), sortedInput.begin() + mid);
	vector<int> newSortedInputR = vector<int>(sortedInput.begin() + mid+1, sortedInput.end());

	if (sortedInput.size() == 1)
	{
		root = new TreeNode(sortedInput[0]);
		return root;
	}

	else if (sortedInput.size() == 2)
	{
		root->left = new TreeNode(sortedInput[0]);
		root->right = new TreeNode(sortedInput[1]);
	}

	else
	{
		 FormHeightBalancedBST(root->left, newSortedInputL);
		 FormHeightBalancedBST(root->right, newSortedInputR);

		 return root;
	}





}



//solution249
vector<vector<string>> groupStrings(vector<string>& strings) {

	vector<vector<string>> result;
	std::unordered_map<int, vector<string>> resultmap;


	for (int i = 0;i<strings.size();i++)
	{
		char temp = strings[i][0];
		for (int j = 0;j<strings[i].size();j++)
		{
			if (temp != strings[i][j])
			{
				vector<string> row;
				if (resultmap.count(strings[i].size() * 10) == 1)
				{
					row = resultmap[strings[i].size() * 10];
					row.push_back(strings[i]);
					resultmap[strings[i].size() * 10] = row;
				}

				else {
					row.push_back(strings[i]);
					resultmap.insert(std::make_pair(strings[i].size() * 10, row));
				}
				break;
			}
			else
			{
				if (j == strings[i].size() - 1)
				{
					vector<string> row;

					if (resultmap.count(strings[i].size()) == 1)
					{
						row = resultmap[strings[i].size()];
						row.push_back(strings[i]);
						resultmap[strings[i].size()] = row;

					}
					else {
						row.push_back(strings[i]);
						resultmap.insert(std::make_pair(strings[i].size(), row));

					}
				}
				if (temp == 'z')
				{
					temp = 'a';
				}
				else
				{
					temp++;
				}
			}

		}

	}


	for (auto it = resultmap.begin(); it != resultmap.end(); ++it)
		result.push_back(it->second);

	return result;

}

//hrank mock
void MoveZeros()
{
	vector<int> nums;
	int *p1, *p2;
	int zerocount = 0;
	if (nums.size() > 1)
	{
		p1 = &nums[0];
		p2 = &nums[1];

		while (p2 != &nums[nums.size() - 1])
		{
			//if()
		}
	}

}


//mappingProblem
unordered_map<string,int> rankmap;
unordered_map<string, vector<string>> temp;

int maxrank = 0;


 vector<vector<string>> stepsFunction;
void Funcall(string event, int rank);

void MappingSol()
{
	
	
	vector<vector<string>> result;

	vector<string> currentSet;
	for (int i = 0;i < stepsFunction.size();i++)
	{
		if (temp.count(stepsFunction[i][0]))
		{
			currentSet = temp[stepsFunction[i][0]];
		}

			currentSet.push_back(stepsFunction[i][1]);
			temp[stepsFunction[i][0]] = currentSet;
	}

	for (unordered_map<string, vector<string>  >::const_iterator iter = temp.begin();
	iter != temp.end(); ++iter)
	{
		Funcall(iter->first, 0);
	}

	vector<string> row;
	for (int i = 0;i < maxrank;i++)
	{
		result.push_back(row);
	}
	for (unordered_map<string, int  >::const_iterator iter = rankmap.begin();
	iter != rankmap.end(); ++iter)
	{	int position = iter->second;
		row = result[position];
		row.push_back(iter->first);
		result[position] = row;
	}
	return ;
}

void Funcall(string event, int rank)
{
	vector<string> events;

	if (rank > maxrank) maxrank = rank;
	if (!temp.count(event))
	{
		return;
	}
	else
	{		rank++;
		for (int i = 0;i < temp[event].size();i++)
		{
			if (rank > rankmap[event])
				rankmap[event] = rank;
			Funcall(temp[event][i], rank);
		}
	}
}





//1234, 2341, 3412, 4123
//2134, 1342, 3421, 4213
//3124, 1243, 2431, 4312
//1324, 3241, 2413, 4132
//

vector<int> Permutation(vector<int> numbers)
{
	vector<int> temp;

	if (numbers.size() == 1)
	{
		temp.push_back(numbers[0]);
	}
	else
	{
		for (int i = 0;i < numbers.size();i++)
		{
			temp.push_back(i);
		}
	}

	return temp;

}

//permutation
void Solution46()
{
	vector<int> numbers;




}

//group anagrams

void Solution49()
{
	vector<string> input;
	vector<vector<string>> result;
	int resultCounter;
	int charCounter;

	for (int i = 0;i < input.size();i++)
	{
		if (input[i] != "")
		{
			for (int j = i + 1;j < input.size();j++)
			{
				// work on it later


			}
		}

	}

}

//first missing positive
int Solution41()
{
	vector <int> input;

	input.push_back(1);
	input.push_back(2);
	input.push_back(3);
	input.push_back(5);

	vector <int> filterinput;
	int result;
	int min, max;
	bool minmaxSet = false;
	int range;
	if (input.size() > 0)
	{
		min = max = 0;
		for (int i = 0;i < input.size();i++)
		{
			if (!minmaxSet && input[i] >= 0)
			{
				min = max = input[i];
				minmaxSet = true;
			}

			if (min > input[i] && minmaxSet)
			{
				min = input[i];
			}

			if (max < input[i] && minmaxSet)
			{
				max = input[i];
			}

			if (input[i]>=0)
			{
				filterinput.push_back(input[i]);
			}
		}

		range = max - min+1;
		vector <int> sort(range);

		for (int i = 0;i < filterinput.size();i++)
		{
			sort[(filterinput[i]-(min))] = filterinput[i];
		}

		int lastValue = sort[0];

		for (int i = 1;i<sort.size();i++)
		{

				if (sort[i] != lastValue + 1)
				{
					return (lastValue + 1);
				}

			lastValue++;
		}
	}

	return 0;

}

int TrapWater(vector<int> height)
{
	int result = 0;
	int lastResult = 0;
	int min, max;
	int betweencount = 0;

	if (height.size() > 1)
	{
		min = max = height[0];

		for (int i = 1;i < height.size();i++)
		{
			
			betweencount++;
			if (min>height[i])
			{
				result = result + (min - height[i]);
				min = height[i];
			}

			if (max <= height[i])
			{
				vector<int> temp(height.begin() + i - betweencount, height.begin() +i);
				result = lastResult + TrapWater(temp);
				lastResult = result;
				betweencount = 0;
				min = max = height[i];
			}
		}
	}

	else
	{
		return 0;
	}

	return result;

}

//TrappingWater
// do this recursively- try
int Solution42() {
	//[0,1,0,2,1,0,1,3,2,1,2,1]
	vector<int> height;
	height.push_back(0);
	height.push_back(1);
	height.push_back(0);
	height.push_back(2);
	height.push_back(1);
	height.push_back(0);
	height.push_back(1);
	height.push_back(3);
	height.push_back(2);
	height.push_back(1);
	height.push_back(2);
	height.push_back(1);


return TrapWater(height);


}

//solution30
vector<int> Solution30(string s, vector<string>& words) {
	vector<int> result;

	for (int i = 0;i < words.size();i++)
	{
		for (int j = 0;j < (s.size()- words.size());j++)
		{
			if (s.substr(j, words[i].size()) == words[i])
			{
				result.push_back(j);
				break;
			}
		}
	}

	return result;

}


//hrank7 minmaxsum

void MinMaxSum()
{
	vector<int> arr(5);
	vector<int> minsum(4);
	vector<int> maxsum(4);
	int least=arr[0];
	int biggest = arr[0];

	while (arr.size() != 0)
	{
		for (int i = 0;i < arr.size();i++)
		{

			if (arr[i] < least)
			{
				least = arr[i];
				arr[i] = NULL;
			}


		}

	}

	for (int i = 0;i < 5;i++)
	{

	}
}

//hrank6 #pyramid

void hrank6Staircase()
{
	int n=5;

	for (int i = 1;i <= n;i++)
	{
		std::cout << std::string(n - i, ' ');
		std::cout << std::string(i, '#') << std::endl;
	}

}


//hrank5
void PlusMinus()
{
	int n=6; vector<int> arr;

	arr.push_back(-4);
	arr.push_back(3);
	arr.push_back(-9);
	arr.push_back(0);
	arr.push_back(4);
	arr.push_back(1);

	int a = 0, b = 0, c = 0;
	float d, e, f;

	for (int i = 0;i<n;i++)
	{
		if (arr[i]>0)
		{
			a++;
		}
		else if (arr[i]<0)
		{
			b++;
		}

		else
		{
			c++;
		}

	}

	d = (float)a /(float) n;
	e = (float)b / (float)n;
	f = (float)c / (float)n;
	
	//printf("%0.6lf", d);cout << '\n';
	//printf("%0.6lf", e);cout << '\n';
	//printf("%0.6lf", f);cout << '\n';
}

//hrank4
 int DiagonalDiff()
{
	int n = 3; vector<int> row;
	vector< vector<int> > matrix;

	row.push_back(11);
	row.push_back(2);
	row.push_back(4);
	matrix.push_back(row);

	row[0] = 4;
	row[1] = 5;
	row[2] = 6;
	matrix.push_back(row);

	row[0] = 10;
	row[1] = 8;
	row[2] = -12;
	matrix.push_back(row);

	int result;
	int temp1 = 0, temp2 = 0;
	int k=0, l=n-1;

	if (n != 0)
	{

		while ((k <n) && (l>=0))
		{
			temp1 = temp1+ matrix[k][k];
			temp2 =temp2+ matrix[k][l];
			k++;
			l--;
		}

		result = abs (temp1 - temp2);
		return result;

	}

	else
	{
		return 0;
	}

}



//hrank3
vector < int > solve(int a0, int a1, int a2, int b0, int b1, int b2) {
	// Complete this function

	int apoint = 0, bpoint = 0;
	vector<int> result;

	if (a0>b0)
	{
		apoint++;
	}
	else if (a0<b0)
	{
		bpoint++;
	}

	if (a1>b1)
	{
		apoint++;
	}
	else if (a1<b1)
	{
		bpoint++;
	}

	if (a2>b2)
	{
		apoint++;
	}
	else if (a2<b2)
	{
		bpoint++;
	}

	result.push_back(apoint);
	result.push_back(bpoint);

	return result;

}

//hrank2
int simpleArraySum(int n, vector <int> ar) {
	// Complete this function
	int temp = 0;

	for (int i = 0;i<n;i++)
	{
		temp = temp + ar[i];
	}

	return temp;
}

//hrank2
int solveMeFirst(int a, int b) {
	// Hint: Type return a+b; below:

	return (a + b);

}


//hrank 1
long aVeryBigSum() {
	int n=5; vector<long> ar;
	//1000000001 1000000002 1000000003 1000000004 1000000005
	ar.push_back(1000000001);
	ar.push_back(1000000002);
	ar.push_back(1000000003);
	ar.push_back(1000000004);
	ar.push_back(1000000005);
	ar.push_back(1000000006);



	// Complete this function
	long long result = 0;

	for (int i = 0;i<n;i++)
	{
		result = result + ar[i];
	}

	result = result / n;

	return result;

}

void Soution25()
{
	Node * input = new Node(1);
	input->next = new Node(2);
	input->next->next = new Node(3);
	input->next->next->next = new Node(4);
	input->next->next->next->next = new Node(5);
		Node * pointer = input;
	int k=3;

	Node * beforek;
	Node * afterk;

	Node* result=NULL;
	Node* resultStart ;

	vector <int> inputstack;
	vector <int> resultvector;

	if (input != nullptr)
	{
		for (int i = 1;i <=k;i++)
		{
			inputstack.push_back(pointer->value);
			pointer = pointer->next;
		}

		for (int i = 1;i <= k;i++)
		{
			resultvector.push_back(inputstack[inputstack.size()-1]);
			inputstack.pop_back();
		}

		if (pointer != NULL)
		{
			while (pointer != NULL)
			{
				resultvector.push_back(pointer->value);
				pointer = pointer->next;
			}
		}

		for (int i = 0;i < resultvector.size();i++)
		{
			Node * temp;
			

			temp = new Node(resultvector[i]);

			if (i == 0)
			{
				result = temp;
				resultStart = result;
			}

			else
			{
				result->next = temp;
				result = result->next;
			}

			
			 
		}


	}

}


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

//phone number texting combination

vector<string> Solution17(string digits)
{
	vector<string> result;
	vector<string> temp;
	vector<string> texts;


	texts.push_back("");
	texts.push_back("");
	texts.push_back("abc");
	texts.push_back("def");
	texts.push_back("ghi");
	texts.push_back("jkl");
	texts.push_back("mno");
	texts.push_back("pqrs");
	texts.push_back("tuv");
	texts.push_back("wxyz");

		if (digits.size() > 1)
		{
			temp = Solution17(digits.substr(1, digits.size() - 1));

			for (int j = 0;j < temp.size();j++)
			{
				for (int k = 0;k < texts.at((int)digits.at(0)-48).size();k++)
				{
					string letters = texts.at(digits.at(0)-48);

					result.push_back((letters.at(k) + (temp.at(j))));
				}

			}

		}

		else if(digits.size() == 1)
		{
			for (int l = 0;l < texts.at((int)digits.at(0)-48).size();l++)
			{
				string letters = texts.at(digits.at(0)-48);
				temp.push_back(string(1,letters.at(l)) );
			}

			result = temp;
		}


	return result;

}




//Closest sum to given num
int Solution16()
{
	int given=-100;
	int var1=0, var2=0,var3=0;
    int maxDiff;
	vector<int> nums;
	nums.push_back(1);
	nums.push_back(1);
	nums.push_back(1);
	nums.push_back(0);


	if (nums.size() > 2)
	{
		for (int i = 0;i < nums.size();i++)
		{
			if (i == 0)
			{
				var3 = nums[i];
			}

			if (i == 1)
			{
				var1 = nums[i];
			}
			else if (i == 2)
			{
				var2 = nums[i];
				maxDiff = given - (var1 + var2 + var3);
			}

			if (i > 2)
			{
			    int least1, least2, least3;

				least1 = given-( nums[i] + var1 + var2);
				least2 = given-(var3 + nums[i] + var2);
				least3 = given-(var3 + var1 + nums[i]);

				if ((least1 < least2) && (least1 < least3) &&(least1<maxDiff))
				{
					var3 = nums[i];
				}

				else if ((least2 < least1) && (least2 < least3) && (least2<maxDiff))
				{
					var1 = nums[i];
				}

				else if ((least3 < least1) && (least3 < least2) && (least3<maxDiff))
				{
					var2 = nums[i];
				}

				maxDiff = maxDiff = given - (var1 + var2 + var3);

			}
		}

		return (var1 + var2 + var3);
	}

	else if (nums.size() == 2)
	{
		return nums[0] + nums[1];
	}

	else if (nums.size() == 1)
	{
		return nums[0];
	}

	else return 0;


}

vector<vector<int>> Solution15() {

	vector<int> nums;

	nums.push_back(-1);
	nums.push_back(0);
	nums.push_back(1);
	nums.push_back(2);
	nums.push_back(-1);
	nums.push_back(-4);

	int searchnum, temp;
	vector<vector<int>> result;
	

	for (int i = 0;i < nums.size();i++)
	{
		for (int j = i + 1;j < nums.size()-2;j++)
		{
			searchnum = nums[i] + nums[j];
			vector<int> set;

			if (std::find(nums.begin()+(j+1), nums.end(), searchnum) != nums.end())
			{
				auto it = std::find(nums.begin() + (j + 1), nums.end(), searchnum);
				auto pos = it - nums.begin()- (j + 1);
				set.push_back(nums[i]);
				set.push_back(nums[j]);
				set.push_back(nums[pos]);

				result.push_back(set);
			}

			else
				continue;
		}
	}

	return result;

}


string Solution14(vector<string>& strs) {

	string smallest = "";

	for (int i = 0;i<strs.size();i++)
	{
		if (strs[i].size() <= smallest.size())
		{
			smallest = strs[i];

		}
	}

	if (smallest != "")
	{
		int ssize = smallest.size();

		while (1)
		{
			for (int i = 0;i < strs.size();i++)
			{
				if ((strs[i].find(smallest.substr(0, smallest.size())) != string::npos) && (strs[i].find(smallest.substr(0, smallest.size())) == 0))
				{
					return(smallest.substr(0, smallest.size()));
				}

				else
				{
					ssize--;
					break;
				}

				if (ssize == 0)
				{
					return "";
				}
			}

		}

	}

	else return "";

}

int Solution11(vector<int>& height)
{

	int volume=0;
	int maxVolume=0;

	for (int i = 0;i < height.size();i++)
	{
		if (i == 0)
		{
			volume = height[0] *  height[0];
		}

		if ((i + 1) < height.size() - 1)
		{
			int lesser;
			if (height[i] < height[i + 1])
			{
				lesser = height[i];
			}

			volume = lesser * lesser;

		}


		if (volume > maxVolume)
		{
			maxVolume = volume;
		}
	}

	return maxVolume;
}

Node* Solution23()
{
	 vector<Node*>lists;

	 Node* temp = new Node(-1);
	 temp->next = new Node(-1);
	 temp->next->next = new Node(-1);


	 lists.push_back(temp);
	 //delete(temp);
	 
	 temp = new Node(-2);
	 temp->next = new Node(-2);
	 temp->next->next = new Node(-1);

	 lists.push_back(temp);
	 //delete(temp);

	 //temp = new Node(6);
	 //temp->next = new Node(7);
	 //temp->next->next = new Node(8);

	 lists.push_back(NULL);
	 //delete(temp);


	 Node* resultstart=NULL;
	 Node* nodeptr=NULL;
	 Node* tempnodeptr;

	 int numberofLists = lists.size();
	// auto array = new int[numberofLists][2];
	 //0 1 2 4, 3 4 5 ,6,7,8
	 for (int i = 0;i < numberofLists;i++)
	 {
		 tempnodeptr = lists[i];

		 if (resultstart == NULL)
		 {
			 Node * temp = new Node(lists[i]->value);
			 resultstart = temp;
			 nodeptr = resultstart;

			 // move to the next element
			 tempnodeptr = tempnodeptr->next;
		 }


			 if (nodeptr != NULL && lists[i] != NULL)
			 {
				 if (nodeptr->value > lists[i]->value)
				 {
					 nodeptr = resultstart;
				 }

				 while (tempnodeptr != NULL  && resultstart != NULL)
				 {
					 // for the first entry to the result list
					 //if (nodeptr == NULL && lists[i] != NULL)
					 //{
						// nodeptr == lists[i];
						// resultstart = nodeptr;
					 //} redundant

					 // if the new entry is less than the start pointer
					 if (tempnodeptr->value < resultstart->value)
					 {
						 Node * temp = new Node(tempnodeptr->value);
						 temp->next = resultstart;
						 resultstart = temp;

						 nodeptr = resultstart;

						 // move to the next element
						 tempnodeptr = tempnodeptr->next;
					 }

					 // insert at the end of the list
					 else if (nodeptr->value <= tempnodeptr->value && nodeptr->next == NULL)
					 {
						 //create a temp node here- not done yet
						 Node * temp = new Node(tempnodeptr->value);
						 nodeptr->next = temp;
						 nodeptr = nodeptr->next;

						 // move to the next element
						 tempnodeptr = tempnodeptr->next;

					 }

					 // insert at he right spot
					 else if ((nodeptr->value <= tempnodeptr->value) && (tempnodeptr->value <= nodeptr->next->value))
					 {

						 //create a temp node here- not done yet
						 Node * temp = new Node(tempnodeptr->value);
						 temp->next = nodeptr->next;
						 nodeptr->next = temp;

						 nodeptr = nodeptr->next;

						 // move to the next element
						 tempnodeptr = tempnodeptr->next;
					 }

					 // move till you reach the right spot
					 else
					 {
						 nodeptr = nodeptr->next;
					 }
				 }
			 }
	 }

	 return resultstart;



}

bool Solution10New(string s, string p)
{
	vector<string> partsSave;
	int partlength = 0;

	char lastValidChar=(char) 0,previousLVC= (char)0;

	bool any = false;
	bool many = false;
	bool anymany = false;

	if ((s == "" && p == ""))
	{
		return true;
	}

	// to find all special characters and subdevide them
	//for (int i = 0;i < p.size();i++)
	//{
	//	if (p[i] == '*' || p[i] == '.')
	//	{
	//		partsSave.push_back(p.substr(i - partlength, partlength + 1));
	//		partlength = 0;
	//	}
	//	else if (i == p.size() - 1)
	//	{
	//		partsSave.push_back(p.substr(i - partlength, partlength + 1));
	//		partlength = 0;
	//	}

	//	else partlength++;
	//}

	//for (int i = 0;i < partsSave.size();i++)
	//{
	//	if (partsSave[i].size() == 1)
	//	{
	//		if ((partsSave[i][partsSave[i].size() - 1] != '*' && partsSave[i][partsSave[i].size() - 1] != '.') && (i == partsSave.size() - 1))
	//		{
	//			if (s.find(partsSave[i]) != string::npos)
	//			{
	//				s.erase(s.find(partsSave[i]), partsSave[i].size());
	//				partsSave[i].clear();

	//			}
	//			else
	//			{
	//				return false;
	//			}
	//		}
	//	}

	//	else if (partsSave[i].size()>1)
	//	{
	//		if (s.find(partsSave[i].substr(0, partsSave[i].size() - 2)) != string::npos) 
	//		{
	//			s.erase(s.find(partsSave[i].substr(0, partsSave[i].size()-2)), partsSave[i].size() - 2);
	//			//partsSave[i].erase((0, (partsSave[i].size - 2)));

	//			partsSave[i]= partsSave[i].substr(partsSave[i].size() - 2, partsSave[i].size());

	//		}

	//		else
	//		{
	//			return false;
	//		}
	//	}
	//}

	//p = "";
	//p = accumulate(begin(partsSave), end(partsSave), p);

	
	//char lastValidChar=(char) 0;

	//if (s == "" && p != "")
	//{
	//	int i;
	//	for (i = 0;i < partsSave.size();i++)
	//	{
	//		string tempstr = partsSave[i];
	//		for (int j = 0;j < tempstr.size();j++)
	//		{
	//			if (tempstr[tempstr.size() - 1] == '*')
	//			{

	//				if (j < tempstr.size() - 1)
	//				{
	//					if (tempstr[j + 1] != '*')
	//					{
	//						return false;
	//					}
	//				}
	//				else if (tempstr[j] == '*')
	//				{
	//					continue;
	//				}
	//				else
	//				{
	//					return false;
	//				}
	//			}
	//			else
	//			{
	//				return false;
	//			}
	//		}
	//	}

	//	if (i == partsSave.size())
	//	{
	//		return true;
	//	}
	//}

	int i = 0, j = 0, k = 0,accumulaterepeated=0,accumulatemeasurer=0;

	while (i < p.size() && j < s.size())
	{

		// normal character match for special character
		if ((p[i] != '*') && (p[i] != '.') && (p[i]==s[j]))
		{
			if (previousLVC != lastValidChar)
			{
				previousLVC = lastValidChar;
			}
				lastValidChar = p[i];
				if (i < p.size() - 1)
				{
					if (p[i + 1] == '*')
					{
						i++;
					}
					else
					{
						i++;
						j++;
					}
				}

				else
				{
					i++;
					j++;
				}

		}


		//considering one compulsary character present for '.'
		else if (p[i] == '.')
	{
		if (i < p.size() - 1)
		{
			k++;
		}
		if ((i < p.size() - 1))
		{
			//if * present after '.' , handle that differently in the else part
			if (p[i + 1] != '*')
			{
				if (j < s.size() - 1)
				{
					i++;
					j++;
					lastValidChar = '.';

					//string tempmatch;
					//tempmatch = accumulate(begin(partsSave)+k, end(partsSave), tempmatch);

					//if (tempmatch.find(".*") != std::string::npos) {
					//	// jump to next '.*'
					//	i = i + tempmatch.find(".*");
					//}

				}
				else
				{
					return false;
				}
			}
			//handle here for '.*'
			else
			{
				//anycharacter 0 or more occurj-1 < s.size()ances-done
				if ((j - 1) < (int)(s.size()))
				{
					j++;
					i++;
					lastValidChar = '.';
				}
			}

		}
		// '.' is the last character, at least 1 character for '.'
		else if (i == (p.size() - 1))
		{
			if (j < s.size())
			{
				j++;
				i++;
				lastValidChar = '.';
			}
		}

		else
		{
			return false;
		}
	}

		//gets little complex here :(
		else if (p[i] == '*')
		{
			// to check the substring match by parts
			if (i < p.size() - 1)
			{
				k++;
			}


				//find various special cases

				// double * back to back, so ignore 1 of them-done
				if (i < (p.size()-1))
				{
					if (p[i + 1] == '*')
					{
						k++;
						i++;
					}
				}

				//normal behaviour for * character for atleast 1 occurance-done
				if (s[j] == lastValidChar || (lastValidChar == '.'))
				{


					if (lastValidChar =='.')
					{
						string temp;
						//if (k < partsSave.size() - 3) {
						//	temp = temp.append(partsSave[k+1], 0).append(partsSave[k + 2], partsSave[k+1].size());
						//	if (temp.find(".*") != std::string::npos) {
						//		// jump to next '.*'
						//		i = i + temp.find(".*");
						//	}
						//}
						



						//if (k < partsSave.size() - 2) {
						//	temp = "";
						//	temp= accumulate(begin(partsSave) + (k+1), end(partsSave), temp);
						//	if (temp.find(".") != std::string::npos) {
						//		// at least one character should be there for '.'
						//		if ((j >= s.size()-1))
						//		{
						//			return false;
						//		}
						//	}
						//}

						//if (k < partsSave.size() - 2) {
						//	temp = "";
						//	temp = accumulate(begin(partsSave) + (k + 1), end(partsSave), temp);
						//	if (temp.find("*") != std::string::npos) {

						//		char tempValid=NULL;
						//		for (int l = temp.find("*");l > i;l--)
						//		{
						//			if (p[l] != '.' || p[l] != '*')
						//			{
						//				tempValid = p[l];
						//			}
						//		}

						//		if (tempValid != NULL)
						//		{
						//			//if not found
						//			if (!(s.substr(i+1,s.size()-i).find(tempValid) != std::string::npos))
						//			{
						//				return false;
						//			}
						//		}

						//	}
						//}

						if (j < s.size())
						{
							j++;

							if (j == s.size() && p[i] == '*')
							{
								i++;
							}
						}

					}
			    else  {

					bool breakchar = false;

					if (previousLVC != lastValidChar)
					{
						previousLVC = lastValidChar;
						accumulaterepeated = 1;
						accumulatemeasurer = 1;

						for (int l = i + 1;l < p.size();l++)
						{
							if (breakchar)
							{
								break;
							}
							if (l < p.size() - 1)
							{
								if (p[l] != '*' && p[l + 1] != '*')
								{
									breakchar = true;
								}

								else if (p[l] != lastValidChar &&p[l + 1] == '*')
								{
									continue;
								}

								else if (p[l] == lastValidChar &&p[l + 1] == '*')
								{
									i = l + 1;
								}

								else if (p[l] == lastValidChar &&p[l + 1] != '*')
								{
									accumulaterepeated++;
								}
							}

							if (l == p.size()-1 && p[l] == lastValidChar)
							{
								accumulaterepeated++;
							}

						}
					}


						   accumulatemeasurer++;

						   if ((accumulatemeasurer > accumulaterepeated) && (i<p.size()-1) &&(j<s.size()-1))
						   {
							   i++;
							   j++;
						   }

						   else
						   {
							   j++;
						   }

					   if (j == s.size() && p[i]=='*')
					   {
						   i++;
					   }
			          }
				}

				//normal behaviour for * character for 0 occurance-done
				else if(s[j]!= lastValidChar)
				{
					i++;
				}
			


		}

		else if(i<(p.size()-1))
		{
			if (p[i+1]=='*')
			{
				lastValidChar = p[i];
				i++;
			}
			else
			{
				// mismatch found
				return false;
			}
		}

		// fits none of above scenario
		else
		{
			return false;
		}

	}

	string temps, tempp;

	tempp = p.substr(i, (p.size() - i));

	if (j==s.size() && i<p.size())
	{
		int m;
			string tempstr = tempp;

			while ((p[i - 1] == '*') && (p[i] == lastValidChar) && (i<p.size()))
			{
				i++;
			}

			//check if * exists at the end
		if (tempstr[tempstr.size() - 1] == '*')
		 {
			for (m = 0;m < tempstr.size();m++)
			{

					//if another * exists before the * at the end
					if (tempstr[m] == '*' )
					{
						continue;
					}

					if (m < tempstr.size() - 1)
					{
						if (tempstr[m + 1] != '*')
						{
							return false;
						}

					}

			  }
			i = i + m;
			}
	  else if(i<p.size())
	  {
		return false;
	  }
		
			
	}

	if(i==p.size() && j==s.size())
	{ 
		return true;
	}
	else
	{
		return false;
	}
	

}

bool Solution10(string s, string p) {

	//abc.*abc*

	//abcabcdef
  
	vector<string> partsSave;
	int partlength = 0;

	char lastValid;

	bool any = false;
	bool many = false;
	bool anymany = false;
	int sizes = s.size(), sizep = p.size();

	// to find all special characters and subdevide them
	for (int i = 0;i < p.size();i++)
	{
		if (p[i] == '*' || p[i]=='.')
		{
			partsSave.push_back(p.substr(i - partlength, partlength+1));
			partlength = 0;
		}
		else if (i==p.size()-1)
		{
			partsSave.push_back(p.substr(i - partlength, partlength + 1));
			partlength = 0;
		}

		else partlength++;
	}

	partlength = 0;

	if ((s == "" && p==""))
	{
		return true;
	}

	int i = 0, j = 0, k = 0;
	
	while (j<sizes && i<sizep)
	{

		// considering normal character match
		if (p[i] != '*' || p[i] != '.')
		{
			if (p[i] == s[j])
			{
				j++;
				i++;
			}
			else
			{
				return false;
			}
		}

		//considering one compulsary character present for '.'
		else if (p[i] == '.')
		{
			if ((i < sizep - 1))
			{
				//if * present after '.' , handle that differently in the else part
				if (p[i + 1] != '*')
				{
					if (j < sizes - 1)
					{
						i++;
						j++;
					}
					else
					{
						return false;
					}
				}
				//handle here for '.*'
				else
				{
					//anycharacter 0 or more occurances-done
						if ((j - 1) < sizes)
						{
							j++;
						}
				}

			}
		}


		//gets little complex here :(
		else if (p[i] == '*')
		{
			// to check the substring match by parts
			k++;

			if (i > 0 )
			{
				//find various special cases

				// double * back to back, so ignore 1 of them-done
				if (i < sizep)
				{
					if (p[i + 1] == '*')
					{
						i++;
					}
				}

				//normal behaviour for * character for atleast 1 occurance-done
				else if (s[j]==lastValid)
				{
					j++;
				}

				//normal behaviour for * character for 0 occurance-done
				else
				{
					i++;
					j++;
				}
			}


		}

		if ((p[i] == s[j]) || ((p[i] == '.') && j<sizes - 1))
		{
			lastValid = p[i];
			j++;
			i++;
		}

		else if (p[sizep]=='*')
		{
			if (i > 0)
			{
				if ((p[i - 1] == '.'))
				{
					j++;
					lastValid = '.';

					if ((k + 1) < partsSave.size() - 1)
					{
						//if (partsSave[k + 1].substr('.*')>0)
						//{
						//	if (partsSave[k + 1].substr(partsSave[k + 1].size() - 2))
						//	{

						//	}
						//}
						//else if (partsSave[k + 1].substr('*') > 0)
						//{
						//	if (partsSave[k + 1].substr(partsSave[k + 1].size() - 1))
						//	{

						//	}
						//}
					}

				}

				else if ((p[i - 1] == '*'))
				{
					if (lastValid == '.' || lastValid == s[i])
					{
						j++;
					}
				}
				else if(p[i-1]==p[j])
				{
					j++;
				}

				if ((i + 1) < sizep)
				{
					if (p[i + 1] == '*')
					{
						i++;
					}

				}

				else
				{
					i++;
				}
			}

		}

		if (k == partsSave[k].size())
		{
			k++;
		}

	}

	if (j == sizes)
	{
		return true;
	}
	else
	{
		return false;
	}

	//for (int i = 0;i < p.size();i++)
	//{
	//	for (int j = 0;j < s.size();j++)
	//	{
	//		if (p.at(i)=='.')
	//		{
	//			any = true;
	//		}

	//		else if (p.at(i) == '*')
	//		{
	//			many = true;
	//			if (i > 0)
	//			{
	//				if (p.at(i - 1) == '.' && p.at(i) == '*')
	//				{
	//					anymany = true;
	//				}
	//				else
	//				{
	//					anymany = false;
	//				}
	//			}
	//		}

	//		else if (p.at(i) == p.at(j))
	//		{
	//			continue;
	//		}

	//		else
	//		{
	//			any = false;
	//			anymany = false;
	//			many = false;
	//			return false;
	//		}


	//	}

	//}
}

//palindrome number check
bool Solution9(int x)
{
	int x1, x2;
	int length = 0;
	unsigned int temp=x;

	if (x >= 0 && x<10)
	{
		return true;
	}

	length = ((temp <= 1) ? 1 : log10(temp) + 1);
		
		while ((temp > 0) &&(length>1))
		{
			x1 = temp % 10;
			x2 = temp / (pow(10, length-1));

			if (x1!=x2)
			{
				return false;
			}

			temp = temp / 10;

			temp = temp - (x2*(pow(10, length - 2)));
			length = length - 2;
		}

	return true;
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

	//Solution7(-2147483648);


	//Solution9(224422);

	//Solution10("abcdabbba", "abcc*abb.*ab");

	//Solution10New("aaaaa", "a*a");

	//Solution23();

	//Solution16();

	//Solution17("233");
	//aVeryBigSum();

	 //DiagonalDiff();

	//PlusMinus();

	//Soution25();

	//vector <string> inputs;
	//inputs.push_back("foo");
	//inputs.push_back("bar");

	//Solution30("barfoothefoobarman", inputs);

	//Solution42();

	//Solution41();

	vector<vector<string>> employees;
	vector<string> empin;

	empin.push_back("1,Richard,Engineering");
	empin.push_back("2,Erlich,HR");
	empin.push_back("3,Monica,Business");
	empin.push_back("4,Dinesh,Engineering");
	empin.push_back("6,Carla,Engineering" );
	empin.push_back("9,Laurie,Directors");
	employees.push_back(empin);

	vector<vector<string>> friendships;
	 vector<string> friends;

	 friends.push_back("1,2");
	 friends.push_back("1,3");
	 friends.push_back("1,6");
	 friends.push_back("2,4");

	 friendships.push_back(friends);


    return 0;
}

