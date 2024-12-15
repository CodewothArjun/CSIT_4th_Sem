from sys import maxsize
from itertools import permutations

# Number of vertices in the graph (cities)
V = 4

# Implementation of the Travelling Salesman Problem
def travellingSalesmanProblem(graph, s):
    # Store all vertices except the source vertex
    vertex = []
    for i in range(V):
        if i != s:
            vertex.append(i)

    # Store the minimum weight of the Hamiltonian Cycle
    min_path = maxsize

    # Generate all permutations of the vertices (except the start vertex)
    next_permutation = permutations(vertex)
    
    # Check each permutation
    for i in next_permutation:
        # Store current path weight (cost)
        current_pathweight = 0
        
        # Compute the current path weight
        k = s
        for j in i:
            current_pathweight += graph[k][j]
            k = j
        
        # Add the cost to return to the starting point
        current_pathweight += graph[k][s]

        # Update the minimum path cost
        min_path = min(min_path, current_pathweight)

    return min_path

# Driver Code
if __name__ == "__main__":
    # Matrix representation of the graph
    graph = [[0, 10, 15, 20],
             [10, 0, 35, 25],
             [15, 35, 0, 30],
             [20, 25, 30, 0]]
    
    # Starting vertex (source city)
    s = 0

    # Output the minimum path cost
    print("Minimum path cost:", travellingSalesmanProblem(graph, s))
print("\n\n")