n,m=map(int,input().strip().split())
s = input()
x=list(s)
for i in range(m):
  l,r,c1,c2=input().strip().split(' ')
  l,r,c1,c2=[int(l),int(r),str(c1),str(c2)]
  for j in range(l-1,r):
    if x[j]==c1:
      x[j]=c2
  print(''.join(x))
  