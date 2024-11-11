(m,t,r)=input().split(sep=None, maxsplit=300)
(m,t,r)=(int(m),int(t),int(r))
x=input().split(sep=None, maxsplit=m)
k=r
out=set([])
u=[int(x[0])+t-1-i for i in range(r)]
out|=set(u)
key=True
for i in range(m):
    if not key:
        break
    v=int(x[i])
    t=v+t-1
    for j in range(r):
        if v<=u[j]:
            continue
        while t in out and t>=v:
            t-=1
        if t<v:
            key=False
            break
        else:
            out|=set([t])
            u[j]=t
            k+=1
            t-=1
if(key):
    print(k)
else:
    print(-1)