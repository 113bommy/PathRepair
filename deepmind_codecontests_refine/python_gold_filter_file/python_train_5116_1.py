import math
import bisect
import heapq

def egcd(a, b):
    if a == 0:
        return (b, 0, 1)
    else:
        g, x, y = egcd(b % a, a)
        return (g, y - (b // a) * x, x)



def mulinv(b, n):
    g, x, _ = egcd(b, n)
    if g == 1:
        return x % n


primes = []

def isprime(n):
    for d in range(2, int(math.sqrt(n))+1):
        if n%d==0:
            return False
    return True


def argsort(ls):
    return sorted(range(len(ls)), key=ls.__getitem__)

def f(p=0):
    if p==1:
        return map(int, input().split())
    elif p==2:
        return list(map(int, input().split()))
    else:
        return int(input())



n, h = f(1)
cl = f(2)

x = [cl[0]]
mx = 1

for i in range(1, n):
    bisect.insort(x, cl[i])
    sm = 0
    for j in range(i-1, -1, -2):
        sm+=max(x[j], x[j+1])
        if sm>=h:
            break
    if i%2==0:
        sm+=x[0]
    if sm<=h:
        mx = max(mx, i+1)
    else:
        break

print(mx)
