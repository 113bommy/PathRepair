## 1040A
(n, w, b) = (int(_) for _ in input().split(' '))
colors = [int(_) for _ in input().split(' ')]
costs = [w, b]
cost = 0
impossible = False
for i in range(n // 2 + 1):
    if colors[i] != colors[n - i - 1]:
        if colors[i] == 2:
            cost += costs[colors[n - i - 1]]
        elif colors[n - i - 1] == 2:
            cost += costs[colors[i]]
        else:
            impossible = True
    elif colors[i] == 2:
        cost += 2* min(w, b)
        if i == n - i + 1:
            cost -= min(w, b)
if impossible:
    print(-1)
else:
    print(cost)