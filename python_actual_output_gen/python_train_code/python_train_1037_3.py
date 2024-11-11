n,s=map(int,input().split())
r=10**18
l=1
def f(m):
  res=0
  while m>0:
    res+=m%10
    m//=10
  return res
while r-l>1:
  mid=(r+l)//2
  if mid-f(mid)>=s:
    r=mid
  else:
    l=mid
print(max(n-r+1,0))