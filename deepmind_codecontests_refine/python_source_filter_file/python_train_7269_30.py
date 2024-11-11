n,y=map(int,input().split())
x=[-1,-1,-1]
for i in range(n+1):
  for j in range(n-i+1):
    if 10000*i+5000*j+1000*(n-i-j)==y:
      x=[i,j,n-i-j]
      break
for _ in range(3):
  print(x[i])