n,y = [int(i)  for i in input().split()]
for i in range(2001):
  for j in range(0,n-i):
      if 10000*(i)+5000*(j)+1000*(n-i-j) == y:
        print(i,j,n-i-j)
        exit()
print(-1,-1,-1)