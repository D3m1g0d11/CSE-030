#include <iostream> 
#include <stdio.h>
#include <string>
using namespace std;
using std::string;
int main()
{
	string verse;
	cout << "Enter the string to reverse: ";
	cin >> verse;
	if(verse.length() > 0)
	{
	char reverse[verse.length()];
	for(int i = 0; i < verse.length()+1; i++)
		{
		reverse[verse.length()-i] = verse[i];
		}
	for(int j = 0; j < verse.length()+1; j++)
			{
			cout << reverse[j];
			}
	cout << endl;
	return 0;
	}
}
