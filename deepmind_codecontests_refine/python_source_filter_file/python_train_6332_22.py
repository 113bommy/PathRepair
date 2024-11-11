import sys
sys.setrecursionlimit(10*6)

def m():
    n, m = map(int, input().split())
    p = list(map(int, input().split()))
    g = [[] for _ in range(n+1)]
    for _ in range(m):
        x, y = map(int, input().split())
        g[x].append(y)
        g[y].append(x)
    color = [-1] * (n+1)

    def dfs(v, c):
        s = []
        s.append(v)
        color[v] = c
        while len(s) != 0:
            a = s.pop()
            for elem in g[a]:
                if color[elem] == -1:
                    dfs(elem, c)

    k = 0
    for i in range(1, n):
        if color[i] == -1:
            dfs(i,k)
            k +=1
    ans = 0
    for i in range(n):
        if color[p[i]] == color[i+1]:
            ans +=1
    return ans

print(m())