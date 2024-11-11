from fractions import gcd
N=int(input())
a = list(map(int, input().split()))
lcm = 1
for i in a:
    lcm = lcm * i // gcd(lcm, i)
ans = 0
for i in a:
    ans += (lcm//i)#%(10**9+7)
print(ans%(10**9+7))