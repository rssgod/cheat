
class UnionFind:
    '''
    Disjoint Set Union (DSU) data structure with Path Compression
    and Union by Rank for efficient cycle detection.
    '''

    def __init__(self, n):
        self.parent = list(range(n))
        self.rank = [0] * n

    def find(self, i):
        '''Finds the representative of the set containing i (with path compression).'''
        if self.parent[i] == i:
            return i
        self.parent[i] = self.find(self.parent[i])
        return self.parent[i]

    def union(self, i, j):
        '''Unites sets containing i and j (using union by rank).'''
        root_i = self.find(i)
        root_j = self.find(j)

        if root_i != root_j:
            if self.rank[root_i] < self.rank[root_j]:
                self.parent[root_i] = root_j
            elif self.rank[root_i] > self.rank[root_j]:
                self.parent[root_j] = root_i
            else:
                self.parent[root_i] = root_j
                self.rank[root_j] += 1
            return True

        return False


def kruskal_mst(num_vertices, edges):
    '''
    Computes the MST using Kruskal's algorithm.

    Args:
        num_vertices (int): Number of vertices in the graph.
        edges (list): List of tuples (u, v, weight).

    Returns:
        tuple: (List of MST edges, Total weight of MST)
    '''

    # 1. Sort edges by weight
    sorted_edges = sorted(edges, key=lambda item: item[2])

    ds = UnionFind(num_vertices)
    mst_edges = []
    mst_weight = 0

    for u, v, weight in sorted_edges:
        # 2. Check if including this edge creates a cycle
        if ds.union(u, v):
            mst_edges.append((u, v, weight))
            mst_weight += weight

            # Optimization: Stop if we have V-1 edges
            if len(mst_edges) == num_vertices - 1:
                break

    return mst_edges, mst_weight


def main():
    '''
    Example Graph:
        0 --(10)-- 1
        0 --(6)--- 2
        0 --(5)--- 3
        1 --(15)-- 3
        2 --(4)--- 3
    '''

    num_vertices = 4

    # (u, v, weight)
    graph_edges = [
        (0, 1, 10),
        (0, 2, 6),
        (0, 3, 5),
        (1, 3, 15),
        (2, 3, 4)
    ]

    print(f"Calculating MST for a graph with {num_vertices} vertices...")

    mst, total_weight = kruskal_mst(num_vertices, graph_edges)

    print("
Edges in the Minimum Spanning Tree:")
    print("-" * 35)
    print(f"{'Source':<10} | {'Dest':<10} | {'Weight':<10}")
    print("-" * 35)

    for u, v, w in mst:
        print(f"{u:<10} | {v:<10} | {w:<10}")

    print("-" * 35)
    print(f"Total MST Weight: {total_weight}")


if __name__ == "__main__":
    main()
