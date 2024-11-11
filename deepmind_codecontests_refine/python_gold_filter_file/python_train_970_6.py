def find(a):
    if parent[a]!=a:
        parent[a]=find(parent[a])
    return parent[a]

def union(a,b):
    u,v=find(a),find(b)
    if u==v:
        return
    if rank[u]>rank[v]:
        parent[v]=u
    else:
        parent[u]=v
    if rank[u]==rank[v]:
        rank[v]+=1

n=int(input())
k=int(input())

parent=list(map(int,range(n+1)))
rank=[0]*(n+1)
ans=[0]*(n+1)
count=[0]*(n+1)

for i in range(k):
        u,v=map(int,input().split())
        union(u,v)

for i in range(len(ans)):
    ans[find(i)]+=1

for i in range(len(parent)):
    count[parent[i]]+=1

d={}

m=int(input())
for i in range(m):
    u,v=map(int,input().split())
    if parent[u]==parent[v]:
        d[parent[u]]=False

sak=0
for i in range(len(count)):
    if count[i]!=0 and i not in d and i!=0:
        sak=max(sak,count[i])
print(sak)