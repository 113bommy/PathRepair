def fast_pow(base, power, modulo):
    if power == 0:
        return 1
    if power % 2 == 1:
        return (fast_pow(base, power-1, modulo)*base) % modulo
    else:
        b = fast_pow(base, power//2, modulo)
        return (b * b) % modulo


def get_inverse(x, modulo):
    return fast_pow(x, modulo - 2, modulo)


n, m = map(int, input().split())

if m - 1 < n or n == 2:
    print(0)
    exit(0)

c = 1
mod = 998244353
sum = 0

for maxx in range(n - 1, m + 1):
    sum += c
    #sum = sum % mod;
    c = (c * maxx * get_inverse(maxx - (n-2), mod)) % mod

#print(sum % mod)
sum = sum * (n - 2) % mod
for i in range(0, n-3):
    sum *= 2
    sum = sum % mod

print(sum % mod)


