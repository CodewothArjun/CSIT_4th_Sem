# Recursive Python function to solve Tower of Hanoi
def TowerOfHanoi(n, from_rod, to_rod, aux_rod):
    if n == 1:
        print("Move disk 1 from rod", from_rod, "to rod", to_rod)
        return
    
    # Move n-1 disks from the source to auxiliary rod
    TowerOfHanoi(n-1, from_rod, aux_rod, to_rod)
    
    # Move nth disk from source to destination rod
    print("Move disk", n, "from rod", from_rod, "to rod", to_rod)
    
    # Move the n-1 disks from auxiliary rod to destination rod
    TowerOfHanoi(n-1, aux_rod, to_rod, from_rod)

# Driver code
n = 3  # Number of disks
TowerOfHanoi(n, 'A', 'C', 'B')  # A, C, B are the names of the rods
print("\n\n")