from collections import defaultdict

# Jug capacities and the target amount
jug1, jug2, aim = 4, 3, 2

# Initialize dictionary with default value as False to track visited states
visited = defaultdict(lambda: False)

# Recursive function to solve the water jug problem
def waterJugSolver(amt1, amt2):
    # If we reach the goal, print the solution and return True
    if (amt1 == aim and amt2 == 0) or (amt2 == aim and amt1 == 0):
        print(amt1, amt2)
        return True
    
    # If this state has already been visited, skip to avoid infinite recursion
    if visited[(amt1, amt2)] == False:
        # Print the current state
        print(amt1, amt2)
        
        # Mark the current state as visited
        visited[(amt1, amt2)] = True

        # Explore all possible moves:
        return (waterJugSolver(0, amt2) or          # Empty jug1
                waterJugSolver(amt1, 0) or          # Empty jug2
                waterJugSolver(jug1, amt2) or       # Fill jug1
                waterJugSolver(amt1, jug2) or       # Fill jug2
                waterJugSolver(amt1 + min(amt2, jug1 - amt1), amt2 - min(amt2, jug1 - amt1)) or  # Pour jug2 into jug1
                waterJugSolver(amt1 - min(amt1, jug2 - amt2), amt2 + min(amt1, jug2 - amt2)))    # Pour jug1 into jug2
    
    # Return False if no solution is found
    else:
        return False

# Driver code
print("Steps: ")
waterJugSolver(0, 0)
print("\n\n")