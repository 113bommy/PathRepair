from itertools import accumulate
store=0
def check(pref,mid):
  global store
  for i in range(mid,n+1):
    r=(arr[i]*mid)-(pref[i]-pref[i-mid])
    if r<=k:
      store=arr[i]
      return True
  return False
n,k=map(int,input().split())
arr=list(map(int,input().split()))
arr=[0]+sorted(arr)
pref=list(accumulate(arr))
l=1
r=n+1
while l<=r:
  mid=(l+r)//2
  if check(pref,mid):
    ans=mid
    l=mid+1
  else:r=mid-1

print(ans,store)
