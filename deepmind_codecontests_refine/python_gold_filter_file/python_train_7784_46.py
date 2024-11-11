n,m=map(int,input().split())
if n%2==0:
  counter=0
  for i in range(min(m,n//4)):
    print(i+1)
    print(n-i)
    counter+=1
  if counter<m:
    for i in range(n//4,m):
      print(i+1)
      print(n-i-1)
else:
  for i in range(m):
    print(i+1)
    print(n-i)