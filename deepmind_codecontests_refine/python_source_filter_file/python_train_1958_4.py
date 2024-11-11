import sys
input = sys.stdin.buffer.readline
sys.setrecursionlimit(10 ** 7)

N, Q = map(int, input().split())
D = N.bit_length()

edge = [[] for _ in range(N)]
for _ in range(N - 1):
    a, b, c, d = map(int, input().split())
    a -= 1
    b -= 1
    edge[a].append((b, c, d))
    edge[b].append((a, c, d))
query = tuple(tuple(map(int, input().split())) for _ in range(Q))

par = [[-1] * N for _ in range(D)]
dep = [0] * N
dist = [0] * N
node = [0]
while node:
    s = node.pop()
    for t, _, d in edge[s]:
        if par[0][s] == t:
            continue
        par[0][t] = s
        dep[t] = dep[s] + 1
        dist[t] = dist[s] + d
        node.append(t)

for d in range(D - 1):
    for i in range(N):
        par[d + 1][i] = par[d][par[d][i]]


def LCA(x, y):
    if dep[x] < dep[y]:
        x, y = y, x
    h = dep[x] - dep[y]
    for d in reversed(range(D)):
        if h >= 1 << d:
            x = par[d][x]
            h -= 1 << d
    if x == y:
        return x
    for d in reversed(range(D)):
        if par[d][x] != par[d][y]:
            x = par[d][x]
            y = par[d][y]
    return par[0][x]


memo = [[] for _ in range(N)]
ans = [0] * Q

for i, (x, y, u, v) in enumerate(query):
    u -= 1
    v -= 1
    c = LCA(u, v)
    ans[i] = dist[u] + dist[v] - 2 * dist[c]
    memo[u].append((x, y, i))
    memo[v].append((x, y, i))
    memo[c].append((x, y, ~i))


c_len = [0] * (N + 1)
c_cnt = [0] * (N + 1)


def dfs(s, p=-1):
    for c, val, i in memo[s]:
        if i >= 0:
            ans[i] -= c_len[c]
            ans[i] += c_cnt[c] * val
        else:
            ans[~i] += c_len[c]
            ans[~i] -= c_cnt[c] * val
    for t, c, d in edge[s]:
        if t == p:
            continue
        c_len[c] += d
        c_cnt[c] += 1
        dfs(t, s)
        c_len[c] -= d
        c_cnt[c] -= 1


dfs(0)
print(*ans, sep="\n")