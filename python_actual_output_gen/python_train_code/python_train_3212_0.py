n=int(input())
a=list(map(int,input().split()))
a.sort()
f =int(input())
def findpos(q):
    if q<a[0]:
        return 0
    if q>=a[-1]:
        return n
    b=0
    e=n-1
    while b<e:
        mid=(b+e)//2
        if a[mid]<=q and a[mid+1]>q:
            return mid+1
        elif a[mid]>q:
            e=mid-1
        else:
            b=mid+1
for i in range(f):
    q=int(input())
    print(findpos(q))