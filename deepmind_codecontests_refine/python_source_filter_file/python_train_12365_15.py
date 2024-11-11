n,k = map(int,input().split())
a = list(map(int,input().split()))

for i in range(k,n+1):
  if a[i] > a[i-k]:
    print('Yes')
  else:
    print('No')