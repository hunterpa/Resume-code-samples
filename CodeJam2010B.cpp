#include <iostream>
#include <cstring>
#include <vector>
#include <sstream>
#include <stack>
#include <stdio.h>
#include <ctype.h>

using namespace std;

void reverse(string str, int length);

int main(int argc, char *argv[])
{
	int cases; //# of test cases
	int *length; //length of line
	string lines; //the line itself for each test case
	cout << "please enter the number of test cases:";
	cin >> cases;
	cin.clear();
	cin.ignore(10000, '\n');
	length=new int[cases];
	stack<string> words;
	for(int i=0; i<cases; i++)
	{
       	        string check;
	        cout << "please enter line:";
	        getline(cin, check);
		length[i]=check.size();
		for(int j=0; j<length[i]; j++)
		  {
		    lines[j]=check[j];
		  }
		cout << "Case #" << i+1 << ": ";
		reverse(lines, length[i]);
	}	
	return 0;
}

void reverse(string str, int length)
{
  int dist=0;
  char arr[length];
  for(int i=0; i<length; i++)
    {
      arr[i]=str[i];
    }
  stack<string> words;
  for(int i=0; i<length; i++)
    {
      if(isspace(arr[i]))
	{
	  char* newWord=new char[i-dist];
	  for(int j=0; j<i-dist; j++)
	    {
	      newWord[j]=arr[j+dist];
	    }
	  dist=i+1;
	  string word(newWord);
	  words.push(word);
	  i++;
	}
    }
  char* newWord=new char[length-dist];
  for(int i=0; i<length-dist; i++)
    {
      newWord[i]=arr[dist+i];
    }
  string word(newWord);
  words.push(word);
  while(!words.empty())
    {
      cout << words.top() << "  ";
      words.pop();
    }
  cout << endl;
}
