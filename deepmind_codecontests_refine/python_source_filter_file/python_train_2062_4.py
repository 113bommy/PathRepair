import sys

sys.setrecursionlimit(10**5)

n, m = list(map(int, input().split()))

counter = 0
c = [-1 for i in range(n)]
p = [[] for n in range(n)]

for i in range(m):
    x, y, z = list(map(int, input().split()))
    x -= 1
    y -= 1
    p[x].append(y)
    p[y].append(x)

def dfs(num, depth):
    if c[num] != -1:
        return
    else:
        c[num] = depth
    for i in p[num]:
        dfs(i, depth)

for i in range(n):
    if c[i] == -1:
        counter += 1
        dfs(i, counter)

print(max(c))