import itertools
n=10001;a=list(range(n));a[:2]=0,0
for i in range(2,97):
 a[i*2::i]=[0]*len(a[i*2::i])
p=list(itertools.compress(range(n),a))
for e in iter(input,'0'):print(sum(p[:int(e)]))
