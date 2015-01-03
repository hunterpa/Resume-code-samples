//Hunter Patton main file for cave exploration
#include <iostream>
#include <cstring>
#include "Stack.h"
#include "ListStack.h"

using namespace std;

int main(int argc, char *argv[])
{
	ListStack<char> rope;
	string exploration;
	int steps;
	cout << "input the exploration steps:";
	cin >> exploration;
	steps=exploration.length();//get length of for loop


	for(int i=0; i<steps; i++)
	{
		char step=exploration[i];

		//make steps for each input
		if(step=='n')
		{
			if(rope.isEmpty())
			{
				rope.push(step);
				continue;
			}
			else if(rope.Top()=='s')
			{
				rope.pop();
			}
			else
			{
				rope.push(step);
			}
		}

		else if(step=='s')
		{
			if(rope.isEmpty())
			{
				rope.push(step);
				continue;
			}
			else if(rope.Top()=='n')
			{
				rope.pop();
			}
			else
			{
				rope.push(step);
			}
		}

		else if(step=='e')
		{
			if(rope.isEmpty())
			{
				rope.push(step);
				continue;
			}
			else if(rope.Top()=='w')
			{
				rope.pop();
			}
			else
			{
				rope.push(step);
			}
		}

		else if(step=='w')
		{
			if(rope.isEmpty())
			{
				rope.push(step);
				continue;
			}
			else if(rope.Top()=='e')
			{
				rope.pop();
			}
			else
			{
				rope.push(step);
			}
		}

		//counter measures for bad inputs
		else if(step==' ')
		{
			cout << "incorrect input" << endl;
			return -1;
		}
		else
		{
			cout << "incorrect input" << endl;
			return -1;
		}
	}

	//check whether or not the rope is rolled up
	if(rope.isEmpty())
	{
		cout << "rope is completely rolled up" << endl;
	}
	else
	{
		cout << "rope is not necessarily rolled up" << endl;
	}
	return 0;
}
