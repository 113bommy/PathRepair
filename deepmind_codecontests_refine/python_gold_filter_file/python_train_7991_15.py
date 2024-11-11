n,k=map(int,input().split())
A = list(map(int, input().split()))
r = max(A)
l = 0
while l+1<r:
  mid=(l+r)//2
  if sum([(a-1)//mid for a in A])>k:
    l=mid
  else:
    r = mid
print(r)