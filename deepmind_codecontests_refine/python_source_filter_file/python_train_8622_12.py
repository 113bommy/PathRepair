import bisect
n = 10**5
primes = set(range(2, n+1))
for i in range(2, int(n**0.5+1)):
    primes.difference_update(range(i*2, n+1, i))
primes=[i for i in primes if (i+1)//2 in primes]
q=int(input())
for i in range(q):
    a,b=map(int, input().split())
    print(bisect.bisect_right(primes, 7)-bisect.bisect_left(primes, 3))