n,m=map(int,input().split())
maxl=1
minr=N
while m:
  l,r=map(int,input().split())
  maxl=max(maxl,l)
  minr=min(minr,r)
  m-=1
print(max(0,maxl-minr+1))
