import sys
sys.setrecursionlimit(1000000)


def input():
    return sys.stdin.readline()


n = int(input())
e = [[] for _ in range(n)]
for _ in range(n - 1):
    a, b, c = [int(i) - 1 for i in input().split()]
    c += 1
    e[a].append([b, c])
    e[b].append([a, c])

c = [0] * n

def dfs(i=0, r=-1, co=0):
    c[i] = co
    for j, k in e[i]:
        if j != r:
            dfs(j, i, (co+k) % 2)


print("\n".join(map(str, c)))
