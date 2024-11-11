n=int(input())
if n<3:
  print(-1)
elif n*n%4:
  print(n*n//2,n*n//2+1)
else:
  print(n*n//4-1,n*n//4+1)