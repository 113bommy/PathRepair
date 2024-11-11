import sys
r=sys.stdin.readline
def s():
 def b(M,x,y,n=1):
  M[x][y]=0;a=n
  if M[x-1][y]:a=max(a,b(M,x-1,y,n+1))
  if M[x][y-1]:a=max(a,b(M,x,y-1,n+1))
  if M[x+1][y]:a=max(a,b(M,x+1,y,n+1))
  if M[x][y+1]:a=max(a,b(M,x,y+1,n+1))
  M[x][y]=1
  return a
 for e in iter(r,'0'):
  n,m=int(e),int(r())
  P=[[0]*(n+2)for _ in[0]*(m+2)]
  for i in range(m):P[i+1][1:-1]=map(int,r().split())
  print(max(b(P,i,j)for i in range(1,m+1)for j in range(1,n+1)if P[i][j]))
if'__main__'==__name__:s()
