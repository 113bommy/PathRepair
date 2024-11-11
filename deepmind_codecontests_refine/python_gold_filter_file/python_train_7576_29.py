import fractions
def lcm(x, y):
    return (x * y) // fractions.gcd(x, y)
N = int(input())
A = [int(x) for x in input().split()]
a = 1
MOD = 10**9+7
for i in A:
  a = lcm(a,i)
ans = 0
for i in A:
  ans += (a//i)
print(ans%MOD)
