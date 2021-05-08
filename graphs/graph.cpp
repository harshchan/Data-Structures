#include<iostream>
#include<list>
#include<bits/stdc++.h>
using namespace std;
class Graph
{
	private:
		int v;
		list <int> *adj;
	public:
		Graph(int v);
		void addEdge(int x,int y);
		void BFS(int source,int dest);
		void DFS();
		
};

Graph::Graph(int v)
{
	this->v=v;
	adj=new list<int>[v];
	
}

void Graph::addEdge(int x, int y)
{
	adj[v].push_back(y);
}
void Graph::BFS(int source,int dest)
{
	bool *check=new bool[v];
	for(int i=0;i<v;i++)
	{
		check[i]=false;
	}
	check[source]=true;
	queue.push_back(source);
	list<int>::iterator i;
	
	while(!queue.empty())
	{
		source=queue.front();
		cout<<s<<" -> ";
		queue.pop_front();
		
		for(i=adj[s].begin();i!=adj[s].end();i++)
		{
			if(check[*i]==check[dest])
			{
				cout<<"\n Distance between source and dest is"<<distance;
			}
			else
			distance++;
			
			if(!checked[*i])
			{
				checked[*i]=true;
				queue.push_back(*i);
			}
			
		}
	}
	cout<<endl;
}
