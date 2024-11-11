import itertools
from math import sqrt
def chunk(a):
    i = 0
    res = []
    while i < len(a):
        res.append(a[i])
        while i != len(a) - 1 and a[i + 1] == a[i] + 1:
            i += 1
        res.append(a[i] + 1)
        i += 1
    return res

def augment(g, src, dest):
    o = [None] * len(g)
    q = [(src, src)]
    while q:
        w = q.pop()
        if o[w[0]] is None:
            o[w[0]] = w[1]
            for s in g[w[0]]:
                if o[s] is None:
                    q.append((s, w[0]))
    if not o[dest]:
        return False
    i = dest
    while i != src:
        g[o[i]].discard(i)
        g[i].add(o[i])
        i = o[i]
    return True

def match(a):
    l = {}
    c = 0
    matches = 0
    for i, j in a:
        if i not in l:
            l[i] = c
            c += 1
        if j not in l:
            l[j] = c
            c += 1
    L = {v: k for k, v in l.items()}
    g = [set() for i in range(len(l) + 2)]
    src = len(l)
    dest = src + 1
    for i, j in a:
        g[src].add(l[i])
        g[l[i]].add(l[j])
        g[l[j]].add(dest)
    while augment(g, src, dest):
        matches += 1
    return matches

def prime(n):
    for i in range(2, min(n, int(sqrt(n) + 7))):
        if n % i == 0:
            return False
    return n > 1

def pairs(b):
    c = []
    for i in b:
        for j in b:
            if i % 2 == 0 and j % 2 == 1 and prime(abs(i - j)):
                c.append((i, j))
    return c

n = int(input())
a = list(map(int, input().split()))
b = chunk(a)
r = match(pairs(b))
e = len(list(filter(lambda x: x % 2 == 0, b)))
o = len(b) - e
print(int(r + 2 * ((e - r) // 2 + (o - r) // 2) + 3 * ((e - r) % 2)))