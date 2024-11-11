import sys
sys.setrecursionlimit(20000)
N=int(input())
g = [[] for i in range(N)]
for i in range(N-1):
    a,b = map(int,input().split())
    g[a-1].append([b-1,i])
    g[b-1].append([a-1,i])

ans=[0 for i in range(N-1)]

def dfs(i,j,col):
    k=1
    for nec in g[i]:
        if nec[0]==j:continue
        if k==col:k+=1
        ans[nec[1]]=k
        dfs(nec[0],i,k)
        k+=1

dfs(0,-1,-1)
print(max(ans))
for i in range(N-1):
    print(ans[i])
