from itertools import *
n=range(104730);a=list(n)
for i in range(2,310):a[i*2::i]=[0]*len(a[i*2::i])
p=list(compress(n,a))
for e in iter(input,'0'):print(sum(p[:int(e)+1])-1)
