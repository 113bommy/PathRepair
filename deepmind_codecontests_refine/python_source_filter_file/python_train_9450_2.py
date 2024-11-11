n,k=map(int,input().split())
A=list(map(int,input().split()))
a=[0]*n
a[0]=1
nxt=A[0]-1
i=2
while 1:
  a[nxt]=i
  nxt=A[nxt]-1
  i+=1
  if a[nxt]!=0:
    g=i-a[nxt]
    t=a[nxt]-1
    break
if g>=k+1:
  print(a.index(k+1))
else:
  k-=t
  u=k%g
  print(a.index(t+u+1)+1)