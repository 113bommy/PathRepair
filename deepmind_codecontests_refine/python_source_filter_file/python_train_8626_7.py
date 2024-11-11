import bisect,sys
from itertools import *
n=range(50001);a=list(n);a[1]=0
for i in range(2,224):a[i*2::i]=[0]*len(a[i*2::i])
p=list(compress(n,a))
for x in map(int,sys.stdin):
 if x:print(len(1 for d in p[:bisect.bisect(p,x//2)]if a[x-d]))
