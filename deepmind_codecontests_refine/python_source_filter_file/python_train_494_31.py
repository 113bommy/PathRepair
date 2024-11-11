# coding: utf-8
import sys,pprint, math
from fractions import Fraction
from collections import defaultdict

MOD = 1000000007
N = int(input())
params =[]
hatemasks = []
tilts = defaultdict(lambda: [0,0])
zerozero = 0
zerodiv = 0
for i in range(N):
    (ai, bi) = map(int,input().split())
    if ai == 0 and bi == 0:
        zerozero += 1
        continue
    elif (ai <= 0) or (ai == 0 and bi < 0):
        ai *= -1
        bi *= -1
    g = math.gcd(ai,bi)
    ai = ai // g
    bi = bi // g
    if bi > 0:
        tilts[(ai,bi)][0] += 1
    else:
        tilts[(-bi,ai)][1] += 1
print(tilts,file=sys.stderr)

#sys.exit()
ans = 1
for(v1,v2) in tilts.values():
    ans *= 1 +pow(2,v1,MOD)-1 +pow(2,v2,MOD)-1
    ans %= MOD
ans = (ans+zerozero-1) % MOD
print(ans)