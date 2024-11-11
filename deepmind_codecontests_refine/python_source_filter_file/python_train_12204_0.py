import random
n = int(input())
a = list(map(int, input().split()))

primes = set()
for x in random.choices(a, k=min(n, 30)):
    for y in (x-1, x, x+1):
        d = 2
        while d * d <= x:
            while x % d == 0:
                primes.add(d)
                x //= d
            d += 1 + (d & 1)
        if x > 1:
            primes.add(x)

ans = float('inf')
for p in primes:
    cand = 0
    for x in a:
        if x < p:
            cand += p - x
        else:
            r = x % p
            cand += min(r, p-r)

        if cand >= ans:
            break
    else:
        ans = cand

print(ans)
