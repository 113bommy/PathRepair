n,k = map(int,input().split())
print(max(n-k,1) if k > 1 else 0)