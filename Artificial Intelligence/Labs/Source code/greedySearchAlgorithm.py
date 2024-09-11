import heapq

class Node:
    def __init__(self, position, parent=None):
        self.position = position
        self.parent = parent
        self.h = 0  # Heuristic cost

    def __lt__(self, other):
        return self.h < other.h

def greedy_best_first_search(start, end, grid):
    open_list = []
    closed_list = set()

    start_node = Node(start)
    end_node = Node(end)
    heapq.heappush(open_list, start_node)
    
    while open_list:
        current_node = heapq.heappop(open_list)
        closed_list.add(current_node.position)

        if current_node.position == end_node.position:
            path = []
            while current_node:
                path.append(current_node.position)
                current_node = current_node.parent
            return path[::-1]

        neighbors = [(0, 1), (1, 0), (0, -1), (-1, 0)]  # Adjacent squares: right, down, left, up
        for neighbor in neighbors:
            node_position = (current_node.position[0] + neighbor[0], current_node.position[1] + neighbor[1])
            if (0 <= node_position[0] < len(grid) and 0 <= node_position[1] < len(grid[0]) and 
                grid[node_position[0]][node_position[1]] == 0):
                if node_position in closed_list:
                    continue

                neighbor_node = Node(node_position, current_node)
                neighbor_node.h = ((end_node.position[0] - neighbor_node.position[0]) ** 2 + 
                                   (end_node.position[1] - neighbor_node.position[1]) ** 2) ** 0.5

                if any(node.position == neighbor_node.position and node.h <= neighbor_node.h for node in open_list):
                    continue

                heapq.heappush(open_list, neighbor_node)

    return None  # No path found

# Example grid: 0 is walkable, 1 is blocked
grid = [[0, 0, 0, 0, 0],
        [0, 1, 1, 1, 0],
        [0, 0, 0, 0, 0],
        [0, 1, 1, 1, 0],
        [0, 0, 0, 0, 0]]

start = (0, 0)  # Start position
end = (4, 4)    # End position

path = greedy_best_first_search(start, end, grid)
print("Path found:", path)
print("\n\n")