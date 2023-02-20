#include <iostream>
#include <stdio.h> 
using namespace std; 
int main()
{

	int arraySize;
	bool increasing = true;
	cout<< "Enter the size of the array: ";
	cin >> arraySize;
	if(arraySize < 0)
	{
		cout << "ERROR: you entered an incorrect value for the array size!" << endl;
	}
	else
	{
		
		int* list = new int[arraySize];

		cout <<  "Enter the numbers in the array, seperated by a space, and enter: ";
		for(int i = 0; i < arraySize; i++)
		{
		scanf("%d", &list[i]);
			if(i > 0 && list[i] < list[i-1] && increasing != false)
			{
			increasing = false;
			}
		}

		if(increasing == true)
			{
			cout << "This IS an increasing array!" << endl;
			}
		else
			{
			cout << "This is NOT an increasing array!" << endl; 
			}
		for(int j = 0;j < arraySize; j++)
			{
			cout << list[j] << " ";
			}
	}
	cout << endl;
	return 0;
}
