MOD = (10 ** 9 + 7)

x, n = list(map(int, input().split()))

# def g(x, p):
#     k = 0
#     while True:
#         if x % p ** k != 0:
#             break
#         k += 1
#     return p ** (k - 1)

# def f(x, y):
#     result = 1
#     for p in primes:
#         result = result * g(y, p)
#     return result

def calc_exponents(n, p):
    exp = 0
    while n > 0:
        exp += n // p
        n = n // p
    return pow(p, exp, MOD)

primes = []
p = 2
while p * p <= x:
    if x % p == 0:
        primes.append(p)
        while x % p == 0:
            x = x // p
    p = p + 1

if x > 1:
    primes.append(x)

answer = 1
for p in primes:
    answer *= calc_exponents(n, p) % MOD

print(answer)
