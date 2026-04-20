class GraphColoringSolver:
    def __init__(self, adjacency_matrix, num_colors):
        self.graph = adjacency_matrix
        self.num_vertices = len(adjacency_matrix)
        self.m = num_colors
        # Result array where colors[i] stores the color assigned to vertex i
        # Colors are represented by integers 1, 2, ..., m. 0 means uncolored.
        self.colors = [0] * self.num_vertices

    def is_safe(self, v, color):
        for i in range(self.num_vertices):
            if self.graph[v][i] == 1 and self.colors[i] == color:
                return False
        return True

    def solve_backtracking(self, v):
        # Base Case: All vertices are assigned a color
        if v == self.num_vertices:
            return True

        # Try assigning each color from 1 to m
        for c in range(1, self.m + 1):
            if self.is_safe(v, c):
                # Assign the color
                self.colors[v] = c

                # Recur to assign colors to the rest of the vertices
                if self.solve_backtracking(v + 1):
                    return True

                # If assigning color c doesn't lead to a solution, backtrack
                self.colors[v] = 0

        # If no color can be assigned to this vertex, return False
        return False

    def get_solution(self):
        if self.solve_backtracking(0):
            return self.colors
        return None

def main():
    # Example: A simple graph with 4 vertices
    # (0)---(1)
    #  |  X  |
    # (3)---(2)
    # Matrix representation:
    graph = [
        [0, 1, 1, 1],
        [1, 0, 1, 0],
        [1, 1, 0, 1],
        [1, 0, 1, 0]
    ]

    m_colors = 3  # Maximum number of colors allowed

    solver = GraphColoringSolver(graph, m_colors)
    solution = solver.get_solution()

    print("--- Graph Coloring CSP Solver ---")
    if solution:
        print(f"Solution found with {m_colors} colors:")
        for i, color in enumerate(solution):
            print(f"  Vertex {i} -> Color {color}")
    else:
        print(f"No solution exists with {m_colors} colors.")

if __name__ == "__main__":
    main()