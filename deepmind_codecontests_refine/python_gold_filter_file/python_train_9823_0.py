from itertools import combinations
from fractions import gcd

primos = [2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61]

def ToBinary(x):
    if x == 0:
        return "0"
    if x == 1:
        return "1"
    if x % 2 == 0:
        return ToBinary(x>>1)+ "0"
    else:
        return ToBinary(x>>1)+ "1"

def CountPeriodic(length):
    p = [x for x in primos if length % x == 0]
    ans = 0
    for x in p:
        d = length/x
        ans += 2**(d-1)
    for x,y in combinations(p,2):
        d = gcd(length/x, length/y)        
        ans -= 2**(d-1)
    for x,y,z in combinations(p,3):
        d = gcd(gcd(length/x, length/y), length/z)
        ans += 2**(d-1)
    return ans


def L(l,x,d):
    ans = 0
    d = int(d)
    x = int(x)
    p = 1
    while True:
        q = l[p:d].find('0')
        if q == -1:
            break
        ans += 2**(d-(p+q)-1)
        p += q+1
    for k in range(1,x):
        if l[0:d] > l[d*k:d*(k+1)]:
            return ans+1
        elif l[0:d] == l[d*k:d*(k+1)]:
            continue
        else:
            return ans
    return ans+1

def CountPeriodicL(l):
    length = len(l)
    p = [x for x in primos if length % x == 0]
    ans = 0
    for x in p:
        d = length/x
        ans += L(l,x,d)
    for x,y in combinations(p,2):
        d = gcd(length/x, length/y)        
        ans -= L(l,length/d,d)
    for x,y,z in combinations(p,3):
        d = gcd(gcd(length/x, length/y), length/z)
        ans += L(l,length/d,d)
    return ans


def R(r,x,d,eq=True):
    ans = 0
    d = int(d)
    x = int(x)
    p = 1
    while True:
        q = r[p:d].find('1')
        if q == -1:
            break
        ans += 2**(d-(p+q)-1)
        p += q+1
    for k in range(1,x):
        if r[0:d] < r[d*k:d*(k+1)]:
            return ans+1
        elif r[0:d] == r[d*k:d*(k+1)]:
            continue
        else:
            return ans
    return ans+(1 if eq else 0)

def CountPeriodicR(r,eq=True):
    length = len(r)
    p = [x for x in primos if length % x == 0]
    ans = 0
    for x in p:
        d = length/x
        ans += R(r,x,d,eq)
    for x,y in combinations(p,2):
        d = gcd(length/x, length/y)        
        ans -= R(r,length/d,d,eq)
    for x,y,z in combinations(p,3):
        d = gcd(gcd(length/x, length/y), length/z)
        ans += R(r,length/d,d,eq)
    return ans



l,r = map(int,input().split())

l_binary = ToBinary(l)
r_binary = ToBinary(r)

ans = 0
for i in range(len(l_binary)+1,len(r_binary)):   
    ans += CountPeriodic(i)


if len(l_binary)==len(r_binary):
    ans += CountPeriodicR(r_binary)
    ans -= CountPeriodicR(l_binary,False)
else:
    ans += CountPeriodicL(l_binary)
    ans += CountPeriodicR(r_binary)


print(int(ans))
