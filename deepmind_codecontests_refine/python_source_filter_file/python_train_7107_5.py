# Fast IO (be careful about bytestring, not on interactive)

import os,io
input=io.BytesIO(os.read(0,os.fstat(0).st_size)).readline

from math import sqrt,ceil

for _ in range(int(input())):
    n = int(input())
    factors = [n]
    primeFactors = []
    for i in range(2,ceil(sqrt(n)) + 2):
        if n % i == 0 and factors[-1] != i:
            factors.append(i)
            if i != n // i:
                factors.append(n // i)
    isPrime = [True] * len(factors)
    factors.sort()
    for i in range(len(factors)):
        for j in range(i):
            if factors[i] % factors[j] == 0:
                isPrime[i] = False
                break
    for i in range(len(factors)):
        if isPrime[i]:
            primeFactors.append(factors[i])
    if len(primeFactors) <= 1:
        print(" ".join(map(str,factors)))
        print(0)
    elif len(factors) == 3 and factors[2] % factors[1] != 0:
        print(" ".join(map(str,factors)))
        print(1)
    elif len(primeFactors) == 2:
        a = primeFactors[0]
        b = primeFactors[1]
        ans = [a * b]
        i = 1
        while n % (a ** i) == 0:
            ans.append(a ** i)
            i += 1
        for elem in factors:
            if elem % a == 0 and elem % b == 0 and elem != a * b:
                ans.append(elem)
        i = 1
        while n % (b ** i) == 0:
            ans.append(b ** i)
            i += 1
        print(" ".join(map(str,ans)))
        print(0)
    else:
        isCovered = [False] * len(factors)
        ans = []
        for i in range(len(primeFactors)):
            a = primeFactors[i]
            ans.append(a)
            for j in range(len(factors)):
                elem = factors[j]
                if elem % a == 0 and elem != a and elem != a * primeFactors[(i + 1) % len(primeFactors)] and elem != a * primeFactors[i - 1] and not isCovered[j]:
                    ans.append(elem)
                    isCovered[j] = True
            ans.append(a * primeFactors[(i + 1) % len(primeFactors)])
        print(" ".join(map(str,ans)))
        print(0)