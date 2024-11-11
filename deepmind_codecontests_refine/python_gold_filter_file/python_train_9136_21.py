import sys

readline = sys.stdin.readline
readall = sys.stdin.read
ns = lambda: readline().rstrip()
ni = lambda: int(readline().rstrip())
nm = lambda: map(int, readline().split())
nl = lambda: list(map(int, readline().split()))
prn = lambda x: print(*x, sep='\n')

def solve():
    n = ni()
    f, s, *a = nm()
    x = 0
    for c in a: x ^= c
    if (f + s - x) % 2 or ((f + s - x) // 2) & x:
        print(-1)
        return
    y = (f + s - x) // 2
    for i in range(40, -1, -1):
        if x & (1 << i) and y | (1 << i) <= f:
            y |= 1 << i
    print(f - y if f >= y > 0 else -1)
    return

solve()
