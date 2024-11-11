t,p,q,r=map(int,input().split())
l=[int(i) for i in input().split()]
prex=[0 for i in range(len(l))]
suff=[0 for i in range(len(l))]
prex[0]=l[0]*p
n=len(l)
for i in range(1,n):
    prex[i]=max(l[i]*p,prex[i-1])
suff[n-1]=l[n-1]*r
for i in range(n-2,-1,-1):
    suff[i]=max(l[i]*r,suff[i+1])
maxx=-3*10**8
for i in range(n):
    maxx=max(maxx,prex[i]+q*l[i]+suff[i])
print(maxx)
    
