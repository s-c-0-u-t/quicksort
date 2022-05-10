#include<iostream>
#include<fstream>
#include<time.h>
#include<stdlib.h>
using namespace std;
void swap(int *a,int *b)
{
	int t=*a;
	*a=*b;
	*b=t;
}
int partiton(int *a,int low,int high)
{
	int key=a[high];
	int i=low-1;
	for(int j=low;j<=high-1;j++)
	{
		if(a[j]<key)
		{
			i++;
			swap(&a[i],&a[j]);
		}
	}
	swap(&a[i+1],&a[high]);
	return (i+1);
	
}
void quicksort(int *a,int low,int high)
{
	if(low<high)
	{
		int pi=partiton(a,low,high);
		quicksort(a,low,pi-1);
		quicksort(a,pi+1,high);
	}
}
int main()
{   ofstream outf;
    ifstream inf;
	int *a;
	int n;
	cout<<"enter how many";
	cin>>n;
	
	
	time_t stt;
	time(&stt);
	srand((long int)stt);
	
	outf.open("in.txt");
	for(int i=0;i<n;i++)
	{
		outf<<"\t"<<rand()%(n+1);
	}
       outf.close();
	
	a=new int[n+1];
	
	inf.open("in.txt");
	for(int i=0;i<n;i++)
	{
		inf>>a[i];
	}
	inf.close();
	quicksort(a,0,n-1);
	cout<<"the sorted array";
	outf.open("output.txt");
	for(int i=0;i<n;i++)
	{        cout<<"\t"<<a[i];
		outf<<"\t"<<a[i];
	}
	outf.close();
	return 0;
}
