from itertools import*
N,K,Q,*A=map(int,open(0).read().split())
l=len
s=sorted
a=1e9
for Y in A:
	C=s(sum((v[:l(v)-K+1] for v in(s(v)for k,v in groupby(A,lambda a:a>=Y)if k)if l(v)>=K),[]))
	if l(C)>=Q:a=min(a,C[Q-1]-Y)
print(a)