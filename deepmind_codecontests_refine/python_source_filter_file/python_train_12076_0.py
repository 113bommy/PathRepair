n, m = map(int, input().split())

MOD = 10**9 + 7
if n == 1:
    print(m+1)
else:
    k = m//(n-1)
    res = m+1 + 2*(m*k - k*(k+1)*(n-1)//2+k)
    print(res % MOD)