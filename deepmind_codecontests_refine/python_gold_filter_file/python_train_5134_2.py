q = int(input())
import math
factors = []
def primeFactors(n):
    f = 0
    global factors
    while n % 2 == 0:
        f += 1
        n = n // 2
        factors.append(2)
    for i in range(3, int(math.sqrt(n)) + 2, 2):
        while n % i == 0:
            factors.append(i)
            n = n // i
            f += 1
    if n > 2:
        factors.append(n)
        f += 1
    return f

fac = primeFactors(q)
#print("factors", fac)
#print(factors)
if fac == 2:
    print(2)
elif fac == 1 or q == 1:
    print(1)
    print(0)
else:
    print(1)
    print((factors[0]) * factors[1])