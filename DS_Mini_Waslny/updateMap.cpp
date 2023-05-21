#include "graph.h"
#include "updateMap.h"
#include "homePage.h"
#include "enumerators.cpp"

// This file has functions that separate the messages from the graph class functions
// in order to make the data loading in the beginning of the program silent

/**
* This function adds the city to the provided graph and based on the return value
* of addCity(), it displays a feedback message
* 
* @param myGraph the graph to add the city to
* @return void
*/
void addCity(graph& myGraph)
{
    cout << "\t\tAdding a City\n";
    cout << "\tName: ";
    string city;
    cin >> city;

    int message = myGraph.addCity(city);

    if (message == cityExists)
        cout << "City " << city << " already exists =|\n";
    else if (message == success)
        cout <<"Added \"" << city << "\" =)\n";
}

/**
* This function lets the user add / edit a road.. it uses the the addRoad function from
* the graph class and calls addRoadFeedback() which handles the feedback messages that appear
* to the user
* 
* @param myGraph the graph to add / edit its roads
* @return void
*/
void addOrEditRoad(graph& myGraph)
{
    string city1, city2;
    float distance;
    cout << "Adding / Updating Road:\n";
    cout << "\tCity 1: ";
    cin >> city1;
    cout << "\tCity 2: ";
    cin >> city2;   
    cout << "\tDistance: ";
    
    // input valid distance
    while (true)
    {
        // validate it's a number
        distance = validateNumber();

        // validate it's positive
        if (distance <= 0)
            cout << "please enter a psitive distance" << endl;
        else
            break;
    }

    // ask the user: Directed or Undirected ?
    int choice;
    cout << "One way or roundway Road ?\n"
        << "1- One way \t 2- Roundway   -> ";
    cin >> choice;

    if (choice == 1)
    {
        // ask the user for the direction
        cout << "1- from " << city1 << " to " << city2 << "\n"
            << "2- from " << city2 << " to " << city1 << "\n"
            << "-> ";
        cin >> choice;

        // add the road and call addRoadFeedback() to give feedback
        int message;
        if (choice == 1)
        {
            message = myGraph.addEditRoad(city1, city2, distance);
            addRoadFeedback(city1, city2, message);
        }
        else if (choice == 2)
        {
            message = myGraph.addEditRoad(city2, city1, distance);
            addRoadFeedback(city2, city1, message);
        }
        else
            cout << "invalid choice :/\n";
    }
    else if (choice == 2)
    {
        int message1 = myGraph.addEditRoad(city1, city2, distance);
        addRoadFeedback(city1, city2, message1);

        int message2 = myGraph.addEditRoad(city2, city1, distance);
        addRoadFeedback(city2, city1, message2);
    }
}

/**
* this function prints a message in the console depending on the given message parameter
* 
* @param city1 city1 name
* @param city2 city2 name
* @param message the return value form calling addRoad() function in the graph class
* @return void
*/
void addRoadFeedback(string city1, string city2, int message)
{
    if (message == noCity1)
        cout << "Sorry! " << city1 << " doesn't exist =|" << endl;
    else if (message == noCity2)
        cout << "Sorry! " << city2 << " doesn't exist =|" << endl;
    else if (message == addedRoad)
        cout << "Added a road successfully =)" << endl;
    else if (message == updatedRoad)
        cout << "updated a road successfully =)" << endl;
}

/**
* This function lets the user delete a road.. it uses the the deleteRoad function from
* the graph class and calls deleteRoadFeedback() which handles the feedback messages that appear
* to the user
*
* @param myGraph the graph to delete its roads
* @return void
*/
void deleteRoad(graph& myGraph)
{
    string city1, city2;
    cout << "Deleing Road: \n";
    cout << "\tCity 1: ";
    cin >> city1;
    cout << "\tCity 2: ";
    cin >> city2;

    int message = myGraph.deleteRoad(city1, city2);
    deleteRoadFeedback(city1, city2, message);
}

/**
* this function prints a message in the console depending on the given message parameter
*
* @param city1 city1 name
* @param city2 city2 name
* @param message the return value form calling deleteRoad() function in the graph class
* @return void
*/
void deleteRoadFeedback(string city1, string city2, int message)
{
    switch (message)
    {
        case 1:
            cout << '\"' << city1 << "\" doesn't exist =|\n";
            break;
        case 2:
            cout << '\"' << city2 << "\" doesn't exist =|\n";
            break;
        case 3:
            cout << "There is no road between " << city1 << " and " << city2 << " =(\n";
            break;
        case 4:
            cout << "Road is deleted =)\n";
            break;
    }
}

void deleteCity(graph& myGraph)
{
    string city;
    cout << "Delete the City: ";
    cin >> city;

    int message = myGraph.deleteCity(city);
    if (message == 1)
        cout << "city " << city << " does not exist.. I can't delete it =(\n";
    else 
        cout << "City is deleted =)\n";
}