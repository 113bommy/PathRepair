import sys
input = sys.stdin.readline
from collections import deque

n = int(input())

graph = [[] for _ in range(n)]
for i in range(n-1):
    a, b = map(int, input().split())
    a -= 1
    b -= 1
    graph[a].append(b)
    graph[b].append(a)

c = list(map(int, input().split()))
c.sort(reverse=True)

value = 0
ans = [0] * n
memo = [0] * n
q = deque([0])
i = 0

while q:
    v = q.popleft()
    ans[v] = c[i]
    memo[v] = 1
    if i > 0:
        value += c[i]
    i += 1
    for nv in graph[v]:
        if memo[nv] == 1:
            continue
        memo[nv] = 1
        q.append(nv)

print(value)
print(*ans)



