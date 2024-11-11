n,m = input().split()
n,m = int(n),int(m)
a = list(map(int, input().split()))
l,r = 0,m-1
def isOptimal(mid):
    prev = 0
    check=True
    for i in range(1,n):
            if prev<a[i]:
                if m-a[i]+prev>mid:
                    prev=a[i]
            else:
                if prev-a[i]>mid:
                    check=False
    return check
while l<=r:
    check=True
    mid=(l+r)//2
    prev=a[0]
    if isOptimal(mid):
        r=mid-1
    else:
        l=mid+1

check = isOptimal(l)
print(l*check+r*(not check))
