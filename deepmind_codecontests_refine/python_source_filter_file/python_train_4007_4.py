n,m,k=[int(x) for x in input().split()]
l=[[0 for i in range(n+2)] for i in range(m+2)]
no=0
for i in range(1,k+1):
  a,b=[int(x) for x in input().split()]
  l[a][b]=1
  if l[a][b]+l[a+1][b]+l[a][b+1]+l[a+1][b+1]==4 or \
     l[a+1][b-1]+l[a+1][b]+l[a][b-1]+l[a][b]==4 or \
     l[a][b]+l[a][b-1]+l[a+1][b]+l[a+1][b-1]==4 or \
     l[a-1][b]+l[a][b]+l[a-1][b+1]+l[a][b+1]==4:
    print(i)
    no=1
    break
if no==0:
  print(0)
