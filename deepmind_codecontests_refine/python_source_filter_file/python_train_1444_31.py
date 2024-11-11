import math
n = int(input())
s = int(input())

def c(b):
    cur = n
    acc = 0
    while cur != 0:
        div, mod = divmod(cur, b)
        acc += mod
        cur = div
    return acc

def g(b):
    if b > n: return n
    return sum(divmod(n,b))

def f():
    if n == s:
        return (n + 1)
    if n < s:
        return -1
    rt = math.ceil(math.sqrt(n))
    for b in range(2, rt + 1):
        if c(b) == s: return b
    for p in range(rt, 0, -1):
        q = s - p
        x = n - q
        b = x // p
        if g(b) == s:
            return b
    return -1
    
print(f())