N,K=map(int,input().split())
A=list(map(int,input().split()))
l,r=0,10**9+1
while r-l>1:
    t=(l+r)//2
    k=sum([(a+t-2)//(t-1)-1 for a in A])
    if K<k:
        l=t
    else:
        r=t
print(l)