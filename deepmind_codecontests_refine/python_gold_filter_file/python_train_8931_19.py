n,k=map(int,input().split())

ans = 0

for i in range(1,n+1):
  p = i
  r = 1
  while p < k:
    p*=2
    r/=2
  ans+=r

ans/=n

print(ans)