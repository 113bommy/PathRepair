n,k=map(int,input().split())
a=list(map(int,input().split()))
for i in range(n-k+1):
  if a[i]<a[i+k+1]:
    print('Yes')
  else:
    print('No')