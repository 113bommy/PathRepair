import sys
sys.setrecursionlimit(10**9)
mod = 998244353
N, S = list(map(int, input().split()))
A = list(map(int, input().split()))

ans = 0
num = [0] * 6020
for i in range(N):
    for j in range(3010, 0, -1):
        num[A[i]+j] += num[j]
        num[A[i]+j] %= mod
    num[A[i]] += i+1
    num[A[i]] %= mod
    ans += num[S] * (N - i)
    ans %= mod
    num[S] = 0
print(ans)
