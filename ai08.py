def dijkstra(graph, start):
    # Initialize distances
    distances = {}
    visited = {}

    for node in graph:
        distances[node] = float('inf')
        visited[node] = False

    distances[start] = 0

    # Loop for all nodes
    for _ in range(len(graph)):
        # Find unvisited node with minimum distance
        min_node = None
        min_distance = float('inf')

        for node in graph:
            if not visited[node] and distances[node] < min_distance:
                min_distance = distances[node]
                min_node = node

        # Mark as visited
        visited[min_node] = True

        # Update neighbors
        for neighbor, cost in graph[min_node]:
            if distances[min_node] + cost < distances[neighbor]:
                distances[neighbor] = distances[min_node] + cost

    return distances


# Graph (same as before)
graph = {
    'A': [('B', 100), ('C', 300)],
    'B': [('A', 100), ('C', 150), ('D', 200)],
    'C': [('A', 300), ('B', 150), ('D', 100)],
    'D': [('B', 200), ('C', 100)]
}

result = dijkstra(graph, 'A')

print("Minimum cost from A:")
for city in result:
    print(city, "=", result[city])