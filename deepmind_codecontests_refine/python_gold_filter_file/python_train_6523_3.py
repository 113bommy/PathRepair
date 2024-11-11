n,k=map(int,input().split())
a=list(map(int,input().split()))
if n==k:
  print(max(a))
  exit()
if k==0:
  if min(a)==1:
    print(-1)
  else:
    print(min(a)-1)
  exit()
a.sort()
if a[k-1]==a[k]:
  print(-1)
else:
  print(a[k]-1)