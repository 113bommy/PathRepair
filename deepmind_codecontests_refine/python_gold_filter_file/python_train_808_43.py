#!/usr/bin/env python3
MOD = 10**9 + 7
n = int(input())
a = list(map(int, input().split()))
ans = 0
for b in range(60)[::-1]:
    ans <<= 1
    c = sum(a[i] >> b & 1 for i in range(n))
    ans = (ans + c * (n - c)) % MOD
print(ans)
