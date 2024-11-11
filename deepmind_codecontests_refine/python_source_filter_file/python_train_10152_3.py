l,r,k=map(int,input().split())
s=1
b=1
while s<r:
  if s>=l and s<=r:
    print(s)
    b=0
  s*=k
if b==1:
  print(-1)
