m = int(input())
for i in range(m):

  x,y,n = map(int,input().split())
  d = n % x
  if d < x:
      print(n-d-x+y)
  else:
      print(n-d+y)
    
    