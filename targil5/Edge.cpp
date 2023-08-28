//
#include "Edge.h"
Vertex::Vertex(string myKey)//ctor
{
	color = white;
	key = myKey;
}
Vertex::~Vertex()//dtor
{
	delete pi;
}
void Vertex::print()//print all the clos to
{
	for (list<Edge*>::iterator item = edgeList.begin(), edgEnd = edgeList.end(); item != edgEnd; item++)//clos to
		cout << (*item)->destination->key;
}
bool Vertex::searchVertex(Vertex* v)
{
	for (list<Edge*>::iterator item = edgeList.begin(), edgEnd = edgeList.end(); item != edgEnd; item++)//close to
		if ((*item)->destination->key == v->key)
			return true;
	return false;
}
void Vertex::removeEdge(Edge* edge)
{
	edgeList.remove(edge);
}

bool Vertex::addEdge(Vertex* vertex)//add new Edge
{
	if (!searchVertex(vertex))
	{
		Edge* edg = new Edge(this, vertex);
		edgeList.push_back(edg);//add  new edge to  list
		return true;
	}
	return false;
}

//Edge
Edge::Edge() {}//defult ctor
Edge::Edge(Vertex* mysource, Vertex* myDestination)//ctor
{
	source = mysource;
	destination = myDestination;
}
Edge::Edge(Vertex* vesource, string myDestination) //ctor
{
	source = vesource;
	destination = new Vertex(myDestination);
}
Edge::~Edge()//d-tor
{
	delete source;
	delete destination;
}
bool Edge::operator==(Edge edg)
{
	return destination == edg.destination && source == edg.source;
}