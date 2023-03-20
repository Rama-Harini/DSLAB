#include <stdio.h>
#include <stdlib.h>



struct node
{


    int vertexNumber;




    struct node *pointerToNextVertex;
};


struct Graph
{

    int numberOfVertices;


    int *visitedRecord;

    // Adjacency Lists is a 2 dimensioanl array
    // It will be used to maintain the adjacency list for each vertex of the graph
    // For example: adjacencyLists[1] will denote the adjacency list of 1st vertex of graph
    // And it will contain all nodes connected to the 1st vertex of the graph
    struct node **adjacencyLists;
};

/* ---------------------------------- Required Helper Functions ---------------------------------- */
// Function to create a Node
// It will be used to create the node for which the structure is defined above
// Parameters: An integer Vertex, to represent the vertex number
struct node *createNodeForList(int v)
{
    // Use malloc to dynamically allocate Memory
    struct node *newNode = malloc(sizeof(struct node));

    // Allocate the vertex Number
    // Means the "v" vertex is connected to the vertex whose adjacency list contains this entire node
    newNode->vertexNumber = v;

    // Assign the next vertex to NULL
    // COnsider it is the last connected vertex
    newNode->pointerToNextVertex = NULL;
    return newNode;
}


void addEdgeToGraph(struct Graph *graph, int source, int destination)
{
 struct node *newNode = createNodeForList(destination);

    newNode->pointerToNextVertex = graph->adjacencyLists[source];

   newNode = createNodeForList(source);
    newNode->pointerToNextVertex = graph->adjacencyLists[destination];
    graph->adjacencyLists[destination] = newNode;
}


struct Graph *createGraph(int vertices)
{
     int i;
     struct Graph *graph = malloc(sizeof(struct Graph));
    graph->numberOfVertices = vertices;
adjacencyLists = malloc(vertices * sizeof(struct node *));
   graph->visitedRecord = malloc(vertices * sizeof(int));
   for (i = 0; i < vertices; i++)
    {
        graph->adjacencyLists[i] = NULL;
        graph->visitedRecord[i] = 0;
    }
    return graph;
}
void depthFirstSearch(struct Graph *graph, int vertexNumber)
{
    struct node *adjList = graph->adjacencyLists[vertexNumber];
    struct node *temp = adjList;

    graph->visitedRecord[vertexNumber] = 1;
    printf("%d ", vertexNumber);

    while (temp != NULL)
    {
        int connectedVertex = temp->vertexNumber;

        if (graph->visitedRecord[connectedVertex] == 0)
        {
            depthFirstSearch(graph, connectedVertex);
        }
        temp = temp->pointerToNextVertex;
    }
}

int main()
{
    int numberOfVertices, numberOfEdges, i;
    int source, destination;
    int startingVertex;

    printf("Enter Number of Vertices and Edges in the Graph: ");
    scanf("%d %d", &numberOfVertices, &numberOfEdges);
    struct Graph *graph = createGraph(numberOfVertices);

    printf("Add %d Edges of the Graph(Vertex numbering should be from 0 to %d)\n", numberOfEdges, numberOfVertices - 1);
    for (i = 0; i < numberOfEdges; i++)
    {
        scanf("%d%d", &source, &destination);
        addEdgeToGraph(graph, source, destination);
    } 

    printf("Enter Starting Vertex for DFS Traversal: ");
    scanf("%d", &startingVertex);

    if (startingVertex < numberOfVertices)
    {
        printf("DFS Traversal: ");
        depthFirstSearch(graph, startingVertex);
    }
    return 0;
}

