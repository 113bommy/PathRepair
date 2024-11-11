from math import gcd
n, X = [int(i) for i in input().split()]
x = [abs(int(i) - X) for i in input().split()]
ans = 0
for i in x:
    ans = gcd(ans, i)
print(ans)