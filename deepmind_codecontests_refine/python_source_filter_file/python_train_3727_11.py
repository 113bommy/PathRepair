from heapq import heappush,heappop
n,*t=map(int,open(0).read().split())
a=t[:n]
b=t[n:]
B=[]
for i,j in enumerate(b):heappush(B,(-j,i))
c=0
d=0
while B and d<2*10**5:
    d+=1
    y,i=heappop(B)
    x,z=b[(i-1)%n],b[(i+1)%n]
    t=(b[i]-a[i])//(x+z)
    b[i]-=t*(x+z)
    c+=t
    if b[i]>a[i]:
        heappush(B,(-b[i],i))
print([-1,c][a==b])