n = int(input())
a = list(map(int,input().split()))
if abs(max(a))>=abs(min(a)):
  p = a.index(max(a))
  print(2*n-1)
  for i in range(n):
    print(p+1,i+1)
  for i in range(1,n):
    print(i,i+1)
else:
  p = a.index(min(a))
  print(2*n-1)
  for i in range(n):
    print(p+1,i+1)
  for i in range(n,0,-1):
    print(i+1,i)