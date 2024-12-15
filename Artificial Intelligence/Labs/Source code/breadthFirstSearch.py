from collections import defaultdict

class Graph:
    # Constructor
    def __init__(self):
        self.graph = defaultdict(list)
    
    # Function to add an edge to the graph
    def addEdge(self, u, v):
        self.graph[u].append(v)
    
    # Function to perform BFS
    def BFS(self, s):
        # Mark all vertices as not visited
        visited = [False] * (max(self.graph) + 1)

        # Create a queue for BFS
        queue = []

        # Mark the source node as visited and enqueue it
        queue.append(s)
        visited[s] = True

        while queue:
            # Dequeue a vertex from the queue and print it
            s = queue.pop(0)
            print(s, end=" ")

            # Get all adjacent vertices of the dequeued vertex s
            # If an adjacent vertex has not been visited, mark it visited and enqueue it
            for i in self.graph[s]:
                if not visited[i]:
                    queue.append(i)
                    visited[i] = True

# Create a graph and add edges
g = Graph()
g.addEdge(0, 1)
g.addEdge(0, 2)
g.addEdge(1, 2)
g.addEdge(2, 0)
g.addEdge(2, 3)
g.addEdge(3, 3)

print("Following is Breadth-First Traversal (starting from vertex 2):")
g.BFS(2)
