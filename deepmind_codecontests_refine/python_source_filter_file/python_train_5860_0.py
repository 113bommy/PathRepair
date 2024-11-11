n,x,pos=map(int,input().split())
smaller=0
larger=0
for i in range(1,n+1):
    if i>x:
        larger+=1
    elif i<x:
        smaller+=1

l=0
r=n
ans=1
while(l<r):
    mid=(l+r)//2
    if mid<pos:
        ans=ans*smaller
        smaller-=1
        l=mid+1
    elif mid==pos:
        ans=ans*1
        break
    else:
        r=mid
        ans=ans*larger
        larger-=1
smaller+=larger
if smaller>0:
    for i in range(smaller,0,-1):
        ans*=i
print(ans%(10**(9)+7))
    