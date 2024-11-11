def divisors(n):
    i = 2
    k = 1
    while i*i <= n:
        q = 1
        while n%i == 0:
            n //= i
            q += 1
        k *= q
        i += 1
    if n != 1:
        k += 1
    return k
def bruh():
    n = int(input())
    if n == 1:
        print(1)
    else:
        print(divisors(n))
bruh()