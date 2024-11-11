n,k=map(int,input().split())
a=list(map(int,input().split()))
adj=[1]*n
b=[1]
now=0
while adj[now]:
  adj[now]=0
  now=a[now]-1
  b.append(now+1)
loop_start=b.index(b[-1])
loop=b[loop_start:-1]
p=len(loop)
if k<loop_start:
  print(b[k])
else:
  k-=loop_start
  k%=p
  print(loop[k])
