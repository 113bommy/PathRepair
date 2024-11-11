import math

divisor = int(math.pow(10, 9)) + 7

def solution():
    x, n = map(int, input().split())
    primes = get_primes(x)
    print(primes)
    res = 1
    for prime in primes:
        res = (res * (helper(prime, n) % divisor)) % divisor
    print(res)


def get_primes(x):
    primes = []
    i = 2
    limit = int(math.sqrt(x)) + 1
    while i < limit:
        if x % i == 0:
            primes.append(int(i))
            while x % i == 0:
                x = x / i
        else:
            i += 1
    if x > 1:
        primes.append(int(x))
    return primes


def helper(p, n):
    k = 1
    count = 0
    p_k = p
    # res = 1
    while n >= p_k:
        count += n // p_k
        p_k = p_k * p
        # res = res * p_k
    res = pow(p, count, divisor)
    return res


if __name__ == '__main__':
    solution()