import sys
def rr(): return sys.stdin.readline().rstrip()
def rri(): return int(rr())
def rrl(): return list(map(int, rr().split()))
def rrt(): return tuple(map(int, rr().split()))
def rrle(): return (line.rstrip() for line in sys.stdin.readlines())
def rrtl(): return [tuple(map(int, l.split())) for l in rrle()]
from collections import defaultdict
def mus(d=lambda: 0): return defaultdict(lambda: defaultdict(d))
def dd0(d=lambda: 0): return defaultdict(d)
def ms(x, y, d=0): return [[0]*y for i in range(x)]
def ar(x, d=0): return [d]*x
def ppm(m, n=0, x=0, y=0): print("\n".join(("\t".join((str(m[j][i]) for j in range(y or n))) for i in range(x or n))))
def ppa(a, n): print("\t".join(map(str, a[0:n])))
def ppl(a=0, x=[1]): x[0]=a or (x[0]+1); print("-"+"- -"*14+"-# "+str(x[0]-2)+" #-"+"- -"*14+"-")
def fltn(a): (i for sub in a for i in sub)
def yn(x): return "YES" if x else "NO"
from itertools import accumulate
from itertools import groupby
from itertools import permutations
def grp(x, key=None): return ((i, sum(1 for _ in g)) for i, g in groupby(x, key=key))
import math
def rnar(): return (*rrl(), rrl())
def rn(): return (*rrl(),)
def dpp(a, b=""): print("#| {} |#:^ {} ^:".format(a, b))
MOD17 = 10**9 + 7

def read():
    return (rri(),)

def solve(n):
    if n == 1:
        ans = -1
    else:
        ans = "2" + "3"*(n-1)
    return ans

if __name__ == "__main__":
    test_count = rri()
    #test_count = 1
    for _ in range(test_count):
        input_data = read()
        result = solve(*input_data)
        print(result)
