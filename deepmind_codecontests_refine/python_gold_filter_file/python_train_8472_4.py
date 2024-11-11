n,k=map(int,input().split())
print(2*k-1 if k<=n-n//2 else 2*(k-n+n//2))