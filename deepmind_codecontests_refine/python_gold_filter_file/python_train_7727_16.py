M = 998244353
N = 200010
ten = [1] * N
for i in range(1, N):
    ten[i] = (ten[i-1]*10) % M
n = int(input())
for i in range(1, n):
    ans = 10*9*2*ten[n-i-1]
    if i < n-1:
        ans += (n-1-i)*10*9*9*ten[n-i-2]
    print(ans % M, end=' ')
print(10)