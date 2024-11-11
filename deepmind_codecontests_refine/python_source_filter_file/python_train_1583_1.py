def h(s, k):
    res = ''
    for i in s:
        if i != k:
            res += i
    return res

def ans(s, k, times, Pr: list):
    d = h(s, k)
    j = 0
    res = ''
    cc = 0
    for i in range(len(s)):
        if (i + 1) not in Pr:
            res += k
            cc += 1
        elif j < len(d):
            res += d[j]
            j += 1
        else:
            res += k
    return res


def ans1(s, k, times, Pr: list):
    d = h(s, k)
    res = ''
    res += d[0]

    j = 1
    for i in range(len(s)):
        if (i + 2) not in Pr:
            res += k
        elif j < len(d):
            res += d[j]
            j += 1
        else:
            res += k
    return res


def isprime(n):
    i = 2
    while i*i <= n:
        if n % i == 0:
            return False
        i += 1
    return True

def getprimes(n):
    res = []
    for i in range(2, n + 1):
        if isprime(i):
            res.append(i)
    return res

s = input()
A = []
Primes = getprimes(len(s))


def f(A: list, l):
    res = 0
    resPr = []
    for i in A:
        if i > l // 2:
            res += 1
            resPr.append(i)
    return res, resPr


g, Pr = f(Primes, len(s))

Dict = dict()
for i in s:
    if i in Dict:
       Dict[i] += 1
    else:
        Dict[i] = 1
for k, v in Dict.items():
    if v >= len(s) - g:
        print('YES')
        print(ans(s, k, len(s) - g, Pr), end='')
        exit()
    elif v == len(s) - g - 1:
        print('YES')
        print(ans1(s, k, len(s) - g, Pr), end='')
        exit()
print('NO')