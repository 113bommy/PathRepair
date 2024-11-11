n = int(input())
primes = []
for i in range(11, 1500, 10):
    for j in range(2, int(i**0.5) + 1):
        if i % j == 0:
            break
    else:
        primes.append(i)
print(*primes[:n])