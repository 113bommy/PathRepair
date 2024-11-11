y,k,n=map(int,input().split(' '))
r_x = n-y
#print(r_x)
j=(k-(y%k))
#j = (n-(n%k))-y
#print(j)
if j<=r_x and j>=1:
  for i in range(j,r_x+1,k):
    print(i, end=' ')
else:
  print(-1)