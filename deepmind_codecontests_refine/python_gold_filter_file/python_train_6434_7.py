n,m=map(int,input().split())
l=1
r=n
for i in range(m):
  li,ri=map(int,input().split())
  l = max(l,li)
  r = min(r,ri)
print(max(r-l+1,0))