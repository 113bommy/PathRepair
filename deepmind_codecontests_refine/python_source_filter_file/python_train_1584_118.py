def is_prime(n):
    i = 2
    while i * i <= n:
        if n % i == 0:
            return False
        i += 1
    return True

n = int(input())
i = 4
while True:
    if is_prime(i) or is_prime(i+n):
        i += 1
        continue
    print("{} {}".format(i, i+n))
    break