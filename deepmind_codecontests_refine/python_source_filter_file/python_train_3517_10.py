n,m,k=map(int,input().split())
w=[i for i in range(n+1)]
s=[1]*(n+1)
g=[list(map(int,input().split()))for i in range(m)]
def root(x):
    if w[x]==x:
        return x
    x=w[x]
    return root(w[x])
def unite(x,y):
    x=root(x)
    y=root(y)
    if x!=y:
        if s[x]<s[y]:
            w[x]=y
            s[y]+=1
        else:
            w[y]=x
            s[x]+=1
for i in range(m):
    a,b=g[i][0],g[i][1]
    unite(a,b)
for i in range(1,n+1):
    w[i]=root(i)
    s[i]=s[w[i]]
for i in range(m):
    s[g[i][0]]-=1
    s[g[i][1]]-=1
for i in range(k):
    a,b=map(int,input().split())
    if w[a]==w[b]:
        s[a]-=1
        s[b]-=1
for i in range(1,n+1):s[i]-=1
print(*s[1:])
