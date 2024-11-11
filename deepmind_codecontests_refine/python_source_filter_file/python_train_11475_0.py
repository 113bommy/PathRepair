import io, os
input = io.BytesIO(os.read(0,os.fstat(0).st_size)).readline
from collections import defaultdict,deque
def bfs(node):
    vis[node]=1
    q=deque([node])
    order.append(node)
    while q:
        cur=q.popleft()
        for j in edge[cur]:
            if vis[j]==0:
                child[cur].append(j)
                vis[j]=1
                order.append(j)
                q.append(j)
def dfs(node):
    vis[node]=1
    stack=[node]
    while stack:
        cur=stack.pop()
        ans[cur-1]=lis[arr[cur]]
        lis.remove(ans[cur-1])
        for j in edge[cur]:
            if vis[j]==0:
                vis[j]=1
                stack.append(j)
n=int(input())
edge=defaultdict(list)
child=defaultdict(list)
root=-1
arr=[-1]*(n+1)
for i in range(n):
    p,c=list(map(int,input().split()))
    arr[i+1]=c
    if p!=0:
        edge[p].append(i+1)
        edge[i+1].append(p)
    else:
        root=i+1
subTreeSize=[0]*(n+1)
vis=[0]*(n+1)
order=[]
bfs(root)
order.reverse()
for i in range(n):
    for j in child[order[i]]:
        subTreeSize[order[i]]+=subTreeSize[j]
x=0
for i in range(1,n+1):
    if arr[i]>subTreeSize[i]:
        x+=1
        break
if x==1:
    print("NO")
else:
    print("YES")
    lis=[]
    for i in range(n):
        lis.append(i+1)
    vis=[0]*(n+1)
    ans=[-1]*n
    dfs(root)
    print(" ".join(str(x) for x in ans))