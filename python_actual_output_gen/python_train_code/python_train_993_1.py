for _ in range(int(input())):
  n=int(input())
  a=list(map(int,input().split()))
  x=a[0]%2
  for i in range(n):
    if a[i]%2!=x:
      print('NO')
      break
  if i==n-1:
    print('YES')
    
