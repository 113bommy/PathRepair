import sys

sys.setrecursionlimit(20000)

def dfs(temp):
    global dist, e, count_from, count, parent

    if count[temp] == count_from[temp]:
        for to in e[temp]:
            count[to] += 1
            temp_dist = dist[temp] + 1
            if temp_dist > dist[to]:
                parent[to] = temp
                dist[to] = temp_dist
            dfs(to)

N, M = map(int, input().split())

count_from = [0] * N
count_to = [0] * N
e = [[] for _ in range(N)]

for i in range(N + M - 1):
    a, b = map(int, input().split())
    e[a - 1].append(b - 1)
    count_from[b - 1] += 1
    count_to[a - 1] += 1

start = 0
for i in range(N):
    if count_from[i] == 0:
        start = i
        break

dist = [0] * N
count = [0] * N
parent = [-1] * N

dfs(start)

for i in range(N):
    print(parent[i] + 1)