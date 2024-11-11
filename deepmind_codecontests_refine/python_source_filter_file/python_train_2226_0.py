n, k = map(int, input().split())
m=10**9+7
print(pow(k,k,m)*pow(n-k,n-k,m)%m)