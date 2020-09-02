/* including the header files . You can directly include the stl lib but then the code does not becomes
   available to tranfer and run on other versions of the compiler also every time we compile the code it
   becomes too heavy for the compiler to preprocess each and every files so I think its better not to include
   the whole package instead only include the relevant ones and move forwardd
*/
#include<iostream>
#include<list>
#include<algorithm>
#include<string>
using namespace std;

// creating a class of Graoh and defining all the data memebers and functions
class Graph
{
  // making it public so that every function can access them and use them
public:
  // This variable is for the Vertex
  int V;

  // creating a list to store all the adjacent values of the vertexes and edges
  list<int> *adj;

  // constructor
  Graph(int V);

  // function for adding edges of the whole graph
  void addEdge(int v,int w);

  // main fucntion for the whole BFS traversal
  void BFS(int s);
};

// Constructor initialzed and assigned values
Graph::Graph(int V)
{
  this->V=V;

  // Adjacency list initailized with the no of vertexes
  adj=new list<int> [V];
}


// Adjacency list creation function
// how the adjacency list will be formed:--->
/*   1------->2-------->3--------->4
     |       |
     4      1
     |
     2
*/
void Graph::addEdge(int v,int w)
{
  adj[v].push_back(w);
}

// Main logic of the program:----------->
void Graph::BFS(int s)
{
  // creating a boolean visited array to store the boolean value of whether the vertex is
  // visited or not if not visited then 0 and if visited then 1
  bool *visited=new bool[V];

  // prefedined it to be 0
  for(int i=0;i<V;i++)
  {
    visited[i]=false;
  }

  // declaring  a queue
  list<int> queue;

  // the source vertex is pushed in the queue and marked visited
  visited[s]=true;
  queue.push_back(s);

  // this loop will run until and unless the queue becomes empty
  while(!queue.empty())
  {

    // poped the first element and o/p it
    s=queue.front();
    cout<<s<<" ";
    queue.pop_front();
  list<int>::iterator itr;

  // run a loop and access each and every element of the particular vertex and marked it true and push it
  // in the queue for futher checking its adjacent nodes;

  for(itr=adj[s].begin();itr!=adj[s].end();itr++)
  {
    if(!visited[*itr])
    {
      visited[*itr]=true;
      queue.push_back(*itr);
    }
  }
}
}


// main function
int main()
{
  // declaring a graph with 4 vertexes
    Graph g(4);

    // creating the adjacency list
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    cout << "Following is Breadth First Traversal "
         << "(starting from vertex 2) \n";

    // calling the BFS function with source vertex as 2
    g.BFS(2);

    return 0;
}
