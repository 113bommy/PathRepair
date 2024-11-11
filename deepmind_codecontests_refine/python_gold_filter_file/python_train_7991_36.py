import math
n,k=map(int,input().split())
a=list(map(int,input().split()))

left=1
right=10**9
while left<right:
  cnt=0
  mid=(left+right)//2
  for i in range(n):
    cnt+=math.ceil(a[i]/mid)-1
  if cnt<=k:
    right=mid
  else:
    left=mid+1
print(left)