#include<iostream>
using namespace std;
class DStemp
{
public:
	int *arr;
	int l;
	DStemp()
	{
		arr = new int;
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
	
	int binSearchHelp()
	{
		cout<<"Enter search element:";
		int s;
		cin>>s;
		cout<<"Location of "<<s<<"(Recursive): "<<binSearch(0,l-1,s)<<endl;
		cout<<"Location of "<<s<<"(Iterative): "<<binSearchIter(s)<<endl;
	}

	int binSearch(int low, int up, int s)
	{
		if(low>up)
			return -1;
		else{
			int mid = (low+up)/2;
			if(arr[mid] == s)
				return mid;
			else if(arr[mid]<s)
				return binSearch(mid+1, up, s);
			else return binSearch(low, mid-1, s);
		}
	}
	
	int binSearchIter(int s)
	{
		int up=l-1, low=0;
		while(low<=up){
			int mid = (low+up)/2;
			if(arr[mid] == s)
				return mid;
			else if(arr[mid] < s)
				low = mid+1;
			else up = mid-1;	
		}
		return -1;
	}
	
};
int main()
{
	DStemp tmp=DStemp();
	tmp.inputEle();
	tmp.disp();
	tmp.binSearchHelp();
}
