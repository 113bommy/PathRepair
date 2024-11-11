(n,m,k)=list(map(int,input().split()))
h=list(map(int,input().split()))
isLunka=[]
j=0
for i in range(0,n+1):
    isLunka.append(0)
for i in range(len(h)):
    isLunka[h[i]]==1
out=0
x=1
for i in range(k):
    (u,v)=list(map(int,input().split()))
    if x==u and isLunka[u]:
        out=u
        break
    if x==v and isLunka[v]:
        out=v
        break
    if x==u:
        x=v
    elif x==v:
        x=u
else:
    out=x
print(out)