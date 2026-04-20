import heapq
def heuristic(state, goal):
    return sum(abs(i//4 -  goal.index(tile)//4) + abs(i%4 - goal.index(tile)%4)
                for i, tile in enumerate(state) if tile!=0)
                
def astar(start, goal):
    pq=[]
    heapq.heappush(pq,(0, start, []))
    visited=set()
    
    while pq:
        cost, state, path = heapq.heappop(pq)
        
        if state==goal:
            return path+[state]
            
        if state in visited:
            continue
        visited.add(state)
        
        zero= state.index(0)
        moves=[-4,4,-1,1]
        
        for move in moves:
            new=zero+move
            if 0<= new<16:
                lst=list(state)
                lst[zero], lst[new]= lst[new], lst[zero]
                new_state=tuple(lst)
                
                heapq.heappush(pq,
                (cost+1+heuristic(new_state, goal), 
                new_state,
                path+ [state]))
                
                
start = (1,2,3,4,5,6,0,8,9,10,7,12,13,14,11,15)
goal = (1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,0)

solution = astar(start, goal)

for i , s in enumerate(solution):
    print("move", i)
    for j in range (0,16,4):
        print(s[j:j+4])
    print("------------")

        