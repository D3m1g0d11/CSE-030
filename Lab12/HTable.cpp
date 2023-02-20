#include "HTable.h"
#include <iostream>


HTable::HTable()
{
    max_size = 23;
	dt = new struct data[23];
	for (int i = 0; i < 23; i++) 
	{
		dt[i].key = -1;
		dt[i].value = "N/A";
	}
	numel = 0;
}//default constructor to initialize a table of size 23

HTable::HTable (int t_size)
{
    max_size = t_size;
	dt = new struct data[max_size];
	for (int i = 0; i < max_size; i++) 
	{
		dt[i].key = -1;
		dt[i].value = "N/A";
	}
	numel = 0;
} //alternate constructor to initialize a table of size t_size

int HTable::hash(int &k)
{
    int a = k % max_size;
    return a;
}  //evaluates hash code of key


int HTable::rehash(int &k)
{
    int b = (k+1) % max_size;
    return b;
} //performs linear probing if collision appears


int HTable::add(struct data &d)
{
    int h = hash(d.key);
    if(dt[h].key == -1)
    {
        dt[h] = d;
        numel++;
        return 0;
    }
    else
    {
        for (int i = 1; i < max_size; i++) 
		{
			h = rehash(h);
			if (dt[h].key == -1) 
            { 
				dt[h] = d;
				numel++;
				return 0;
			}
		}
        return -1;
    }
}   //adda a data pair into the table according to its key


int HTable::remove(struct data &d)
{
    int l = hash(d.key);
    if(dt[l].value == d.value)
    {
        dt[l].key = -1;
        dt[l].value = "N/A";
        numel--;
        return 0;
    }
    else
    {
		l = rehash(l);
        cout << dt[l].value;
		if (d.value == dt[l].value) 
        {
			dt[l].key = -1;
            dt[l].value = "N/A";
            numel--;
			return 0;
    	}
    }
    return -1;
} //removes data pair from the table according to its key


void HTable::output()
{
    for(int k = 0; k < max_size; k++)
    {
        cout << k << " -> " << dt[k].key << " " << dt[k].value << endl;
    }
    cout << "There are " << numel << " data in the table" << endl;
}//print out the content of the table