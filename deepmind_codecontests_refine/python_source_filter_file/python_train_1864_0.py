from itertools import permutations as P
import sys
r=sys.stdin.readline
for e in iter(r,'0\n'):
 n,k=int(e),int(r())
 C=[r()for _ in[0]*n]
 print(len(set(''.join(s)for s in P(C,k))))
