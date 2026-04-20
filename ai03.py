def dfs(a, b):
    if (a, b) in visited:
        return False
    #a=water in jug1 and b = water in jug2
    visited.add((a, b))
    print("Jug1 =", a, "Jug2 =", b)

    # Target condition
    if a == target or b == target:
        print("Target Achieved!")
        return True

    return (
        dfs(jug1, b) or                     # Fill Jug1
        dfs(a, jug2) or                     # Fill Jug2
        dfs(0, b) or                        # Empty Jug1
        dfs(a, 0) or                        # Empty Jug2
        dfs(a - min(a, jug2 - b),           # Pour Jug1 → Jug2
            b + min(a, jug2 - b)) or
        dfs(a + min(b, jug1 - a),           # Pour Jug2 → Jug1
            b - min(b, jug1 - a))
    )


# -------- Variables --------
jug1, jug2 = 4, 3
target = 2
visited = set()

# -------- Start --------
if not dfs(0, 0):
    print("Solution Not Possible")