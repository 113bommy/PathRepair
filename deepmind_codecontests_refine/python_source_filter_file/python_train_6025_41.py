n,l=[int(x) for x in input().split()]

a=[int(x) for x in input().split()]

j=-1
for i in range(1,n):
  if a[i]+a[i-1]>=l:
    j=i
    break
    
if j==-1:
  print("Impossible")
else:
  print(j)
  print("Possible")
  for i in range(j):
    print(i+1)
  for i in range(n-1,j,-1):
    print(i+1)