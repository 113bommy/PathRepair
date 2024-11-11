def isPrime(m):
    for j in range(2, int(m ** 0.5) + 1):
        if m % j == 0:
            return False
    return True


n = int(input())
count = 0
mas = []
for i in range(2, n):
    if isPrime(i):
        step = 1
        while i ** step <= n:
            count += 1
            mas.append(i ** step)
            step += 1
print(count)
print(*mas)