#pragma once
#include <string>
#include <iostream>
#include<list>
//
using namespace std;
enum Color// colors for the status of the vertex
{
	white, gray, black
};
class Edge;

class Vertex
{
public:
	int d;//time of discovery 
	int f;//finish time
	Color color;
	list<Edge*> edgeList;
	string key;
	Vertex* pi;// the father
	Vertex(string myKey);//c-tor
	~Vertex();//d-tor
	bool addEdge(Vertex* v);
	bool searchVertex(Vertex* v);
	void print();
	void removeEdge(Edge* e);
};
class Edge
{
public:
	Vertex* source;
	Vertex* destination;
	friend class Vertex;

	Edge();//defult c-tor
	Edge(Vertex* mysource, Vertex* myDestination);//c-tor
	Edge(Vertex* mysource, string myDestination);//c-tor
	~Edge();//d-tor
	bool operator==(Edge other);
};

