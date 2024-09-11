import heapq

class Node:
    def __init__(self, position, cost=0, parent=None):
        self.position = position
        self.cost = cost
        self.parent = parent

    def __lt__(self, other):
        return self.cost < other.cost

def uniform_cost_search(start, goal, graph):
    open_list = []
    closed_list = set()
    
    start_node = Node(start, 0)
    goal_node = Node(goal)
    heapq.heappush(open_list, start_node)
    
    while open_list:
        current_node = heapq.heappop(open_list)
        current_position = current_node.position
        
        if current_position in closed_list:
            continue

        closed_list.add(current_position)

        if current_position == goal_node.position:
            path = []
            while current_node:
                path.append(current_node.position)
                current_node = current_node.parent
            return path[::-1], current_node.cost

        for neighbor, cost in graph[current_position].items():
            if neighbor in closed_list:
                continue

            neighbor_node = Node(neighbor, current_node.cost + cost, current_node)
            heapq.heappush(open_list, neighbor_node)
    
    return None, float('inf')  # No path found

# Example graph represented as an adjacency list with costs
graph = {
    'A': {'B': 1, 'C': 4},
    'B': {'A': 1, 'C': 2, 'D': 5},
    'C': {'A': 4, 'B': 2, 'D': 1},
    'D': {'B': 5, 'C': 1}
}

start = 'A'
goal = 'D'

path, cost = uniform_cost_search(start, goal, graph)
print("Path found:", path)
print("Total cost:", cost)
print("\n\n")