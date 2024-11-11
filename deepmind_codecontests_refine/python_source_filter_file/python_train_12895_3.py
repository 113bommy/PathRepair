primes = [0, 0] + [1]*49999
for i in range(2, 224):
    if primes[i]:
        for j in range(i*i, 50001, i):
            primes[j] = 0
while True:
    try:
        n = int(input())
    except:
        break
    m, o = n-1, n+1
    while not primes[m]:
        m -= 1
    while not primes[o]:
        o += 1
    print(m, o)