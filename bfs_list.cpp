#include<iostream>
using namespace std;
struct node
{
	int vertex;
	node*next;
};

node*adj[50];//declaration of adjacency list for storing graph node
void create_graph();
int n,val,nb;//declare varaibles to store no of vertices,value of node and no of neighbour

void create_graph()
{
	
	cout<<"Enter how many nodes are there in graph: ";
	cin>>n;
	for(int i=1;i<=n;i++) //// Loop through each node to initialize and connect the nodes
	{
		adj[i]=NULL; //// Initialize the adjacency list for vertex i to NULL (no neighbors initially)
		cout<<"Enter value of "<<i<<":";
		cin>>val;

		node *nn=new node; //// Allocate memory for the new node
		node *last; // Pointer to keep track of the last node in the list (to add new nodes at the end)

		nn->vertex=val;
		nn->next=NULL;

		adj[i]=last=nn; // Set 'adj[i]' to point to the new node (head of the list) and assign 'last' to point to it


		cout<<"Enter how many nodes are connected to "<<val<<": ";
		cin>>nb;
		for(int j=1;j<=nb;j++)
		{
			cout<<"Enter value of node: ";
			cin>>val;
			node*nn=new node;
			nn->vertex=val;
			nn->next=NULL;
			last->next=nn;
			last=nn;
		}
	}
	cout<<"Graph in adjecency list format: ";
	for(int i=1;i<=n;i++)
	{
		node*temp=adj[i];
		while(temp!=NULL)
		{
			cout<<temp->vertex<<"->";
			temp=temp->next;
		}
		cout<<"NULL"<<endl;
	}
}
int arr[50];
int front=-1,rear=-1;
void insertion(int m);
int deletion();
bool isempty();
bool isempty()
{
	if((front==-1 && rear==-1)||(front>rear))
		return true;
	else
	return false;
}
void insertion(int m)
{
	if(front==-1)
	{
		front=rear=0;	
	}
	else
	rear++;
	arr[rear]=m;
}
int deletion()
{
int n;
	if(isempty())
	{
		cout<<"Queue is underflow!";
	}
	else
	{	
		 n=arr[front];
		front++;

	}
	return n;
}
const int ready=0,wait=1,processed=2;
int status[10];
int start;
void bfs()
{
	
	for(int i=1;i<=n;i++)
	{
		status[i]=ready;
	}
	cout<<"Enter root node: ";
	cin>>start;
	insertion(start);
	status[start]=wait;
	while(!isempty())
	{
		int del=deletion();
		status[del]=processed;
		cout<<del<<" ";
		node*temp=adj[del];
		while(temp!=NULL)
		{
			int n=temp->vertex;
			//check status of n
			if(status[n]==ready)
			{
				insertion(n);
				status[n]=wait;
			}
			temp=temp->next;
		}
	}
}


				
int main()
{
	create_graph();
	bfs();
	return 0;
}
