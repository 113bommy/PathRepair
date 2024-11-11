from collections import defaultdict, deque
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
    root_s = get_root(s)
    root_t = get_root(t)
    if not root_s == root_t:
        if rank[s] == rank[t]:
            root[root_t] = root_s
            rank[root_s] += 1
            size[root_s] += size[root_t]
        elif rank[s] > rank[t]:
            root[root_t] = root_s
            size[root_s] += size[root_t]
        else:
            root[root_s] = root_t
            size[root_t] += size[root_s]

def same(s, t):
    if get_root(s) == get_root(t):
        return True
    else:
        return False

def bfs(s):
    q = deque()
    q.append(s)
    anss = []
    while q:
        i = q.popleft()
        for j in G[i]:
            if not visit[j]:
                ans.append((i, j))
                q.append(j)
                visit[j] = 1
    return anss

n, m, d = map(int, input().split())
G = [[] for _ in range(n + 1)]
root = [i for i in range(n + 1)]
rank = [1 for _ in range(n + 1)]
size = [1 for _ in range(n + 1)]
u1 = []
for _ in range(m):
    u, v = map(int, input().split())
    if u ^ 1 and v ^ 1:
        unite(u, v)
        G[u].append(v)
        G[v].append(u)
    else:
        u1.append(u ^ v ^ 1)
s = set()
r = defaultdict(lambda : -1)
for i in G[1]:
    ri = get_root(i)
    s.add(ri)
    r[ri] = i
ans = "YES" if len(s) < d and len(u1) >= d else "NO"
print(ans)
if ans == "YES":
    visit = [0] * (n + 1)
    visit[1] = 1
    st = set()
    for i in r:
        st.add(r[i])
    for i in u1:
        if len(st) == d:
            break
        st.add(i)
    for i in st:
        visit[i] = 1
    ans = []
    for i in st:
        ans.append((1, i))
        for u, v in bfs(i):
            ans.append((u, v))
    for u, v in ans:
        print(u, v)