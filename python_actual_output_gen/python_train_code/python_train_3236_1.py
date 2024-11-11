def modInverse(a, m):
    g = gcd(a, m)
    if g != 1:
        return 1
    else:
        return power_fct(a, m - 2, m)


def power_fct(x, y, m):
    if y == 0:
        return 1

    p = power_fct(x, y // 2, m) % m
    p = (p * p) % m

    if y % 2 == 0:
        return p
    else:
        return (x * p) % m


def gcd(a, b):
    if a == 0:
        return b
    return gcd(b % a, a)


def radio_towers():
    n = int(input())
    modulo = 998244353

    fib = [1, 1]
    power = 4

    for i in range(2, n):
        fib = [sum(fib) % modulo, fib[0]]
        power = (power * 2) % modulo

    print((modInverse(power, modulo) * fib[0]) % modulo)


if __name__ == "__main__":
    radio_towers()
