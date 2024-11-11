from sys import stdin,stdout
nmbr = lambda: int(stdin.readline())
lst = lambda: list(map(int,stdin.readline().split()))
for _ in range(1):#nmbr()):
    n=nmbr()
    a=lst()
    suf=[0]*n
    suf[n-1]=a[n-1]
    for i in range(n-2,-1,-1):
        suf[i]=min(a[i],suf[i+1])
    for i in range(n):
        l,r=i+1,n-1
        while l<=r:
            mid=(l+r)>>1
            if a[mid]<a[i]:l=mid+1
            else:r=mid-1
        stdout.write(str(r-i-1)+' ')