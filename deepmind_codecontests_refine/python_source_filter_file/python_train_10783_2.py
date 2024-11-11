n,m=map(int,input().split())
k=min(n,m)
n-=min(n,m)
l=0
r=123123123123123
while l<r :
    m=(l+r)//2
    if int((1+m)/2*m)>=n :
        r=m
    else :
        l=m+1


print(l+k)
