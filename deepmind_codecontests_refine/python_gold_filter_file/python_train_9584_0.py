from collections import defaultdict
import sys
sys.setrecursionlimit(200000)

def dfs(source, used, all_weight, connect):
    max_weight = all_weight
    max_source = source
    used[source] = 1
    for target, weight in connect[source]:
        if not used[target]:
            now_weight = all_weight + weight
            this_source, this_weight = dfs(target, used, now_weight, connect)
            if max_weight < this_weight:
                max_weight = this_weight
                max_source = this_source
    return [max_source, max_weight]

vertice = int(input())
connect = defaultdict(list)
for _ in range(vertice - 1):
    v1, v2, weight = (int(n) for n in input().split(" "))
    connect[v1].append([v2, weight])
    connect[v2].append([v1, weight])
answer = 0
start_v = 0
for i in range(2):
    used = [0 for n in range(vertice)]
    start_v, answer = dfs(start_v, used, 0, connect)
print(answer)