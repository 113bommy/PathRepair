import fractions

n = int(input())
t = 1
for i in range(n):
    t0 = int(input())
    t = t * t0 / fractions.gcd(t, t0)
print(int(t))