class RouteNode:
    def __init__(self, s, e, d, t, c):
        self.start = s
        self.end = e
        self.distance = d
        self.time = t
        self.cost = c
        self.left = None
        self.right = None


class RouteBST:
    def __init__(self, criterion="distance"):
        self.root = None
        self.criterion = criterion

    # Get value based on criterion
    def get_value(self, node):
        if self.criterion == "distance":
            return node.distance
        elif self.criterion == "time":
            return node.time
        else:
            return node.cost

    # Insert node
    def insert(self, root, node):
        if root is None:
            return node

        if self.get_value(node) < self.get_value(root):
            root.left = self.insert(root.left, node)
        else:
            root.right = self.insert(root.right, node)

        return root

    # Find best route (minimum)
    def find_best(self):
        curr = self.root
        while curr.left:
            curr = curr.left
        return curr

    # Display sorted routes
    def inorder(self, root):
        if root:
            self.inorder(root.left)
            print(root.start, "->", root.end,
                  "| D:", root.distance,
                  "| T:", root.time,
                  "| C:", root.cost)
            self.inorder(root.right)


# -------- MAIN --------
bst = RouteBST("distance")   # can change to "time" or "cost"

data = [
    ("A", "B", 100, 60, 20),
    ("A", "C", 50, 30, 10),
    ("B", "C", 150, 90, 25)
]

for r in data:
    bst.root = bst.insert(bst.root, RouteNode(*r))

print("All Routes:")
bst.inorder(bst.root)

best = bst.find_best()
print("\nBest Route:", best.start, "->", best.end)