from sys import setrecursionlimit

setrecursionlimit(10**10)

def dfs(v):
    flag = True

    for nxt in edge[v]:
        if l[v] == l[nxt]:
            return False
        elif l[v] + l[nxt] == 1:
            continue
        else:
            l[nxt] = 1 - l[v]
            cnt[1-l[v]] += 1
            flag &= dfs(nxt)
    
    return flag
        

n, m = map(int, input().split())
edge = [[] for _ in range(n)]
for _ in range(m):
    a, b = map(int, input().split())
    edge[a-1].append(b-1)
    edge[b-1].append(a-1)

l = [-1] * n
l[0] = 0
cnt = [1, 0]

if dfs(0):
    print(cnt[0] * cnt[1] - m)
else:
    print(n * (n - 1) // 2 - m)