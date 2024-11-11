def sieve(a, b):
    m = []
    if (b != 1):
        if (a == 1):
            a += 1
        primes = [1] * (b + 1)
        primes[0] = 0
        primes[1] = 0
        for i in range(2, b + 1):
            if (primes[i] == 1):
                for j in range(2 * i, b + 1, i):
                    primes[j] = 0
        for i in range(a, b + 1):
            if (primes[i] == 1):
                m.append(i)
        return m
    elif (a == 1) and (b == 1):
        return

n = int(input())
k = 0
ans = []
if n == 1:
    print(k)
else:
    mas = sieve(2, n)
    for i in mas:
        j = i
        ans.append(j)
        k += 1
        while (n >= j ** 2):
            j *= j
            ans.append(j)
            k += 1
    print(k)
    print(*ans)