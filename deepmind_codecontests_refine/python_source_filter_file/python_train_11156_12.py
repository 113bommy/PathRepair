from bisect import bisect_left


def is_prime(n):
    for i in range(2, n):
        if n % i == 0:
            return False
    return True


primes = []

for i in range(2, 1010):
    if is_prime(i):
        primes.append(i)

n = int(input())
adjacencyList = []

for i in range(n):
    adjacencyList.append({(i + 1) % n, (i - 1) % n})

nextPrime = primes[bisect_left(primes, n)]
moreEdges = nextPrime - n

for i in range(moreEdges):
    adjacencyList[i].add(n // 2 + i)
    adjacencyList[n // 2 + i].add(i)

print(nextPrime)

for i, v in enumerate(adjacencyList):
    for u in v:
        if (u > i):
            print('{} {}'.format(i, u))
