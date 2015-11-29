#include <iostream>
#include <vector>

using namespace std;

void quicksort(vector<int>& arr, int lo, int hi);
int part(vector<int>& arr,int lo,int hi);
void swap(vector<int>& arr, int i, int j);
void Init(vector<int>& arr);

int main()
{
	vector<int> arr;
	Init(arr);
	quicksort(arr, 0, arr.size()-1);

	for(int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }

	return 0;
}

void quicksort(vector<int>& arr, int lo, int hi)
{
    int p;

	if(lo < hi)
	{
		p = part(arr, lo, hi);
		quicksort(arr, lo, p-1);
		quicksort(arr, p+1, hi);
	}
}

int part(vector<int>& arr,int lo,int hi)
{
	int p = lo;
	int pele = arr[lo];
	for(int i = lo + 1; i <= hi; i++)
	{
		if(arr[i] < pele)
		{
            p++;
			swap(arr, i, p);
		}
	}
	swap(arr, p, lo);
	return p;
}


void swap(vector<int>& arr, int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void Init(vector<int>& arr)
{
    int p;
    do
    {
        cin >> p;
        if(p >= 0)
        {
            arr.push_back(p);
        }
    }while(p >= 0);
}
