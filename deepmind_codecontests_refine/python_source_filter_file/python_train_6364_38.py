

n = int(input())

a = [int(x) for x in input().split()]


min_cost = 10**9
best_t = 10**9
for t in range(0,100):
    cost = 0
    for l in a:
        cost += max(abs(l-t) - 1, 0)
    if cost < min_cost:
        min_cost = cost
        best_t = t
print(best_t, min_cost)
