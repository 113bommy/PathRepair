n,k=map(int,input().split())
print((n-1)//(k-1)+(1 if n%k else 0))