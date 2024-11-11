class Bit:
    def __init__(self, n):
        self.size = n
        self.tree = [0] * (n + 1)
    def sum(self, i):
        s = 0
        while i > 0:
            s += self.tree[i]
            i -= i & -i
        return s
    def add(self, i, x):
        while i <= self.size:
            self.tree[i] += x
            i += i & -i
import sys
input = sys.stdin.readline
mod = 998244353

def sub(a, b):
    return (a % mod + mod - b % mod) % mod


def main():
    n, = list(map(int, input().split()))
    t = 1
    dd = [t]
    for _ in range(n):
        t=2*t%mod
        dd.append(t)

    xs, ys = [], []
    for _ in range(n):
        x, y = list(map(int, input().split()))
        xs.append(x)
        ys.append(y)

    ini = sorted(list(range(n)), key=lambda x:xs[x])
    for i, yi in enumerate(sorted(list(range(n)), key=lambda x:ys[x])):
        ys[yi] = i 
    nys = [ys[i] for i in ini]

    ss1 = Bit(n)
    r = 0
    for i, y in enumerate(nys):
        ss1.add(y+1, 1)
        d = ss1.sum(y)
        c = i - d
        b = (n-1) - y - c
        a = (n-1) - b - c - d
        r = (r + sub(dd[b+c] + dd[c+d] + dd[d+a] + dd[a+b],
                dd[a] + dd[b] + dd[c] + dd[d])) % mod

    print(sub((dd[n] * n) % mod, (r+n)%mod))
main()
