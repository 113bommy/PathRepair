import bisect
primes = [0,0] + [1]*49999
for i in range(2, 224):
    if primes[i]:
        for j in range(i*i, 50001, i):
            primes[j] = 0

values = [k for k, b in enumerate(primes) if b]
while True:
    n = int(input())
    if n == 0:
        break
    end = bisect.bisect_left(values, n//2)+1
    print(sum(1 for i in values[:end] if primes[n-i]))