import math
def fun(mid,k,n):
    check=0
    while mid:
        check+=mid
        mid=mid//k
    if check>=n:
        return True
    else:
        return False
        
n,k=map(int,input().split())
ans=0
c=0
while ans<n:
    ans+=math.pow(k,c)
    c+=1
c-=1
l=math.pow(k,c-1)
r=math.pow(k,c)
mid= l+(r-l)//2
while l<r:
    if fun(mid,k,n):
        r=mid
    else:
        l=mid+1
    mid= l+(r-l)//2
print(int(mid))