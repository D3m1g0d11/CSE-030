#include <iostream> 
using namespace std;
int main()
{
	int range;
	int negaNums = 0;
	cout<< "Enter the size of the 2D array: ";
	cin >> range;

	if( range <= 0)
	{
	cout << "ERROR: you entered an incorrect value for the array size";
	}
	else if (range > 10)
	{
	cout << "ERROR: your array is too large! Enter 1 to 10.";
	}
	else
	{
	int database [range][range];
		for(int i =0; i < range; i++)
		{
		cout <<"Enter the values in the array for the row " << (i+1) << ", seperated by a space and press enter: ";

			for(int j = 0; j < range; j++)
			{
				scanf("%d", &database[i][j]);
				if(database[i][j] < 0)
				{
				negaNums++;
				}

			}
		}

		if(negaNums == 0)
		{
		cout << "All values are non-negative" << endl;
		}
		else
		{
		cout << "There are " << negaNums  << " negative values!" << endl;
		}
	}
	return 0;
}
