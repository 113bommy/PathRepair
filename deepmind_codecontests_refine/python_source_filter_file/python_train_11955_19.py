import heapq
from collections import deque

n, m = map(int, input().split())
a = list(map(int, input().split()))

info = [list(map(int, input().split())) for i in range(m)]
tree = [[] for i in range(n)]

for b, c in info:
    tree[b].append(c)
    tree[c].append(b)

visited = [False] * n
group = []
for i in range(n):
    if visited[i]:
        continue
    q = deque([i])
    visited[i] = True
    tmp = [a[i]]
    while q:
        pos = q.pop()
        for next_pos in tree[pos]:
            if visited[next_pos]:
                continue
            visited[next_pos] = True
            q.append(next_pos)
            tmp.append(a[next_pos])
    group.append(tmp)

for i in range(len(group)):
    group[i] = sorted(group[i])
    
ans = 0
cnt = len(group)*2 - 2

if cnt == 0:
    print(0)
    exit()
    
for i in range(len(group)):
    ans += group[i][0]
    cnt -= 1
    group[i][0] = 10**9 + 7

q = []
for i in range(len(group)):
    for num in group[i]:
        if num != 10**9 +7:
            heapq.heappush(q, num)

for i in range(cnt):
    if not q:
        print("Impossible")
        exit()
    ans += heapq.heappush(q)
print(ans)
    