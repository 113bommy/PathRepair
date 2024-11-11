n,l,r=map(int,input().split())
t=[]
m=[]
k=0
for j in range(0,n):
    if(j+1<=n-l+1):
        m.append(1)
    else:   
        k=k+1
        m.append(2*k)
for i in range(0,n):
    if(i+1<=r):
        t.append(2**i)
    else:   t.append(2**(r-1))
print("%d %d"%(sum(m),sum(t)))
