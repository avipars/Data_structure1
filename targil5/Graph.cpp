//
#include"Graph.h"
//
Graph::Graph() {}//ctor
Graph::~Graph() {}//dtor

bool Graph::addVertex(string str)//add  new vertex for graph
{
	if (graph.find(str) != graph.end())
		return false;
	graph.insert(pair<string, Vertex*>(str, new Vertex(str)));//add the vertex
	return true;
}
bool Graph::addEdge(string str1, string str2)//add  new edge for graph
{
	map<string, Vertex*>::iterator it1 = graph.find(str1), it2 = graph.find(str2);
	if (it1 != graph.end() && it2 != graph.end())
		if (it1->second->addEdge(it2->second))
			return true;
	return false;
}
void Graph::DFSVisit(Vertex* v)
{
	v->color = gray;
	v->d = ++timer;
	list<Edge*>::iterator item = v->edgeList.begin(), itEnd = v->edgeList.end();
	for (; item != itEnd; item++)
		if ((*item)->destination->color == white)//if the vertex is white 
		{
			(*item)->destination->pi = v;
			DFSVisit((*item)->destination);
		}
	v->color = black;
	order.push_front(v);
	v->f = ++timer;
}
void Graph::DFS()
{
	order.clear();
	timer = 0; //initialize clock
	map<string, Vertex*>::iterator it = graph.begin(), itEnd = graph.end();
	for (; it != itEnd; it++)//initialize all vertices
		it->second->color = white, it->second->pi = NULL;
	for (it = graph.begin(); it != itEnd; it++)//DFS on all vertices
		if (it->second->color == white)
			DFSVisit(it->second);
}

void Graph::topologicalSorting()//topological sort  tasks
{
	DFS();//sort according to DFS 
	cout << "order: ";
	list<Vertex*>::iterator item = order.begin(), itEnd = order.end();
	for (; item != itEnd; item++)//for the keys
		cout << (*item)->key << " ";
	cout << endl;
}
void Graph::printAll()
{
	map<string, Vertex*>::iterator map = graph.begin(), itMapEnd = graph.end();
	for (; map != itMapEnd; map++)//for all verte print
	{
		cout << map->first << ": ";
		map->second->print();
		cout << endl;
	}
}
