import math
dp = {2**i:2**(i+1)-1 for i in range(61)}
print(dp)

def solver_for_2k(n):
    return dp[n]


def solve(n):
    ans = 0
    p = 1
    while n > 0:
        if n % 2 == 1:
            ans += solver_for_2k(p)
        n = n // 2
        p *= 2
    return ans


def read():
    t = int(input())
    for i in range(t):
        n = int(input())
        ans = solve(n)
        print(ans)


read()
