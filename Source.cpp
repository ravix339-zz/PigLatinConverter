#include <iostream>
#include <vector>
#include <string>
using namespace std;


class PigL
{
private:
	vector<char> phrase;
	vector<char> temp;
	vector<char> finall;
public:
	PigL(vector<char> text){ phrase = text; }
	void convert2Pig();
	bool checkSpace(int);
	void separate();
	void sort();
};

void PigL::separate()
{
	temp = phrase;

	for (int i = 0; i < phrase.size(); ++i)
	{
		if (checkSpace(i))
		{
			temp.erase(temp.begin() + i, temp.end());
			phrase.erase(phrase.begin(), phrase.begin() + i + 1);
			return;
		}
	}
	phrase.clear();
}

void PigL::convert2Pig()
{
	while (!phrase.empty())
	{
		separate();
		sort();
	}

	cout << endl << "Your converted phrase is: ";
	for (int i = 0; i < finall.size(); ++i)
	{
		cout << finall[i];
	}
	cout << endl;

}

bool PigL::checkSpace(int i)
{
	if (phrase[i] == ' ')
		return true;
	else
		return false;
}

void PigL::sort()
{
	if (temp[0] == 'a' || temp[0] == 'e' || temp[0] == 'i' || temp[0] == 'o' || temp[0] == 'u')
	{
		temp.push_back('w');
		temp.push_back('a');
		temp.push_back('y');
	}
	else
	{
		while (!(temp[0] == 'a' || temp[0] == 'e' || temp[0] == 'i' || temp[0] == 'o' || temp[0] == 'u'))
		{
			temp.push_back(temp[0]);
			temp.erase(temp.begin());
		}
		temp.push_back('a');
		temp.push_back('y');
	}
	finall.push_back(' ');
	for (int i = 0; i < temp.size(); i++)
		finall.push_back(temp.at(i));
}

void main()
{
	string phrase;
	cout << "Please enter an English phrase in all lower case letters: ";
	getline(cin, phrase);
	vector<char> myvector(phrase.begin(), phrase.end());
	PigL convert(myvector);
	convert.convert2Pig();
	system("PAUSE");
}
