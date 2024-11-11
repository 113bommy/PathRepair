n,k = map(int,input().split())
m=10**9+7
print((n-k+2)*(n*(n+k+1)+2*k*(1-k)+6)%m//6)