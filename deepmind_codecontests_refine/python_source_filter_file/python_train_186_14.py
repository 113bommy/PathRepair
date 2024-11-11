from itertools import*
N,K,Q,*A=map(int,open(0).read().split())
s=sorted
print(min((s(sum((v[:1-K or-1]for v in(k*s(v)for k,v in groupby(A,lambda a:a>=Y))),[]))[Q-1:]+[2e9])[0]-Y for Y in A))