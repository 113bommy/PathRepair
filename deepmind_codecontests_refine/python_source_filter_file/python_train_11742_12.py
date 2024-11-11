from collections import deque


def dfs(start, goal, tree):
    """startからgoalまでの木上のpathを出力する"""
    q = deque([start])
    visited = {}
    visited[start] = -1
    while True:
        pos = q.pop()
        if pos == goal:
            break
        for child in tree[pos]:
            if child in visited:
                continue
            visited[child] = pos
            q.append(child)
    res = []
    pos = goal
    while True:
        par = visited[pos]
        if par == -1:
            break
        res.append((min(par, pos), max(par, pos)))
        pos = par
    return res


n = int(input())
info = [list(map(int, input().split())) for i in range(n - 1)]
m = int(input())
path = [list(map(int, input().split())) for i in range(m)]

tree = [[] for i in range(n)]
memo = {}
for i in range(n - 1):
    a, b = info[i]
    a -= 1
    b -= 1
    tree[a].append(b)
    tree[b].append(a)
    memo[(min(a, b), max(a, b))] = i
  

li_path = [0] * m
for i in range(m):
    s, g = path[i]
    s -= 1
    g -= 1
    res = dfs(s, g)
    tmp = 0
    for j in res:
        tmp += (1 << memo[j])
    li_path[i] = tmp
  
ans = 0
for bit_state in range(1 << m):
    mask = 0
    cnt = 0
    for i in range(m):
        if bit_state & (1 << i):
            cnt += 1
            mask |= li_path[i]
    num_n = bin(mask).count("1")
    if cnt % 2 == 0:
        ans += 2 ** (n - 1 - num_n)
    else:
        ans -= 2 ** (n - 1 - num_n)
print(ans)
