n,m,k=map(int,input().split())
c=[(0,0)]*(m+1)
r=[(0,0)]*(n+1)
for i in range(k):
    q,a,b=map(int,input().split())
    if q==1: r[a]=(i+1,b)
    else: c[a]=(i+1,b)
for i in range(n):
    s=""
    for j in range(m):
        t=r[i+1][1]
        if c[j+1][0]>r[i+1][0]: t=c[j+1][1]
        s+=str(t)
    print(s)