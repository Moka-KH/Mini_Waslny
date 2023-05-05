#pragma once
#include <iostream>
#include <string.h>
#include <unordered_map>
#include <list>


using namespace std;

class graph
{
private:
	int vertexNum;

public:

	// unordered_map (hash table) storing all data we have
	// key: city name - value: linked list of the connected vertices
	// each list element is a pair of 2 values:
	// name of adjacent city - the distance between it and the original vertex
	unordered_map <string, list<pair <string, float>>> map;

	pair <string, float> pairHolder;

	// itrators for Map and List
	unordered_map <string, list<pair <string, float>>>::iterator mapIterator;
	list <pair <string, float>>::iterator listIterator;

	graph();
	~graph();

	void addCity(string newCity);
	void addCity(string newCity, string adjCity, float distance);
	void addRoad(string city1, string city2, float distance);

	void deleteCity(string cityName);
	void deleteRoad(string city1, string city2);

	int getVertexNum();
	void display();
	//Dina and Mayar
	void getAdjacentList(string city, list<pair <string, float>>& adj);
	bool checkCity(string cityName);
	bool checkEdge(string city1,string city2);

};