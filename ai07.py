#7. Implement a solution for a Constraint Satisfaction Problem using Branch and Bound
#or Backtracking a graph coloring problem.

# Number of vertices
n = 4

# Graph (Adjacency Matrix)
graph = [
    [0, 1, 1, 1],
    [1, 0, 1, 0],
    [1, 1, 0, 1],
    [1, 0, 1, 0]
]

# Number of colors
m = 3

# Store colors of vertices
color = [0] * n


# Check if safe to color vertex v with color c
#If:
#There is an edge
#AND neighbor already has same color
#➡ Not allowed

def isSafe(v, c):
    for i in range(n):
        if graph[v][i] == 1 and color[i] == c:
            return False
    return True


# Backtracking function
def solve(v):
    # All vertices colored
    if v == n:
        return True

    # Try all colors
    for c in range(1, m + 1):
        if isSafe(v, c):
            color[v] = c

            if solve(v + 1):
                return True

            # Backtrack
            color[v] = 0

    return False


# Main
if solve(0):
    print("Solution exists:")
    for i in range(n):
        print("Vertex", i, "-> Color", color[i])
else:
    print("No solution")