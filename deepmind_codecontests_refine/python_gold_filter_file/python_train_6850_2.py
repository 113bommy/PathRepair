from collections import deque
n, m = map(int, input().split())
edges = [[] for _ in range(n)]
for _ in range(m):
    u, v = map(int, input().split())
    u -= 1
    v -= 1
    edges[u].append(v)

s, t = map(int, input().split())
s -= 1
t -= 1
#dfs
from_s = [[-1]*3 for _ in range(n)]
d_s = deque()
d_s.append((s, 0))
from_s[s][0] = 0
while d_s:
    p, count = d_s.popleft()
    next_count = (count + 1) % 3
    for c in edges[p]:
        if from_s[c][next_count] != -1:
            continue
        from_s[c][next_count] = from_s[p][count] + 1
        d_s.append((c, next_count))
if from_s[t] == -1:
    print(-1)
else:
    print(from_s[t][0]//3)
