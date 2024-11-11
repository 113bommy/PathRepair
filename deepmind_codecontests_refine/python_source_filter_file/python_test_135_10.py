import sys, array, bisect, collections, heapq, itertools, math, functools
sys.setrecursionlimit(100000)

def _r(): return sys.stdin.buffer.readline()
def rs(): return _r().decode('ascii').strip()
def rn(): return int(_r())
def rnt(): return tuple(map(int, _r().split()))
def rnl(): return list(rnt())
def rna(): return array.array('q', rnt())
def pnl(l): print(' '.join(map(str, l)))

class MaxHeapObj:
    def __init__(self, val): self.val = val
    def __lt__(self, other): return self.val > other.val
    def __eq__(self, other): return self.val == other.val
    def __str__(self): return str(self.val)

def solve(n, k, a):
    a = sorted(a)
    sol = sum(a[:n-2*k])
    f = {}
    for x in a[-2*k:]:
        f[x] = f.get(x, 0) + 1
    q = [MaxHeapObj(cnt) for cnt in f.values()]
    heapq.heapify(q)
    while q:
        cnt1 = heapq.heappop(q).val
        if q:
            cnt2 = heapq.heappop(q).val
            if cnt1 > 1:
                heapq.heappush(q, MaxHeapObj(cnt1-1))
            if cnt2 > 1:
                heapq.heappush(q, MaxHeapObj(cnt2-1))
        else:
            sol += 1
            if cnt1 > 2:
                heapq.heappush(q, MaxHeapObj(cnt1-2))
    return sol

for _ in range(rn()):
    n, k = rnt()
    a = rnl()
    print(solve(n, k, a))