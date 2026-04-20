from collections import deque
def bfs(start, goal):
    queue=deque([(start, [])])#state ,path
    visited=set([start])
    
    while queue:
        state, path = queue.popleft()
        if state==goal:
            return path + [state]
    
        zero = state.index(0)
        moves = [-3,3,-1,1]

        for move in moves:
            new = zero+move
            if 0<= new <9: #be inside grid
                lst = list(state) #convert to list
                lst[zero], lst[new]=lst[new], lst[zero]
                new_state=tuple(lst)

                if new_state not in visited:
                    visited.add(new_state)
                    queue.append((new_state, path + [state]))

start=(1,2,3,4,0,6,7,5,8)
goal=(1,2,3,4,5,6,7,8,0)

solution = bfs(start,goal)

for step, state in enumerate(solution):
    print("Step", step)
    print(state[:3])
    print(state[3:6])
    print(state[6:])
    print("---------") 