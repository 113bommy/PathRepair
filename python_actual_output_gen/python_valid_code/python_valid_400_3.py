n,m,k=list(map(int,input().split()))
print(m**n%(10**9+7) if k>n else m**(-(-n//2) if n==k else k%2+1)%(10**9+7))