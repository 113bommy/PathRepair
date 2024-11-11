import sys
from math import gcd

n = int(input())
a = list(map(int, input().split()))
ans = [a[0]]
for i in range(1, n):
    if gcd(a[i-1], a[i]) != 1:
        for j in range(2, 10**9):
            if gcd(a[i-1], j) == 1 and gcd(a[i], j) == 1:
                ans.append(j)
                break
    ans.append(a[i])

print(len(ans))
print(*ans)
