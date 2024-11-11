from math import gcd

n = int(input())
k = list(map(int, input().split()))
ans = k[0]

for i in k:
    ans = gcd(ans, i)

print(ans)