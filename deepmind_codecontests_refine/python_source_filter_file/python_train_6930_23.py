def is_prime(a):
    for i in range(2, int(pow(a, 0.5) + 1)):
        if a % i == 0:
            return 1
    return 0


n = int(input())

if n % 2:
    print(1)
else:
    m = 1
    while True:
        if is_prime(m * n + 1):
            break
        m += 1
    print(m)
