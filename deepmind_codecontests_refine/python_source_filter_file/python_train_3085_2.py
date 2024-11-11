n, m = map(int, input().split())
costs = [int(x) for x in input().split()]

disjointSet = [-1 for x in costs]

def root(x):
    if disjointSet[x] > 0:
        disjointSet[x] = root(disjointSet[x])
        return disjointSet[x]
    return x

for _ in range(m):
    a, b = map(int, input().split())
    a -= 1
    b -= 1
    r1, r2 = root(a), root(b)
    if r1 != r2:
        disjointSet[r2] = r1
        costs[r1] = min(costs[r1], costs[r2])
        costs[r2] = 0
print(sum(costs))