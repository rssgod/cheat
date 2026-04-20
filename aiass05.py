
import heapq


def manhattan_distance(state, goal_state, side_length):
    '''
    Heuristic function:
    Calculates total Manhattan distance of tiles
    from their goal positions.
    '''

    distance = 0

    # Precompute goal positions
    goal_pos = {
        tile: divmod(i, side_length)
        for i, tile in enumerate(goal_state)
    }

    for i, tile in enumerate(state):
        if tile != 0:
            curr_row, curr_col = divmod(i, side_length)
            goal_row, goal_col = goal_pos[tile]

            distance += (
                abs(curr_row - goal_row)
                + abs(curr_col - goal_col)
            )

    return distance


def solve_puzzle_astar(start_state, goal_state):
    '''
    Solves the N-Puzzle using A* Search.

    f(n) = g(n) + h(n)
    g(n): cost from start
    h(n): Manhattan heuristic
    '''

    side_length = int(len(start_state) ** 0.5)

    priority_queue = []

    h_start = manhattan_distance(
        start_state,
        goal_state,
        side_length
    )

    heapq.heappush(
        priority_queue,
        (h_start, 0, start_state, [])
    )

    g_costs = {start_state: 0}
    visited = set()

    print(f'Starting A* Search for {side_length}x{side_length} board...')

    while priority_queue:
        f, g, current_state, path = heapq.heappop(priority_queue)

        if current_state == goal_state:
            return path + [current_state]

        if current_state in visited:
            continue

        visited.add(current_state)

        empty_idx = current_state.index(0)
        row, col = divmod(empty_idx, side_length)

        for dr, dc in [(-1, 0), (1, 0), (0, -1), (0, 1)]:
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
                new_g = g + 1

                if (
                    new_state not in g_costs
                    or new_g < g_costs[new_state]
                ):
                    g_costs[new_state] = new_g

                    h = manhattan_distance(
                        new_state,
                        goal_state,
                        side_length
                    )

                    heapq.heappush(
                        priority_queue,
                        (
                            new_g + h,
                            new_g,
                            new_state,
                            path + [current_state]
                        )
                    )

    return None


def print_board(state):
    side = int(len(state) ** 0.5)

    for i in range(0, len(state), side):
        print(' '.join(f'{x:2}' for x in state[i:i + side]))

    print('-' * 15)


if __name__ == '__main__':
    start = (
        1, 2, 3, 4,
        5, 6, 0, 8,
        9, 10, 7, 12,
        13, 14, 11, 15
    )

    goal = (
        1, 2, 3, 4,
        5, 6, 7, 8,
        9, 10, 11, 12,
        13, 14, 15, 0
    )

    solution = solve_puzzle_astar(start, goal)

    if solution:
        print(f'Success! Optimal solution is {len(solution) - 1} moves.')

        for step, state in enumerate(solution):
            print(f'Move {step}:')
            print_board(state)
    else:
        print('No solution exists for this configuration.')

