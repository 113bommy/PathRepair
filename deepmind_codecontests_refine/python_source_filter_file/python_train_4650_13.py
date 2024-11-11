from bisect import *
n,k,k1=map(int,input().split())
l=list(map(int,input().split()))
arr=[abs(int(i)-k) for i,k in zip(input().split(),l)]
arr.sort()
k=k+k1
while(k>0):
    x=arr[-1]
    del arr[-1]
    insort(arr,x-1)
    k-=1
ans=0
for i in arr:
    ans+=i*i
print(ans)