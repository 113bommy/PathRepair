MOD = 10 ** 9 + 7

X, Y = map(int, input().split())

if (X + Y) % 3 != 0:
    print(0)
    exit()

a = (2 * X +   - Y) // 3
b = (  - Y + 2 * X) // 3

if a < 0 or b < 0:
    print(0)
    exit()

#calculate (a+b)!/a!b!

fac = [1, 1]
for i in range(2, a+b+1):
    fac.append(fac[-1] * i % MOD)

print(fac[a+b] * pow(fac[a] * fac[b], MOD-2, MOD) % MOD)