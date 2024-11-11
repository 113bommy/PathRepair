import fractions
N = int(input())
lcm = 1
for i in range(N):
    t = int(input())
    lcm = lcm * t / fractions.gcd(lcm,t)
print(int(lcm))
