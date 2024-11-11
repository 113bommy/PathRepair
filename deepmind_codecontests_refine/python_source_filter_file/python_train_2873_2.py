#!/usr/bin/pypy3

from sys import stdin,stderr
from random import shuffle

def readInts(): return map(int,stdin.readline().strip().split())
def print_err(*args,**kwargs): print(*args,file=stderr,**kwargs)
    
def solve(vs):
    modval = 10**9+7
    print(all_f(vs))

def expnm(a,b,m):
    if b==0: return 1
    if b%2 == 0: return expnm(a*a%m,b//2,m)
    return (a*expnm(a,b-1,m)%m)

def expnm2(a,b,m):
    #print(a,b)
    out = 1
    mult = a
    while b > 0:
        if b%2 == 0:
            mult *= mult
            b //= 2
        else:
            out *= mult
            b -= 1
        out %= m
    return out

def all_f_naive(ns):
    n = len(ns)
    ns.sort()
    out = 0
    m = 10**9+7
    for x1ix in range(n-1):
        for x2ix in range(x1ix+1,n):
            c = x2ix-x1ix-1
            d = ns[x2ix]-ns[x1ix]
            out += d * (expnm(2,c,m))
            out %= m
    return out

def twos(n,m):
    v = 1
    out = []
    for _ in range(n+1):
        out.append(v)
        v <<= 1
        v %= m
    return out

def all_f(ns):
    n = len(ns)
    ns.sort()
    out = 0
    m = 10**9+7
    t = twos(n,m)
    for x1ix in range(n):
        v = ns[x1ix] * t[x1ix]
        v %= m
        out += v
        out %= m
        v = ns[x1ix] * t[n-x1ix-1]
        v %= m
        out -= v
        out %= m
    return out

def all_f3(ns):
    n = len(ns)
    ns.sort()
    out = 0
    m = 10**9+7
    for x1ix in range(n):
        v = ns[x1ix] * expnm(2,x1ix,m)
        v %= m
        out += v
        out %= m
        v = ns[x1ix] * expnm(2,n-x1ix-1,m)
        v %= m
        out -= v
        out %= m
    return out

def all_f2(ns):
    n = len(ns)
    ns.sort()
    out = 0
    m = 10**9+7
    for x1ix in range(n):
        v = ns[x1ix] * expnm2(2,x1ix,m)
        v %= m
        out += v
        out %= m
        v = ns[x1ix] * expnm2(2,n-x1ix-1,m)
        v %= m
        out -= v
        out %= m
    return out

def run():
    n, = readInts()    
    vs = list(readInts())
    print(solve(vs))
        
run()
