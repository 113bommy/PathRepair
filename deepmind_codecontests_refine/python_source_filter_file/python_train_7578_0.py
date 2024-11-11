N = int(input())
A = [int(input()) for i in range(N+1)]


def factorize(n):
    b = 2
    fct = {}
    while b * b <= n:
        while n % b == 0:
            n //= b
            if b in fct.keys():
                fct[b] += 1
            else:
                fct[b] = 1
        b += 1
    if n > 1:
        fct[n] = 1
    return fct


def gcd(a, b):
    """
    自然数a, b の最大公約数を求める
    """
    if b == 0:
        return a
    else:
        return gcd(b, a % b)


g = abs(A[0])
for a in A:
    g = gcd(g, abs(a))
cand = list(factorize(g).keys())
ans_set = [c for c in cand]


def SieveofEratosthenes(N: int) -> list:
    isPrime = [0] + [1 for _ in range(N-1)]
    numList = [i+1 for i in range(N)]
    for i in range(1, N):
        if isPrime[i] == 1:
            for k in range(i+1, N):
                if (k+1) % (i+1) == 0:
                    isPrime[k] = 0
    returnList = []
    for i, v in enumerate(isPrime):
        if v == 1:
            returnList.append(numList[i])
    return returnList


cand = SieveofEratosthenes(N+1)


def ans(cand):
    for p in cand:
        if A[0] % p != 0:
            continue
        for n in range(1, p):
            cur = 0
            for k in range((N-n)//(p-1)+1):
                cur += A[n+k*(p-1)]
                cur %= p
            if cur != 0:
                break
        if cur == 0:
            ans_set.append(p)
    return ans_set


A.reverse()
ans_set = ans(cand)
ans = list(set(ans_set))
for p in ans:
    print(p)