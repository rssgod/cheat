
import time
import random
import os
import pyperclip


class RouteNode:
    '''Represents a specific route between two cities in the BST.'''

    def __init__(self, start_city, end_city, distance, travel_time, cost):
        self.start_city = start_city
        self.end_city = end_city
        self.distance = distance
        self.travel_time = travel_time
        self.cost = cost

        # BST pointers
        self.left = None
        self.right = None

    def get_metric(self, criterion):
        '''Returns the value associated with the current sorting priority.'''
        metrics = {
            "distance": self.distance,
            "time": self.travel_time,
            "cost": self.cost
        }
        return metrics.get(criterion, self.distance)

    def __str__(self):
        return (
            f"[{self.start_city} -> {self.end_city}] "
            f"Dist: {self.distance}km, "
            f"Time: {self.travel_time}min, "
            f"Cost: ${self.cost}"
        )


class RouteBST:
    '''Manages routes using a Binary Search Tree structure.'''

    def __init__(self, criterion="distance"):
        self.root = None
        self.criterion = criterion

    def insert(self, route):
        '''Inserts a route into the BST based on the active criterion.'''
        if not self.root:
            self.root = route
        else:
            self._insert_recursive(self.root, route)

    def _insert_recursive(self, current, new_route):
        new_val = new_route.get_metric(self.criterion)
        curr_val = current.get_metric(self.criterion)

        if new_val < curr_val:
            if current.left is None:
                current.left = new_route
            else:
                self._insert_recursive(current.left, new_route)
        else:
            if current.right is None:
                current.right = new_route
            else:
                self._insert_recursive(current.right, new_route)

    def find_min(self):
        '''Finding the best route by going as far left as possible.'''
        if not self.root:
            return None

        current = self.root
        while current.left:
            current = current.left
        return current

    def get_all_sorted(self, node, result):
        '''In-order traversal to get all routes from best to worst.'''
        if node:
            self.get_all_sorted(node.left, result)
            result.append(node)
            self.get_all_sorted(node.right, result)


class LogisticsSimulator:
    '''Real-life simulator for route management.'''

    def __init__(self):
        self.criterion = "distance"
        self.bst = RouteBST(self.criterion)
        self.all_routes_raw = []
        self._seed_data()

    def _seed_data(self):
        '''Pre-populate the system with some real-world routes.'''
        seeds = [
            ("New York", "Boston", 350, 240, 45),
            ("New York", "DC", 360, 260, 55),
            ("LA", "San Francisco", 610, 380, 80),
            ("Chicago", "Detroit", 450, 280, 35),
            ("Austin", "Houston", 260, 160, 25),
            ("Seattle", "Portland", 280, 180, 30)
        ]

        for s in seeds:
            route = RouteNode(*s)
            self.all_routes_raw.append(route)

        self.rebuild_bst()

    def rebuild_bst(self):
        '''Re-sorts the entire tree when the user changes optimization priority.'''
        self.bst = RouteBST(self.criterion)
        temp_list = list(self.all_routes_raw)
        random.shuffle(temp_list)

        for r in temp_list:
            r.left = None
            r.right = None
            self.bst.insert(r)

    def clear_screen(self):
        os.system('cls' if os.name == 'nt' else 'clear')

    def display_menu(self):
        self.clear_screen()
        print("==============================================")
        print(" LOGISTICS ROUTE BST SIMULATOR (v1.0)")
        print(f" Optimization Priority: {self.criterion.upper()}")
        print("==============================================")
        print("1. View 'Best' Route (BST Search)")
        print("2. List All Routes (In-order Traversal)")
        print("3. Change Optimization Criterion")
        print("4. Add New Route to System")
        print("5. Simulate Traffic/Price Surge (Update)")
        print("6. Exit")
        print("----------------------------------------------")

    def run(self):
        while True:
            self.display_menu()
            choice = input("Select an option: ")

            if choice == '1':
                best = self.bst.find_min()
                if best:
                    print("[OPTIMAL ROUTE FOUND]")
                    print(best)

                    # 🔥 Automatically copy best route to clipboard
                    pyperclip.copy(str(best))
                    print("✔ Route copied to clipboard!")

                else:
                    print("[!] No routes in system.")
                input("Press Enter to return...")

            elif choice == '2':
                routes = []
                self.bst.get_all_sorted(self.bst.root, routes)

                print(f"[ALL ROUTES - SORTED BY {self.criterion.upper()}]")
                for i, r in enumerate(routes, 1):
                    print(f"{i}. {r}")

                input("Press Enter to return...")

            elif choice == '3':
                print("Set Priority: 1. Distance | 2. Time | 3. Cost")
                c_choice = input("Choice: ")
                mapping = {"1": "distance", "2": "time", "3": "cost"}

                self.criterion = mapping.get(c_choice, "distance")
                print(f"Rebuilding BST optimized for {self.criterion}...")
                self.rebuild_bst()
                time.sleep(1)

            elif choice == '4':
                print("--- Register New Route ---")
                try:
                    start = input("From City: ")
                    end = input("To City: ")
                    d = float(input("Distance (km): "))
                    t = float(input("Time (min): "))
                    c = float(input("Cost ($): "))

                    new_route = RouteNode(start, end, d, t, c)
                    self.all_routes_raw.append(new_route)
                    self.bst.insert(new_route)

                    print("Route added and indexed successfully!")

                except ValueError:
                    print("Invalid input. Please enter numbers for metrics.")

                time.sleep(1)

            elif choice == '5':
                print("[!] Simulating unexpected traffic and fuel spikes...")

                for r in self.all_routes_raw:
                    r.travel_time = round(r.travel_time * random.uniform(0.9, 1.3), 1)
                    r.cost = round(r.cost * random.uniform(0.9, 1.4), 2)

                self.rebuild_bst()
                print("System updated. All routes re-indexed in BST.")
                time.sleep(1.5)

            elif choice == '6':
                print("Shutting down logistics engine...")
                break


if __name__ == "__main__":
    sim = LogisticsSimulator()
    sim.run()
