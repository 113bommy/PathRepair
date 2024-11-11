import sys, math
import heapq

from collections import deque
input = sys.stdin.readline

#input
def ip(): return int(input())
def sp(): return str(input().rstrip())

def mip(): return map(int, input().split())
def msp(): return map(str, input().split().rstrip())

def lmip(): return list(map(int, input().split()))
def lmsp(): return list(map(str, input().split().rstrip()))

def list1(x, i): return [i for _ in range(x)]  # list[x]
def list2(x, y, i): return [[i for _ in range(y)] for _ in range(x)]  # list[x][y]
def list3(x, y, z, i): return [[[i for _ in range(z)] for _ in range(y)] for _ in range(x)]  # list[x][y][z]

#gcd, lcm
def gcd(x, y):
    while y:
        x, y = y, x % y
    return x

def lcm(x, y):
    return x * y // gcd(x, y)

#prime
def isPrime(x):
    if x==1: return False
    for i in range(2, int(x**0.5)+1):
        if x%i==0:
            return False
    return True

# Union Find
# p = {i:i for i in range(1, n+1)}
def find(x):
    if x == p[x]:
        return x
    q = find(p[x])
    p[x] = q
    return q

def union(x, y):
    global n
    x = find(x)
    y = find(y)

    if x != y:
        p[y] = x

def getPow(a, x):
    ret =1
    while x:
        if x&1:
            ret = (ret*a) % MOD
        a = (a*a)%MOD
        x>>=1
    return ret

def getInv(x):
    return getPow(x, MOD-2)

def lowerBound(start, end, key):
    while start < end:
        mid = (start + end) // 2
        if lst[mid] == key:
            end = mid
        elif key < lst[mid]:
            end = mid
        elif lst[mid] < key:
            start = mid + 1
    return end

def upperBound(start, end, key):
    while start < end:
        mid = (start + end) // 2
        if lst[mid] == key:
            start = mid + 1
        elif lst[mid] < key:
            start = mid + 1
        elif key < lst[mid]:
            end = mid
    if end == len(lst):
        return end-1
    return end

############### Main! ###############

n = ip()
x = []
for i in range(n):
    x.append(lmip())
x.sort(key=lambda x: x[1], reverse=True)
a = []
b = []
for i, j in x:
    a.append(i)
    b.append(j)
l = 0
r = n - 1
c = 0
ans = 0
while l <= r:
    while l <= r and a[l] + c <= b[r]:
        ans += a[l] * 2
        c += a[l]
        l += 1
    if l > r:
        break
    m = b[r] - c

    ans += m * 2
    a[l] -= m
    c = b[r]

    while l <= r and c >= b[r]:
        ans += a[r]
        c += a[r]
        r -= 1

print(ans)

######## Priest W_NotFoundGD ########