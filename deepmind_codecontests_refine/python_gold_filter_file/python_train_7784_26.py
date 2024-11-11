n,m = map(int,input().split())
if n%2 == 0:
  na = n//2
  m1 = m//2
  m2 = m-m1
  for i,j in enumerate(range(n,n-m2,-1)):
    print(i+1,j)
  for i in range(na,na-m1,-1):
    print(i,n-i+2)
  
else:
  for i,j in enumerate(range(n,n-m,-1)):
    print(i+1,j)