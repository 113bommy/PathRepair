n,l,r=map(int,input().split())
maxx=0
if l<n: 
    minn=n-l+1
    for i in range (l-1):
        minn+= 2**(i+1)
else:
    minn=n
maxx=0
if (r<n):
    for i in range (r-1):
        maxx+= 2**(i)
    for i in range (n-r):
        maxx+= 2**(i+1)
else:
    for i in range (r):
        maxx+=2**i
print(minn,maxx)
