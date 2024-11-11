from collections import defaultdict
from collections import deque
import heapq
import sys
input = sys.stdin.readline

def get_root(s):
    v = []
    while not s == root[s]:
        v.append(s)
        s = root[s]
    for i in v:
        root[i] = s
    return s

def unite(s, t):
    rs, rt = get_root(s), get_root(t)
    if not rs ^ rt:
        return
    if rank[s] == rank[t]:
        rank[rs] += 1
    if rank[s] >= rank[t]:
        root[rt] = rs
        size[rs] += size[rt]
    else:
        root[rs] = rt
        size[rt] += size[rs]
    return

def same(s, t):
    return True if get_root(s) == get_root(t) else False

def bfs(r):
    q = deque()
    q.append(r)
    dist1[r] = 0
    m0, u = 0, r
    while q:
        i = q.popleft()
        di = dist1[i]
        if m0 < di:
            m0 = di
            u = i
        for j in G[i]:
            if dist1[j] == -1:
                dist1[j] = di + 1
                q.append(j)
    q.append(u)
    dist2[u] = 0
    m0, v = 0, u
    while q:
        i = q.popleft()
        di = dist2[i]
        if m0 < di:
            m0 = di
            v = i
        for j in G[i]:
            if dist2[j] == -1:
                dist2[j] = di + 1
                q.append(j)
    q.append(v)
    dist3[v] = 0
    while q:
        i = q.popleft()
        di = dist3[i]
        for j in G[i]:
            if dist3[j] == -1:
                dist3[j] = di + 1
                q.append(j)
    c = r
    ma = m0
    for i in x[r]:
        m1 = max(dist2[i], dist3[i])
        if m1 < ma:
            ma, c = m1, i
    return ma, m0, c

n, m = map(int, input().split())
G = [[] for _ in range(n + 1)]
root = [i for i in range(n + 1)]
rank = [1 for _ in range(n + 1)]
size = [1 for _ in range(n + 1)]
for _ in range(m):
    u, v = map(int, input().split())
    unite(u, v)
    G[u].append(v)
    G[v].append(u)
x = defaultdict(lambda : [])
s = set()
for i in range(1, n + 1):
    r = get_root(i)
    x[r].append(i)
    s.add(r)
dist1 = [-1] * (n + 1)
dist2 = [-1] * (n + 1)
dist3 = [-1] * (n + 1)
h = []
l = 0
for i in s:
    ma, m0, c = bfs(i)
    l = max(l, m0)
    heapq.heappush(h, (-ma, c))
s, t = [], []
while h:
    m0, c = heapq.heappop(h)
    s.append(-m0)
    t.append(c)
ans = l
for i in range(len(s)):
    si = s[i]
    for j in range(i + 1, len(s)):
        sj = s[j]
        ans = max(ans, si + sj + min(i, 1) + 1)
print(ans)
u = t[0]
for i in range(1, len(t)):
    v = t[i]
    print(u, v)