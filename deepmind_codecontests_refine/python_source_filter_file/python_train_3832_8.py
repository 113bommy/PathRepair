import sys
sys.setrecursionlimit(10000000)
n=int(input())
s=[[]for i in range(n+1)]
g=[0]*(n+1)
h=[True]*(n+1)
for i in range(n-1):
    a,b,c=map(int,input().split())
    s[a].append([b,c])
    s[b].append([a,c])
def dfs(x):
    h[x]=False
    for i in s[x]:
        if h[i[0]]:
            g[i[0]]=g[x]+i[1]
            dfs(i[0])
dfs(1)
print(g)
for i in range(1,n+1):
    if g[i]%2==0:
        print(0)
    else:
        print(1)