def warshall_floyd(d):
    r=range(M+1)
    for k in r:
        for i in r:
            for j in r:
                t=d[i][k]+d[k][j]
                if t<d[i][j]:
                    d[i][j]=t
    return d
n,*a=map(int,open(0).read().split())
a,b=a[:n],a[n:]
for x,y in zip(a,b):
    if x==y:continue
    if y>x:
        print(-1)
        exit()
    if x-y<=y:
        print(-1)
        exit()
M=max(a)
d=[]
for k in range(M-1,-1,-1):
    s=set(a)
    e=[[10**18]*(M+1)for _ in range(M+1)]
    for i in range(M+1):e[i][i]=1
    for i in d+list(range(k,0,-1)):
        t=s.copy()
        for x in s:
            e[x][x%i]=1
            t|={x%i}
        s=t
    c=warshall_floyd(e)
    for x,y in zip(a,b):
        if c[x][y]>=10**18:
            d+=k+1,
            break
print(sum(2**k for k in d))