n,k = map(int,input().split())
if n % 2 == 0:
  if 2*k > n:
    print(-1)
  else:
    for i in range(n//2):
      print(k+2*i, k+(3*n)//2-1-i, k+2*n+i)
    for i in range(n//2):
      print(k+1+2*i, k+2*n-1-i, k+(5*n)//2+i)
else:
  if 2*k-1 > n:
    print(-1)
  else:
    for i in range((n+1)//2):
      print(k+2*i, k+(3*n-1)//2-i, k+2*n+i)
    for i in range((n-1)//2):
      print(k+1*2*i, k+2*n-1-i, k+(5*n+1)//2+i)