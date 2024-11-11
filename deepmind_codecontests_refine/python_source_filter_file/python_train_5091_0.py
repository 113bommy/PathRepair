primes = [0, 0] + [1] * 9999
for i in range(2, 101):
    if primes[i]:
        for j in range(i*i, 10001, i):
            primes[j] = 0

while True:
    try:
        N = int(input())
    except:
        break
    print(sum(primes[i] & primes[-i] for i in range(1, N+1)))