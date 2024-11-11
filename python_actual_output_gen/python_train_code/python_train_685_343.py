n,k = tuple(map(int,input().split()))
print(min(n%k,n-n%k))