# Prim's Algorithm


import sys

def Prim(graph, V):
    visited=[False]*V
    visited[0]=True
    total=0
    
    print("Edges in MST: ")
    
    for _ in range(V-1):
        min_edge=sys.maxsize
        x=y=0
        
        for i in range(V):
            if visited[i]:
                for j in range(V):
                    if not visited[j] and graph[i][j]!=0:
                        if graph[i][j]< min_edge:
                            min_edge= graph[i][j]
                            x,y=i,j
                            
        print(x, "--", y , "=", graph[x][y])
        total += graph[x][y]
        visited[y]=True
        
    print ("total weight:" , total)
    

# main
graph=[
    [0,10,6,5],
    [10,0,0,15],
    [6,0,0,4],
    [5,15,4,0]
]

Prim(graph, 4)
    
    