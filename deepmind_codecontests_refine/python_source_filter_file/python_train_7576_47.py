from math import gcd
N = int(input())
A = [int(i) for i in input().split()]
lcd = A[0]
for i in A:
    lcd = lcd * i // gcd(lcd,i)
ans = 0
for i in A:
    ans += lcd // i
print(ans% (10**9+7))