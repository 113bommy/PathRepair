N,M=map(int,input().split())
p=list(map(int,input().split()))
p=[0]+p

par=[i for i in range(N+1)]
size=[1 for i in range(N+1)]

def find(x):
    if par[x]==x:
        return x
    else:
        return find(par[x])

def union(x,y):
    if size[x]>size[y]:
        size[x]+=size[y]
        par[y]=find(x)
    elif size[y]>size[x]:
        size[y]+=size[x]
        par[x]=find(y)
    elif size[x]==size[y]:
        size[x]+=size[y]
        par[y]=find(x)
        
for i in range(M):
    a,b=map(int,input().split())
    if find(a)==find(b):
        pass
    else:
        union(find(a),find(b))
#print(par)
ans=0
for i in range(1,N+1):
    if find(i)==find(p[i]):
        ans+=1
        #print(i,find(i))
print(ans)

