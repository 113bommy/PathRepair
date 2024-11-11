import sys

f_i = sys.stdin

n, q = map(int, f_i.readline().split())

S = set([frozenset([i]) for i in range(n)])

def unite(sets, v1, v2):
    s1 = None
    s2 = None
    for s in sets:
        if v1 in s and v2 in s:
            return None
        elif v1 in s:
            s1 = s
        elif v2 in s:
            s2 = s
        if s1 and s2:
            break
    sets.discard(s1)
    sets.discard(s2)
    s3 = s1.union(s2)
    sets.update(s3)

def same(sets, v1, v2):
    for s in sets:
        if v1 in s and v2 in s:
            print(1)
            break
        elif v1 in s or v2 in s:
            print(0)
            break

for l in f_i:
    com, x, y = map(int, l.split())
    if com == 0:
        unite(S, x, y)
    else:
        same(S, x, y)