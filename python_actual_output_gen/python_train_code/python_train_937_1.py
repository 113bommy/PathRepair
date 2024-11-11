M = 998244353
n,m,K = map(int,input().split())
ans = 0
c = 1
for k in range(K+1):
    ans += c * m * pow(m-1,n-k-1,M)
    c *= (n-k+1) * pow(k+1,M-2,M)
    ans %= M
    c %= M
print(ans)
    
