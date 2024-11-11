import sys
sys.setrecursionlimit(10**6)
n = int(input())
v = 10**5+2
e = [[] for i in range(2*v)]
for i in range(n):
    x,y = map(int,input().split())
    y += v
    e[x].append(y)
    e[y].append(x)
visit = [0]*(2*v)
def dfs(x):
    if not visit[x]:
        visit[x] = 1
        count[x//v] += 1
        for nex in e[x]:
            dfs(nex)
ans = 0
for i in range(v):
    if not visit[i]:
        count = [0]*2
        dfs(i)
        ans += count[0]*count[1]
print(ans-n)
    
