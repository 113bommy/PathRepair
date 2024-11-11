n,m=map(int,input().split())
maxl=1
minr=n
for i in range(m):
  l,r=map(int,input().split())
  maxl=max(maxl,l)
  minr=min(minr,r)

print(max(minr-maxl+1,0))
