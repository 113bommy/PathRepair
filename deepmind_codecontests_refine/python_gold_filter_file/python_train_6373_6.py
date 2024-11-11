from math import gcd, sqrt, ceil
isPrime = [0, 0] + [1] * 1000001
for i in range(2, 1000001):
    if(isPrime[i]):
        for j in range(2*i, 1000001, i):
            isPrime[j] = 0
def isItPrime(n):
    for i in range(2, 1+int(sqrt(n))):
        if(n % i == 0):
            return 0
    return 1
t = int(input())
while(t):
    t -= 1
    a, m = list(map(int, input().split()))
    hcf = gcd(a, m)
    a //= hcf
    m //= hcf
    primes = []
    for i in range(1, 1+int(sqrt(m))):
        if(m % i == 0):
            if(isPrime[i]):
                primes.append(i)
            if(i != m//i and isItPrime(m // i)):
                primes.append(m // i)
    n = len(primes)
    ans = m
    for i in range(1, 2 ** n):
        b = bin(i)[2:].rjust(n,"0")
        temp = 1
        for j in range(n):
            if(b[j] == '1'):
                temp *= primes[j]
        left = ceil(a / temp) * temp
        right = ((a + m - 1) // temp) * temp
        count = ((right - left) // temp) + 1
        if(b.count("1") & 1):
            ans -= count
        else:
            ans += count
    print(ans)