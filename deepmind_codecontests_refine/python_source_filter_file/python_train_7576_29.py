import fractions

def lcm(x, y):
    return (x * y) // fractions.gcd(x, y)

N = int(input())
A = list(map(int, input().split()))

l = 1
for a in A:
    l = lcm(l, a)

ans = 0
for a in A:
    ans += l // a

print(ans % (10**9 + 7))