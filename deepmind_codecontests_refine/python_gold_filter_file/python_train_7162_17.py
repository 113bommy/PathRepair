import sys
sys.setrecursionlimit(10**5)
m = 100005
visited = [False]*(m*2)
cnt = [0,0]
def dfs(i):
    visited[i] = True
    cnt[i//m] = cnt[i//m]+1
    for j in to[i]:
        if not visited[j]:
            dfs(j)
 
input = sys.stdin.readline
n = int(input())
to = [[] for _ in range(m*2)]
for _ in range(n):
    x,y = map(int,input().split())
    y = y+m
    to[x].append(y)
    to[y].append(x)
 
ans = 0
for i in range(m):
    if not visited[i]:
        cnt = [0,0]
        dfs(i)
        ans = ans + cnt[0]*cnt[1]
 
print(ans-n)