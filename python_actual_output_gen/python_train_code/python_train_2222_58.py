n,m = map(int,input().split())
l,r = 1,N
for i in range(m):
  L,R = map(int,input().split())
  L = max(l,L)
  R = min(r,R)
print(max(0,L-R+1))