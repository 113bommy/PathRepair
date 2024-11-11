n,k=input().split()
n=int(n)
k=int(k)
low=0
high=n-1
while(low>high):
    mid=(low+high)//2
    if(((n-mid)*(n-mid+1)//2 )-mid > k):
        low=mid
    else:
        high=mid
print(high)