from math import gcd


MOD = 10**9 + 7

n = int(input())

cnt = {}

zero_cnt = 0
for i in range(n):
    a, b = map(int, input().split())
    if (a,b) == (0,0):
        zero_cnt += 1
        continue
    g = gcd(abs(a), abs(b))
    a /= g
    b /= g
    rotate = 0
    while not (a > 0 and b > 0):
        a,b = -b,a
        rotate += 1
    if (a,b) not in cnt:
        cnt[(a,b)] = [0,0]

    cnt[(a,b)][rotate % 2] += 1

ans = 1
    
for key in cnt:
    A, B = cnt[key]
    ans *= 1 + pow(2, A, MOD) - 1 + pow(2, B, MOD - 1) - 1
    ans %= MOD

ans += zero_cnt
ans -= 1
print(ans % MOD)

    