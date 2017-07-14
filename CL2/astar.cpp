#include <iostream>
#include <vector>
#include <typeinfo>

using namespace std;

typedef struct Node
{
    int h,g;
    int c[3][3];
    vector<Node*> child;
}Node;

void disp(int a[3][3])
{
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
			cout<<a[i][j]<<"\t";
		cout<<endl;	
	}
}
void cpy(int n[3][3], int a[3][3])
{
	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++)
			n[i][j]=a[i][j];
}

void swap(int a[3][3],int i1, int j1,int n[3][3],int i2, int j2)
{
	cout<<"\t swapping "<<a[i1][j1]<<" and "<<n[i2][j2]<<endl;
	int t = a[i1][j1];
	a[i1][j1] = n[i2][j2];
	n[i2][j2] = t;
}

int h(int a[3][3], int g[3][3])
{
	int c=0;
	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++)
			if(a[i][j]!=g[i][j])
				++c;
	return c;			
}

class Graph
{
public:
	Node *root, *cu,*p;
	Graph(int a[3][3])
	{
		root = new Node;
		cpy(root->c,a);
		cu = root;
		p=root;
	}
	void addChild(Node *r, int a[3][3], int hv)
	{
		Node *n = new Node;
		cpy(n->c,a);
		n->h=hv;
		r->child.push_back(n);
	}
	Node *parent(Node *r)
	{
		if(r==root)
			return NULL;
	}
};

void moves(int a[3][3], int goal[3][3], Graph g, int c) //only h(n)
{
	if(!h(a,goal))
	{
		cout<<"\nReached Goal\n";
		return;
	}
	if(!c)
	{
		cout<<"\nCount exhausted\n";
		return;
	}
	int na1[3][3],na2[3][3],na3[3][3],na4[3][3];
	int dn[3][3]={{0,0,0},{0,0,0},{0,0,0}};
	int hmin=9999, id, hv;
	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++)
		{
			if(a[i][j]==0)
			{
				if(i-1>=0){
					cout<<"\nUP\n";
					cpy(na1,a);
					swap(na1,i,j,na1,i-1,j);
					if(h(na1,g.p->c)){
					//disp(na1);
					hv=h(na1,goal);
					if(hv<hmin)
					{
						hmin = hv;
						id=1;
					}
					
					g.addChild(g.cu,na1,hv);
					cout<<"h(n) for move = "<<hv<<endl;
					}
					else{
					g.addChild(g.cu,dn,9999);
					}
				}
				else{
					g.addChild(g.cu,dn,9999);
					};//up
				if(i+1<3){
					cout<<"\nDOWN\n";
					cpy(na2,a);
					swap(na2,i+1,j,na2,i,j);
					if(h(na2,g.p->c)){
					//disp(na2);
					hv=h(na2,goal);
					if(hv<hmin)
					{
						hmin = hv;
						id=2;
					}
					g.addChild(g.cu,na2,hv);
					cout<<"h(n) for move = "<<h(na2,goal)<<endl;
					}
					else{
					g.addChild(g.cu,dn,9999);
					}
				}
				else{
					g.addChild(g.cu,dn,9999);
					};//down
				if(j-1>=0){
					cout<<"\nLEFT\n";
					cpy(na3,a);
					swap(na3,i,j-1,na3,i,j);
					if(h(na3,g.p->c)){
					//disp(na3);
					hv=h(na3,goal);
					if(hv<hmin)
					{
						hmin = hv;
						id=3;
					}
					g.addChild(g.cu,na3,hv);
					cout<<"h(n) for move = "<<h(na3,goal)<<endl;
					}
					else{
					g.addChild(g.cu,dn,9999);
					}
				}
				else{
					g.addChild(g.cu,dn,9999);
					};//left
				if(j+1<3){
					cout<<"\nRIGHT\n";
					cpy(na4,a);
					swap(na4,i,j+1,na4,i,j);
					if(h(na4,g.p->c)){
					//disp(na4);
					hv=h(na4,goal);
					if(hv<hmin)
					{
						hmin = hv;
						id=4;
					}
					g.addChild(g.cu,na4,hv);
					cout<<"h(n) for move = "<<h(na4,goal)<<endl;
					}
					else{
					g.addChild(g.cu,dn,9999);
					}
				}
				else{
					g.addChild(g.cu,dn,9999);
					};//right
				
				cout<<"\nMin outcome id="<<id<<endl<<"For hmin = "<<hmin<<endl<<endl;
				cout<<"GrParent:"<<endl;
				disp(g.p->c);
				g.p=g.cu;
				g.cu=g.cu->child[id-1];
				cout<<"Parent:"<<endl;
				disp(g.p->c);
				cout<<"Child:"<<endl;
				disp(g.cu->c);
				
				cout<<"--------------------------------"<<endl;
				
				moves(g.cu->c,goal,g,c-1);
				
				break;
			}
			
		}
}

int main()
{
	int x[3][3] = {{2,8,3},{1,6,4},{7,0,5}};
	int goal[3][3] = {{1,2,3},{8,0,4},{7,6,5}};
	
	Graph g= Graph(x);
	vector<Node*> open, close;
	
	Node *n=new Node;
	cpy(n->c,x);
	n->h=h(x,goal);
	
	open.push_back(n);
	disp(x);
	cout<<"\nh(n)="<<h(x,goal)<<endl;
	int c=10;
	moves(x,goal,g,c);
}
