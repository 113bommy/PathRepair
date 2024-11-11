def gcd(a, b):
    c = a % b
    return gcd(b, c) if c else b

n = int(input())
t = list(map(int, input().split()))

x = gcd(t[0], t[1])
for i in t[2: ]:
    x = gcd(i, x)
print(['Bob', 'Alice'][(max(t) // x - n) % 2])