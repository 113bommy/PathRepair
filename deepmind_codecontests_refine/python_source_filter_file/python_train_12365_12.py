n,k=map(int,input().split())
a=list(map(int,input().split()))
for i in range(k,n):
  if a[k]>a[i-k]:
    print('Yes')
  else:
    print('No')