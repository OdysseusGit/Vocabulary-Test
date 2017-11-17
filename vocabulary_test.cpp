/*
A simple testing program to help with memorisation of question/answer pairs.
*/

#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

vector<string> question;
vector<string> answer;

int main()
{
	cout << "Input a list of question/answer pairs in the form \"a:alpha,b:bravo,c:charlie,...,z:zulu\": " << endl;
	string list;
	cin >> list;

	stringstream ss1(list);
	string segment1;

	while(getline(ss1, segment1, ','))
	{
		stringstream ss2(segment1);
		string segment2;

		bool qabool = true;
		while(getline(ss2, segment2, ':'))
		{
			if(qabool)
			{
				question.push_back(segment2);
				qabool = false;
			}
			else
			{
				//check that "quit" is not an answer entry, as this command is used to exit the program
				if(segment2 == "quit")
				{
					cout << "You will have to learn " + question.back() + " manually, sorry!" << endl;
					return 0;
				}

				answer.push_back(segment2);
			}
		}
	}

	bool done;
	while(!done)
	{
		if(question.empty())
		{
			cout << "Congratulations!" << endl;
			break;
		}

		int randint = rand() % question.size();

		cout << "What is " + question[randint] + "?" << endl;
		string input;
		cin >> input;

		if(input == "quit")
		{
			done = true;
		}
		else if(input == answer[randint])
		{
			cout << "Correct!" << endl;
			question.erase(question.begin() + randint);
			answer.erase(answer.begin() + randint);
		}
		else
		{
			cout << "Incorrect! The correct answer was " + answer[randint] + "." << endl;
			question.push_back(question[randint]);
			answer.push_back(answer[randint]);
		}
	}

	return 0;
}
