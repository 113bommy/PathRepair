n,m=map(int,input().split())
ll=list(map(int,input().split()))
ll.sort()
f=0
l=n//2+1
while l-f>1:
    mid=(f+l)//2
    flag=True
    for i in range(mid):
        fla=flag&(ll[n-mid+i]-ll[i]>=m)
    if fla:
        f=mid
    else:
        l=mid
print(f)