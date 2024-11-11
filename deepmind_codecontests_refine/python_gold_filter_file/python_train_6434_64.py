n,m = map(int,input().split())
l,r = 1,n
for i in range(m):
  L,R = map(int,input().split())
  l = max(l,L)
  r = min(r,R)
print(max(0,r-l+1))