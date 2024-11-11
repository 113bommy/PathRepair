from fractions import gcd

N, X = map(int, input().split())
x = list(map(int, input().split()))
ans = x[0] - X

for a in x[1:]:
    ans = gcd(ans, abs(a-X))
print(ans)