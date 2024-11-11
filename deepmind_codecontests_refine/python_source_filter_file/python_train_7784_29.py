n,m=[int(_) for _ in input().split()]

n=2*m+1
if m%2==0:
  for i in range(m//2):
    print(i+1,m+1-i)
  for i in range(m//2):
    print(m+1+i,n-i)
else:
  for i in range(m//2):
    print(i+1,m-i)
  for i in range(m//2+1):
    print(m+1+i,n-i)