from math import gcd
n = int(input())
A = list(map(int, input().split()))
ans = A[0]
for a in A[1:]:
    ans = gcd(ans, a)
print(ans)
