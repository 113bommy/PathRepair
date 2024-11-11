primes = [0, 0] + [1]*999
for i in range(2, 32):
    if primes[i]:
        for j in range(i*i, 1001, i):
            primes[j] = 0
while True:
    n = int(input())
    if n == 0:
        break
    m = n
    while not primes[m]:
        m -= 1
    pnum = [i for i in range(m+1) if primes[i]]
    ans = 0
    for i in range(len(pnum)):
        tmp = 0
        for j in range(i, len(pnum)):
            tmp += pnum[j]
            if tmp == n:
                ans += 1
                break
            if tmp > n:
                break
    print(ans)