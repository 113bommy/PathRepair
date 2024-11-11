from math import gcd
n = int(input())
T = [int(input()) for i in range(n)]
ans = 1
for t in T:
    ans = ans*t//gcd(ans,t)
print(ans)