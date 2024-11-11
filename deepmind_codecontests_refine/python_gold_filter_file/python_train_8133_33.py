n,k = map(int,input().split())
print(min(n-k,k-1) + n*3)