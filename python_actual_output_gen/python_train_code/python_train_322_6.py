loop, magic_cost = map(int, input().split(" "))
cost = [n for n in map(int, input().split(" "))]
answer = float("inf")
min_costs = [float(inf) for n in range(loop)]
for i in range(loop):
    for j in range(loop):
        min_costs[j] = min(min_costs[j], cost[(i - j) % loop])
    answer = min(answer, sum(min_costs) + (magic_cost * (i) ) )
print(answer)