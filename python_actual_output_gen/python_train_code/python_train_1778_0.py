n,k=map(int,input().split())
a=list(map(int,input().split()))
def binarysearch(mid,s,k):
    c=0
    for i in range(n):
        if s or a[i]<=mid:
            c+=1
            s^=1
    if c>=k: return True
    return False
l=1
h=10**9
while l<h:
    mid=(l+h)//2
    if binarysearch(mid,0,k) or binarysearch(mid,1,k):
        h=mid
    else:
        l=mid+1
print(1)