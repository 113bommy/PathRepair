n=int(input())
if n%2==0:
  m=(n**2-2*n)//2
  print(m)
  for i in range(1,n+1):
    for j in range(i,n+1):
      if j == i or j== n+1-i:continue
      print(i,j)
else:
  m=n+((n-1)**2-(n-1)*2)//2
  print(m)
  for i in range(1,n):
    for j in range(i+1,n+1):
      if j == n-i: continue
      print(i,j)