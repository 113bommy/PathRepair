x,y,z=map(int,input().split())
x1,y1,z1=map(int,input().split())
arr=list(map(int,input().split()))
sums=0
if x>0:
  if x>x1:
    sums+=arr[5]
  elif x<0:
    sums+=arr[4]
elif x<0:
  if x<x1:
    sums+=arr[5]
  elif x>0:
    sums+=arr[4]
if y>0:
  if y>y1:
    sums+=arr[1]
  elif y<0:
    sums+=arr[0]
elif y<0:
  if y<y1:
    sums+=arr[1]
  elif y>0:
    sums+=arr[0]
if z>0:
  if z>z1:
    sums+=arr[3]
  elif z<0:
    sums+=arr[2]
elif z<0:
  if z<z1:
    sums+=arr[3]
  elif z>0:
    sums+=arr[2]
  
print(sums)