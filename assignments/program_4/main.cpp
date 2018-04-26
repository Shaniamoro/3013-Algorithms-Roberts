/*
* Name: Shania Roberts
* Date: 04.20.18
* Assignment: Program 4
* Description: Create a graph structure with cities as Vertices and
 * no Edges initially. Fully connect your cities by adding edges
 * between cities that are close together. Basically create a
 * connected graph of all the cities so that every city is
 * reachable by ensuring that each vertex has a max degree of 3,
 * where each edge represents one of three closest cities to that
 * vertex.
 */

// A simple representation of graph using STL
#include "graph.h"
#include <fstream>
using namespace std;

/**
* randomEdges - creates random edges between vertices
* Params:  graph object and number of edges
* Returns:  none
*/

void randomEdges(graph &g,int numEdges){
    int r1,r2;
    latlon from;
    latlon to;
    double d;
    for(int i=0;i<numEdges;i++){
        r1 = rand() % g.vertexList.size();
        r2 = rand() % g.vertexList.size();
        from = g.vertexList[r1]->loc;
        to = g.vertexList[r2]->loc;
        d = distanceEarth(from.lat,from.lon,to.lat,to.lon);
        g.addEdge(r1,r2,(int)d,true);
    }
}

/**
 * loadGraphCSV - loads a graph with the given csv
 * Params:  string filename  - filename to open
 * Returns:  graph no edges
 */
graph loadGraphCSV(string filename,int max=0)
{
    int zip;
    double lat;
    double lon;
    string city;
    string state;
    string county;


    strMapInt cityCheck;

    int i=0;

    graph H;


    ifstream file(filename);

    for (CSVIterator loop(file); loop != CSVIterator(); ++loop)
    {
        zip = stoi((*loop)[0]);
        if ((*loop)[1].length() > 0)
        {
            lat = stod((*loop)[1]);
        }
        else
        {
            lat = 0.0;
        }

        if ((*loop)[2].length() > 0)
        {
            lon = stod((*loop)[2]);
        }
        else
        {
            lon = 0.0;
        }

        city = (*loop)[3];
        state = (*loop)[4];
        county = (*loop)[5];

        
        if (cityCheck.find(city) == cityCheck.end())
        {   
            // Add the city as a key to the map.
            cityCheck[city] = 0;

            if(state != "PR"){
                H.addVertex(city, state, lat, lon);
                i++;
            }
        }

        if(i > max && max != 0){
            return H;
        }
        
    }

    return H;
}
/* loadGraphPR- loads a graph with the given file
 * only loads the cities in PR
 * string filename- filename to open
 * Returns the Graph with no edges.
 *
 * */
graph loadGraphPR(string filename,int max=0)
{
    int zip;
    double lat;
    double lon;
    string city;
    string state;
    string county;


    strMapInt cityCheck;

    int i=0;

    graph G;

    ifstream file(filename);

    for (CSVIterator loop(file); loop != CSVIterator(); ++loop)
    {
        zip = stoi((*loop)[0]);
        if ((*loop)[1].length() > 0)
        {
            lat = stod((*loop)[1]);
        }
        else
        {
            lat = 0.0;
        }

        if ((*loop)[2].length() > 0)
        {
            lon = stod((*loop)[2]);
        }
        else
        {
            lon = 0.0;
        }

        city = (*loop)[3];
        state = (*loop)[4];
        county = (*loop)[5];


        if (cityCheck.find(city) == cityCheck.end())
        {
            // Add the city as a key to the map.
            cityCheck[city] = 0;

            if(state == "PR"){
                G.addVertex(city, state, lat, lon);
                i++;
            }
        }

        if(i > max && max != 0){
            return G;
        }

    }

    return G;
}
/**
 * filterDups - filters out duplicate cities and creates new output file
 * Params:
 *     string filename  - filename to open
 *     string outfile   - filename to write to
 * Returns 
 *     graph
 */
void filterDups(string filename,string outfile)
{
    int zip;
    double lat;
    double lon;
    string city;
    string state;
    string county;

    strMapInt cityCheck;

   // int i=0;


    ifstream file(filename);
    ofstream out(outfile);

    for (CSVIterator loop(file); loop != CSVIterator(); ++loop)
    {
        zip = stoi((*loop)[0]);
        if ((*loop)[1].length() > 0)
        {
            lat = stod((*loop)[1]);
        }
        else
        {
            lat = 0.0;
        }

        if ((*loop)[2].length() > 0)
        {
            lon = stod((*loop)[2]);
        }
        else
        {
            lon = 0.0;
        }

        city = (*loop)[3];
        state = (*loop)[4];
        county = (*loop)[5];

        
        if (cityCheck.find(city) == cityCheck.end())
        {   
            // Add the city as a key to the map.
            cityCheck[city] = 0;
            out<<zip<<","<<lat<<","<<lon<<","<<city<<","<<state<<","<<county<<"\n";

        }

        
    }

}

// Test Driver
int main(int argc, char **argv)
{
    srand(984325);
    int max_vertices = 0;
    int max_edges = 0;
    int size_of_degree;
    argc=3;

    if(argc > 2){
       // max_vertices = stoi(argv[1]);
        max_vertices =18953;

    }else{
        cout<<"Usage: ./graph max_vertices max_edges"<<endl;
        //system("pause");
        exit(0);
    }

    //File to write the output
    ofstream outfile;
    outfile.open("../output.txt");
    ofstream graphFile;
    graphFile.open("../graphViz.dat");


    //Prompt for user to enter size of degree
    cout << "What should we set the size of the degree: " << endl;
    cin >> size_of_degree;
    cout << endl;

    //Loads the graph
    
    graph G = loadGraphPR("../filtered_cities.csv",max_vertices);
    graph H = loadGraphCSV("../filtered_cities.csv",max_vertices);


    string key;

    //Begin
    outfile << "\n";
    outfile << "Lebanon, Kansas" << "\n";
    H.createSpanningTree("KS", size_of_degree);
    outfile << H.distanceTotal << " miles " << H.edge_count << " edges " << "\n";


    outfile << "\n";
    outfile << "Miami Beach, Florida" << "\n";
    H.createSpanningTree("FL", size_of_degree);
    outfile << H.distanceTotal << " miles " << H.edge_count << " edges " << "\n";

    outfile << "\n";
    outfile << "Lake Dallas, Texas" << endl;
    H.createSpanningTree("TX", size_of_degree);
    outfile << H.distanceTotal << " miles " << H.edge_count << " edges " << "\n";

    outfile << "\n";
    outfile << "Boston, Massachusetts" << endl;
    H.createSpanningTree("MA", size_of_degree);
    outfile << H.distanceTotal << " miles " << H.edge_count << " edges " << "\n";


    outfile << "\n";
    outfile << "San Juan, Puerto Rico" << endl;
    G.createSpanningTree("PR", size_of_degree);
    outfile << G.distanceTotal << " miles " << G.edge_count << " edges " << "\n";

    //Prints a directed graph if true.

   // cout<<G.graphViz(true);
    graphFile <<G.graphViz(false);
    graphFile.close();

    int *size = G.graphSize();

    cout<<"V= "<<size[0]<<" E= "<<size[1]<<endl;
    for(int i = 0; i < G.vertexList.size(); i++) {
        cout << (*G.vertexList[i]) << endl;
    }

    outfile.close();

    //filterDups("cities.csv","filtered_cities.csv");
    
    //randomEdges(G,max_edges);

    //G.printGraph();
    //cout<<G.searchGraph("truro")<<endl;

    //G.createSpanningTree("PR");


    //G.printVids();

    //int *size = G.graphSize();

    //cout<<"V= "<<size[0]<<" E= "<<size[1]<<endl;

    //system("pause");
    return 0;
}
