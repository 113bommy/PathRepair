import sys
sys.setrecursionlimit(1000000)
def input():
    return sys.stdin.readline()
n = int(input())
e = [[] for _ in range(n)]
for _ in range(n - 1):
    a, b = [int(i) - 1 for i in input().split()]
    e[a].append(b)
    e[b].append(a)

mod = 10**9+7

def dfs(i=0, r=-1):
    b = w = 1
    for j in e[i]:
        if j == r:
            continue
        bb, ww = dfs(j, i)
        b = b * ww % mod
        w = w * (bb + ww) % mod
    return b, w

print(sum(dfs())%mod)
