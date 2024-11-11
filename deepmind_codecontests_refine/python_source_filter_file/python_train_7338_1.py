from sys import stdin,stdout
input = stdin.readline
from itertools import tee, chain

n,m = map(int,input().split())
i1,i2,i3 = tee((c == '.' for c in input()),3)

res = sum(map(all,zip(chain([False],i1),chain(i1,[False]))))
s = bytearray(chain([False],i3,[False]))

def calc(s,res):
    for i in range(m):
        x,c = input().split()
        x = int(x)
        nc = c == '.'
        if s[x] != nc:
            diff = s[x-1] + s[x+1]
            res += (-diff,diff) [nc]
            s[x] = nc
        yield str(res)

stdout.write('\n'.join(calc(s,res)))