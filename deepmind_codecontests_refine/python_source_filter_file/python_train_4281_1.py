# -*- coding:utf-8 -*-

"""

created by shuangquan.huang at 11/19/18

"""

N, M = map(int, input().split())
A = [int(x) for x in input()]

memo = [0] * (N+1)
def pow(n):
    if n == 0:
        return 1

    if n < 30:
        return 1 << n

    if memo[n] > 0:
        return memo[0]

    half = pow(n // 2)

    ans = half * half
    if n % 2 != 0:
        ans *= 2
    ans %= MOD
    memo[n] = ans

    return ans


MOD = 10 ** 9 + 7

left = [0] * (N + 1)
for i in range(1, N + 1):
    left[i] = left[i - 1] + A[i - 1]

ans = []
for qi in range(M):
    l, r = map(int, input().split())
    ones = left[r] - left[l - 1]
    zeros = r - l + 1 - ones
    x = pow(ones) - 1
    y = x * (pow(zeros)- 1)
    ans.append((x + y) % MOD)

print('\n'.join(map(str, ans)))