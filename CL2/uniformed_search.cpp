#include<iostream>
#include <vector>
#include <typeinfo>
#include <string.h>
using namespace std;

typedef struct Node
{
    string data;
    vector<Node*> child;
}Node;

class Graph
{
public:
    Node *root;
    Graph()
    {
        root=new Node;
        root->data="root";
    }
    void addChild(Node *r, string v)
    {
        Node *n= new Node;
        n->data = v;
        r->child.push_back(n);
    }
    void printChildDFS(Node *r)
    {
        vector<Node*>::iterator j=r->child.begin();
        for(;j!=r->child.end();j++){
        	cout<< (*j)->data <<endl;
        	printChildDFS((*j));
        }
    }
    void printChildBFS(Node *r)
    {
        vector<Node*> q;
        q.push_back(r);
        
        cout<<r->data<<endl;
        
        while(!q.empty())
        {
        	Node *t = q.back();
        	q.pop_back();
        	
        	vector<Node*>::iterator j=t->child.begin();
        	for(;j!=t->child.end();j++){
        		q.push_back(*j);
        		cout<<(*j)->data<<endl;
            }
        }
    }
};
int main()
{
    cout<<"Hello, World!"<<endl;
    Graph g=Graph();
    
    g.addChild(g.root,"test");
    g.addChild(g.root,"test2");
    g.addChild(g.root,"test3");
    g.addChild(g.root,"test4");
    
    g.addChild(g.root->child[0],"prod1");
    g.addChild(g.root->child[0],"prod2");
    
    g.addChild(g.root->child[2],"prod3");
    g.addChild(g.root->child[2],"prod4");
    
    g.addChild(g.root->child[0]->child[0],"prod14");    
    
    cout<<"BFS"<<endl;
    g.printChildBFS(g.root);
    
    cout<<endl<<endl;
	cout<<"DFS"<<endl;
    g.printChildDFS(g.root);

}
