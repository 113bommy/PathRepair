import math

n = int(input())
x = n // 2
numbers = [1 for i in range(x+1)]
numbers[0] = 0
numbers[1] = 0
for i in range(2, x+1):
    if numbers[i]:
        j = 2
        while j*i <= x:
            numbers[j*i] = 0
            j += 1

primes = []
for i in range(x+1):
    if numbers[i]:
        primes.append(i)


def max_power(a, b):
    counter = 0
    while b % a == 0:
        counter += 1
        b /= a
    return counter


z = n
factorization = []
for prime in primes:
    x = max_power(prime, z)
    if x > 0:
        z /= prime**x
        factorization.append((prime, x))

factorization.sort()
answer = n
for factor in factorization:
    prime = factor[0]
    power = factor[1]
    for i in range(power):
        n /= prime
        answer += n

print(int(answer))


        




