import sys

readline = sys.stdin.buffer.readline
read = sys.stdin.read
ns = lambda: readline().rstrip()
ni = lambda: int(readline().rstrip())
nm = lambda: map(int, readline().split())
nl = lambda: list(map(int, readline().split()))
prn = lambda x: print(*x, sep='\n')

def solve():
    s = list(ns())
    o = list()
    e = list()
    s.sort()
    for x in s:
        if x & 1:
            o.append(x)
        else:
            e.append(x)
    for g in (o+e, e+o):
        for x, y in zip(g, g[1:]):
            if abs(x - y) in (1, 25):
                break
        else:
            print(''.join(map(chr, g)))
            return
    print('No answer')
    return

# solve()

T = ni()
for _ in range(T):
    solve()
