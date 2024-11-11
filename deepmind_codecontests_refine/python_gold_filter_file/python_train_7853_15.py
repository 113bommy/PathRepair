# from sys import stdout
from bisect import bisect_left as bs
from math import log as lg
from math import factorial as f
log = lambda *x: print(*x)
def cin(*fn, def_fn=str):
	i,r = 0,[]
	if fn: def_fn=fn[0]
	for c in input().split(' '):
		r+=[(fn[i] if len(fn)>i else def_fn) (c)]
		i+=1
	return r
####################################################


n, = cin(int)
b = sorted(cin(int))
log(b[-1]-b[0], b.count(b[0])*b.count(b[-1]) if b[0]!=b[-1] else int((b.count(b[0])*(b.count(b[0])-1)/2)))
