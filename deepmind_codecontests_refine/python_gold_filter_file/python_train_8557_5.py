n,k=map(int,input().split())
def c(m):
  a=b=m
  ans=0
  if m%2==0:b+=1
  while b<=n:
    ans+=b-a+1
    a*=2
    b*=2
    b+=1
  return ans+max(0,n-a+1)

if n<100:
  ans=1
  for i in range(1,n+1):
    if c(i)>=k:ans=i
  print(ans);exit()
for i in range(n,n-100,-1):
  if c(i)>=k:print(i);exit()

ng=0
ok=(n+1)//2*2
while ng+2!=ok:
  mid=(ok+ng)//4*2
  if c(mid)<k:ok=mid
  else:ng=mid
x=ng
ng=-1
ok=(n+1)//2*2-1
while ng+2!=ok:
  mid=(ok+ng)//4*2+1
  if c(mid)<k:ok=mid
  else:ng=mid
print(max(ng,x))