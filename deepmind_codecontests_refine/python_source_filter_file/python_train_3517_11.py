import sys
sys.setrecursionlimit(1000000)
n,m,k=map(int,input().split())
stock=[set() for i in range(n)]
ter=[0]*n
ans=[0]*n
for i in range(m):
    a,b=map(int,input().split())
    stock[a-1].append(b-1)
    stock[b-1].append(a-1)
    ans[a-1]-=1
    ans[b-1]-=1
def dfs(j,k):
    size[k]+=1
    for next_j in stock[j]:
        if ter[next_j]==0:
            ter[next_j]=k
            dfs(next_j,k)
total=0
size=[0]*(n+1)
for i in range(n):
    if ter[i]==0:
        total+=1
        ter[i]=total
        dfs(i,total)

for i in range(n):
    ans[i]+=size[ter[i]]-1
for i in range(k):
    c, d = map(int, input().split())
    if ter[c-1]==ter[d-1]:
        ans[c-1]-=1
        ans[d-1]-=1
for i in range(n-1):
    print(ans[i],end=" ")
print(ans[n-1])
