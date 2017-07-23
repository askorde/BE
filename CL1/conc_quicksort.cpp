#include<iostream>
#include<omp.h>
using namespace std;
class DStemp
{
public:
	int *arr;
	int l;
	DStemp()
	{
		arr = new int;
		l=0;
	}
	
	void inputEle()
	{
		cout<<"Enter no of elements:";
		cin>>l;
		cout<<"Enter elements:\n";
		for(int i=0;i<l;i++)
			cin>>arr[i];		
	}
	
	void disp()
	{
		for(int i=0;i<l;i++)
			cout<<arr[i]<<"\t";
		cout<<endl;
	}	
	
	void sort(int st, int end)
	{
		if(st<end)
		{
			int p = part(st,end);
			#pragma omp parallel num_threads(2)
			{
				int id=omp_get_thread_num();
				if(id==0)
					sort(st,p-1);
				else if(id==1)	
					sort(p+1,end);
			}
		}
	}
	
	int part(int st,int end)
	{
		int i = st, j = end+1;
		int p = arr[st];
		while(true)
		{
			while(arr[++i]<p && i<end);
			while(arr[--j]>p && j>st );
			if(i>=j) 
				break;
			int t1=arr[i];
			arr[i] = arr[j];
			arr[j] = t1;				
		}
		arr[st] = arr[j];
		arr[j] = p;
		return j;
	}
};
int main()
{
	DStemp tmp=DStemp();
	tmp.inputEle();
	tmp.disp();
	tmp.sort(0,tmp.l-1);
	cout<<"Sorted:"<<endl;
	tmp.disp();
	return 0;
}
