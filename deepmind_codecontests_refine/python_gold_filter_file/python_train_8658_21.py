a=(input()).split()
n=int(a[0])
l=int(a[1])
r=int(a[2])
minn=0
for i in range(l):
    minn+=2**(l-i-1)
minn+=n-l
maxx=0
for i in range(r):
    maxx+=2**(r-i-1)
if n-r>0:
    maxx+=(n-r)*2**(r-1)
print(minn,maxx)

    
