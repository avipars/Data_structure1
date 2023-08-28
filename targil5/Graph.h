#pragma once
//a
#include <map>
#include <list>
#include "Edge.h"
class Graph {
public:
	map<string, Vertex*> graph;
	list<Vertex*> order;
	int timer;
	Graph();//actor
	~Graph();//
	void DFS();
	void DFSVisit(Vertex* v);
	void printAll();
	void topologicalSorting();
	bool addEdge(string str, string destination);
	bool addVertex(string str);
};

