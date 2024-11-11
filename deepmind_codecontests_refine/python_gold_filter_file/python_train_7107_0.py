import sys, math
reader = (line.rstrip() for line in sys.stdin)
input = reader.__next__

def getInts():
    return [int(s) for s in input().split()]

def getInt():
    return int(input())

def getStrs():
    return [s for s in input().split()]

def getStr():
    return input()

def listStr():
    return list(input())

from functools import reduce

def factors(n):    
    return set(reduce(list.__add__, 
                ([i, n//i] for i in range(1, int(n**0.5) + 1) if n % i == 0)))

def prime_factors(n):
    factors = []
    num = 0
    while n % 2 == 0:
        num += 1
        n //= 2
    if num:
        factors.append((2,num))
    i = 3
    while n > 1 and i*i <= n:
        num = 0
        while n % i == 0:
            num += 1
            n //= i
        if num:
            factors.append((i,num))
        i += 2
    if n > 2:
        factors.append((n,1))
    return factors

def solve():
    N = getInt()
    facs = prime_factors(N)
    if len(facs) == 2 and facs[0][1] == 1 and facs[1][1] == 1:
        print(facs[0][0],facs[1][0],facs[0][0]*facs[1][0])
        print(1)
        return
    prime_facs = [f[0] for f in facs]
    facs2 = factors(N)
    facs2.remove(1)
    for p in prime_facs:
        facs2.remove(p)
    #facs2 = sorted(list(facs2))
    #first we need to make sure all requirements are satisfied, then we add in later elements
    to_add = []
    lenP = len(prime_facs)
    
    if lenP > 2:
        for j in range(lenP):
            y = prime_facs[j]*prime_facs[(j+1)%lenP]
            to_add.append(y)
            facs2.remove(y)
        ans = []
        for j in range(lenP):
            ans.append(prime_facs[j])
            ans.append(to_add[j])
    elif lenP == 1:
        ans = [prime_facs[0]]
    else:
        p0, p1 = prime_facs
        facs2.remove(p0*p1)
        ans = [p0,p1,p0*p1]
    for ff in facs2:
        for p in prime_facs:
            if ff % p == 0:
                prime = p
                break
        x = ans.index(prime)
        ans.insert(x+1,ff)
    assert(len(ans)==len(factors(N))-1)
    print(*ans)
    print(0)
    return
    
T = getInt()    
for t in range(T):
    solve()
    
