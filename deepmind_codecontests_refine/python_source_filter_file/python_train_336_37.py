from sys import stdin
from math import factorial
n = int(stdin.readline())
ans = 1
for i in range(1, n+1):
    ans *= (i % (10 ** 9 + 7))
    ans %= 10 ** 9 + 7
ans -= (2 ** (n-1)) % (10 ** 9 + 7) 
print(ans)