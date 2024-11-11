n,m=map(int,input().split())
maxl=1
minr=n
while m:
  l,r=map(int,input().split())
  maxl=max(maxl,l)
  minr=min(minr,r)
  m-=1
print(max(0,minr-maxl+1))