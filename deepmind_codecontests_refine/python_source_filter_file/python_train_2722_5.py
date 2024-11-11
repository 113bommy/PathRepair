n=int(input())
h='#'
f=[[h]*(n+2)]
a=f+[[*(h+input()+h)]for _ in[0]*n]+f*2
for i in range(n):
 for j in range(n):
  if a[i+1][j+1]>h:
   for k,l in(2,0),(2,1),(1,1),(3,1):
    if a[i+k][j+l]==h:print('NO');exit()
    a[i+k][j+l]=h
print('YES')