a=list(map,input().split())
k=int(input())
while a[0]>=a[1]:
  k-=1
  a[1]*=2
while a[1]>=a[2]:
  k-=1
  a[2]*=2
if k>=0:
  print("Yes")
else:
  print("No")
