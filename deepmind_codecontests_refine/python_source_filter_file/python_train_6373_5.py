from math import sqrt

primes = [2]
seen = set()

for i in range(3,int(1e5),2):
    if i not in seen:
        primes.append(i)
        for j in range(i+i,int(1e5),i):
            seen.add(j)

def gcd(a,b):
    if b > a:
        a,b = b,a
    r = a%b
    if r == 0:
        return b
    return gcd(b,r)

def hipow(n, x):
    if n%x:
        return 1,n
    ret,n = hipow(n,x*x)
    if n%x == 0:
        ret*=x
        n//=x
    return ret,n

def totient(n):
    ret = 1
    lim = sqrt(n)
    for d in primes:
        if n%d == 0:
            t,n = hipow(n,d)
            ret *= t-t//d
        if n == 1:
            break
    else:
        ret *= n-1

    return ret



T = int(input().strip())

for _ in range(T):
    a,m = map(int, input().split())
    d = gcd(a,m)
    print(d, totient(m//d))
