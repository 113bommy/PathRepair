import sys
def rr(): return sys.stdin.readline().rstrip()
#def pp(*args, end="\n"): sys.stdout.write(" ".join(map(str, args))+end)
rp = print
def print(*args, **kwargs): rp("DBG:# ", *args, **kwargs, file=sys.stderr)
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
def cpc(arr): return zip(arr, arr[1:])
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
    #return rnar()
    return (*rrl(),)

def solve(a, b, n):
    if a == 0 and b == 0:
        return "0"
    elif a == 0 and b != 0:
        return "No solution"
    elif a != 0 and b == 1:
        return "0"

    f = (b/a)
    s = (1/n)
    x = (-(f < 0)+(f > 0)) *(abs(b/a)**(1/n))
    try:
        x = round(x)
    except Exception:
        x = 0

    if a*(x**n) == b:
        return x
    else:
        return "No solution"
    return ans

if __name__ == "__main__":
    #test_count = rri()
    test_count = 1
    for _ in range(test_count):
        input_data = read()
        result = solve(*input_data)
        rp(result)
