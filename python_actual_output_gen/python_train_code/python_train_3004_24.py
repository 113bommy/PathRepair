n,m=map(int,input().split())
a=sorted(list(map(int,input().split())),reverse=True)
if a[m-1]>=1/(4*m):
  print('Yes')
else:
  print('No')