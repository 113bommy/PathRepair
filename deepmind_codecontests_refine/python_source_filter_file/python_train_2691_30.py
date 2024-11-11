n,a,b=map(int,input().split())
h=[int(input()) for _ in range(n)]
def bisearch(k):# k回で倒せるかどうか
  ret=0
  for hi in h:
    ret+=(hi-b*k+a-b-1)//(a-b)
  return ret<=k
l,r=0,pow(10,9)
while r-l>1:
  x=(l+r+1)//2
  if bisearch(x):
    r=x
  else:
    l=x

print(r)