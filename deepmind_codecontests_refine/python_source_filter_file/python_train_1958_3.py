import sys
input = sys.stdin.readline
sys.setrecursionlimit(10**7)

N, Q = map(int, input().split())
graph = [[] for _ in range(N+1)]
for _ in range(N-1):
    a, b, c, d = map(int, input().split())
    graph[a].append((b, c, d))
    graph[b].append((a, c, d))
query = [[int(x) for x in input().split()] for _ in range(Q)]

depth = [0] * (N+1)
U = 17
ancestor = [[0] * (U+1) for _ in range(N+1)]

q = [(1, 0, 0)]
while q:
    qq = []
    for x, d, parent in q:
        depth[x] = d
        ax = ancestor[x]
        ax[0] = parent
        for i in range(d.bit_length()-1):
            ax[i+1] = ancestor[ax[i]][i]
        for y, _, _ in graph[x]:
            if y == parent:
                continue
            qq.append((y, d+1, x))
    q = qq

def LCA(x, y):
    dx = depth[x]
    dy = depth[y]
    if dx > dy:
        x, y = y, x
        dx, dy = dy, dx
    diff = dy - dx
    while diff:
        step = diff & (-diff)
        y = ancestor[y][step.bit_length()-1]
        diff -= step
    while x != y:
        j = 0
        while ancestor[x][j] != ancestor[y][j]:
            j += 1
        if j == 0:
            return ancestor[x][0]
        x = ancestor[x][j-1]
        y = ancestor[y][j-1]
    return x

tasks = [[] for _ in range(N+1)]
for i, (x, y, u, v) in enumerate(query):
    tasks[u].append((i, x, y, 1))
    tasks[v].append((i, x, y, 1))
    tasks[LCA(u, v)].append((i, x, y, -2))

answer = [0] * Q

def dfs(x = 1, sums = [0] * (N+1), nums = [0] * (N+1), total = 0, parent = 0):
    for i, c, d, coef in tasks[x]:
        answer[i] += coef * (total - sums[c] + nums[c] * d)
    for y, c, d in graph[x]:
        if y == parent:
            continue
        sums[c] += d
        nums[c] += 1
        total += d
        dfs(y, sums, nums, total, x)
        sums[c] -= d
        nums[c] -= d
        total -= d
    return

dfs()

print('\n'.join(map(str, answer)))
