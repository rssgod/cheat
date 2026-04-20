
from collections import deque


def solve_puzzle_bfs(start_state, goal_state):
    '''
    Solves the N-Puzzle game using Breadth First Search
    to find the optimal moves.

    Args:
        start_state (tuple): Initial configuration.
        goal_state (tuple): Target configuration.
    '''

    # Board dimension
    side_length = int(len(start_state) ** 0.5)

    # BFS queue -> (state, path)
    queue = deque([(start_state, [])])

    # Visited states
    visited = {start_state}

    print(
        f'Starting BFS to find the optimal solution '
        f'for a {side_length}x{side_length} board...'
    )

    while queue:
        current_state, path = queue.popleft()

        # Goal check
        if current_state == goal_state:
            return path + [current_state]

        empty_idx = current_state.index(0)
        row, col = divmod(empty_idx, side_length)

        # Possible movements
        moves = [
            (-1, 0, 'Up'),
            (1, 0, 'Down'),
            (0, -1, 'Left'),
            (0, 1, 'Right')
        ]

        for dr, dc, direction in moves:
            new_row = row + dr
            new_col = col + dc

            if 0 <= new_row < side_length and 0 <= new_col < side_length:
                target_idx = new_row * side_length + new_col

                new_state_list = list(current_state)
                new_state_list[empty_idx], new_state_list[target_idx] = (
                    new_state_list[target_idx],
                    new_state_list[empty_idx]
                )

                new_state = tuple(new_state_list)

                if new_state not in visited:
                    visited.add(new_state)
                    queue.append(
                        (new_state, path + [current_state])
                    )

    return None


def print_board(state):
    '''
    Helper function to visualize puzzle board.
    '''
    side = int(len(state) ** 0.5)

    for i in range(0, len(state), side):
        print(state[i:i + side])

    print('-' * 10)


if __name__ == '__main__':
    # Example 8-Puzzle
    start = (
        1, 2, 3,
        4, 0, 6,
        7, 5, 8
    )

    goal = (
        1, 2, 3,
        4, 5, 6,
        7, 8, 0
    )

    solution = solve_puzzle_bfs(start, goal)

    if solution:
        print(f'Optimal solution found in {len(solution) - 1} moves!')

        for step, state in enumerate(solution):
            print(f'Step {step}:')
            print_board(state)
    else:
        print('No solution exists.')

