n,m = map(int,input().split())

s = 0
e = n-1

for _ in range(m):
  l,r = map(int,input().split())
  
  s = max(s,l)
  e = min(e,r)
  
print(max(e-s+1,0))