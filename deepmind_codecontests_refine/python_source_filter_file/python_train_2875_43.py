n,k=map(int,input().split())
print(0 if n==k else 1,k*2 if k*2<n-k else n-k)
