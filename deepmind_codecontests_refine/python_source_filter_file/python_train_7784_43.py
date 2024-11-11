n,m=map(int,input().split())
l1,r2=1,n
if m%2:
  r1=m
else:
  r1=m+1
l2=r1+1
for i in range(m//2):
  print(l1,r1)
  print(l2,r2)
  l1+=1
  l2+=1
  r1-=1
  r2-=1
if m%2:
  print(l2,r2)