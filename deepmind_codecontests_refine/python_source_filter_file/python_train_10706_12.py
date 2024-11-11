n=int(input())
pt=[[] for i in range(n)]
for i in range(n-1):
    a,b=map(int,input().split())
    pt[a-1].append(b-1)
    pt[b-1].append(a-1)

def dfs(v):
    d=[-1]*n
    d[v]=0
    q=[v]
    c=1
    while q:
        q1=[]
        for i in q:
            for j in pt[i]:
                if d[j]==-1:
                    d[j]=c
                    q1.append(j)
        q=q1
        c+=1
    return d

ans=0
for i,j in zip(dfs(0),dfs(n-1)):
    if i<=j:ans+=1
if ans<n/2:print('Snuke')
else:print('Fennec')