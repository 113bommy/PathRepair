import sys
import math as m
def main():
    pass
def binary(n):
    return (bin(n).replace("0b", ""))
def decimal(s):
    return (int(s, 2))
def pow2(n):
    p = 0
    while n > 1:
        n //= 2
        p += 1
    return (p)
def isPrime(n):
    if (n == 1):
        return (False)
    else:
        root = int(n ** 0.5)
        root += 1
        for i in range(2, root):
            if (n % i == 0):
                return (False)
        return (True)
def sinp(): return sys.stdin.readline().strip()
def iinp(): return int(input())
def ninp(): return map(int, sys.stdin.readline().strip().split())
def linp(): return list(map(int, sys.stdin.readline().strip().split()))
def p(a): print(a)
for _ in range(iinp()):
    x=iinp()
    n=1
    ans=0
    while(True):
        ind=0
        b=n
        tot=0
        while(b!=1):
            tot=tot+b*b*(2**ind)
            b=b/2
            ind+=1
        tot=tot+(2**ind)
        x=x-tot
        if(x>=0):
            ans+=1
            n=n*2
        else:
            break
    print(ans)


