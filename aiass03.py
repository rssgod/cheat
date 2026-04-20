
def solve_water_jug_dfs(jug1_cap, jug2_cap, target):
    '''
    Solves the Water Jug problem using Depth First Search.

    Args:
        jug1_cap (int): Capacity of the first jug.
        jug2_cap (int): Capacity of the second jug.
        target (int): The goal amount of water needed in either jug.
    '''

    # Set to keep track of visited states (jug1, jug2)
    visited = set()

    # Store solution path
    path = []

    def dfs(j1, j2):
        # Check target condition
        if j1 == target or j2 == target:
            path.append((j1, j2))
            return True

        # Avoid revisiting states
        if (j1, j2) in visited:
            return False

        visited.add((j1, j2))
        path.append((j1, j2))

        # Possible operations
        possible_moves = [
            (jug1_cap, j2),  # Fill Jug 1
            (j1, jug2_cap),  # Fill Jug 2
            (0, j2),         # Empty Jug 1
            (j1, 0),         # Empty Jug 2

            # Pour Jug1 -> Jug2
            (
                j1 - min(j1, jug2_cap - j2),
                j2 + min(j1, jug2_cap - j2)
            ),

            # Pour Jug2 -> Jug1
            (
                j1 + min(j2, jug1_cap - j1),
                j2 - min(j2, jug1_cap - j1)
            )
        ]

        for move in possible_moves:
            if dfs(move[0], move[1]):
                return True

        # Backtrack
        path.pop()
        return False

    print(f'Solving for Jug1: {jug1_cap}, Jug2: {jug2_cap}, Target: {target}...')

    import math

    # GCD feasibility check
    if (
        target > max(jug1_cap, jug2_cap)
        or target % math.gcd(jug1_cap, jug2_cap) != 0
    ):
        print('No solution possible based on GCD rules.')
        return

    if dfs(0, 0):
        print('Solution found!')
        for i, state in enumerate(path):
            print(f'Step {i}: Jug1 = {state[0]}, Jug2 = {state[1]}')
    else:
        print('No solution found using DFS.')


if __name__ == '__main__':
    solve_water_jug_dfs(4, 3, 2)
