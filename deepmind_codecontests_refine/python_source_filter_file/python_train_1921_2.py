from collections import deque ,defaultdict

cnt = 0
def dfs(node):
    global cnt
    visited[node] =True
    cnt +=1
    for i in g[node]:
        if not visited[i]:
            dfs(i)

n , m = map(int,input().split())
if m == 0 :
    print(1)
    exit(0)

g = defaultdict(list)
for i in range(m):
    u,v = map(int,input().split())
    g[u].append(v)
    g[v].append(u)

visited = [False] * (n+1)

res = 0
for i in range(1 , n + 1):
    cnt = 0
    dfs(i)
    cnt -=1
    if cnt > 0 :
        res += pow(2 , cnt)
print(res)
