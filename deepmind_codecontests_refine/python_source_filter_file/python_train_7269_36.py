n,y=[int(i) for i in input().split()]
y //= 1000
for i in range(n+1):
  for j in range(n+1):
    if 10*i+5*j+(n-i-j)==y:
      print(i,j,n-i-j)
      exit(0)
print(-1,-1,-1)