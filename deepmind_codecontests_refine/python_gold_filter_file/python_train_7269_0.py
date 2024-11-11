n,y=map(int,input().split())

for i in range(0,n+1):
  for j in range(0,n+1-i):
    if 10000*i+5000*j+1000*(n-i-j)==y:
      print(i,j,n-i-j)
      exit()
print("-1 -1 -1")