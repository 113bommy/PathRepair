N,K=map(int,input().split())
a=list(map(int,input().split()))
for v in range(K-1):
  if a[v]>=a[K+v]:
    print("No")
  else:
    print("Yes")
