mod=998244353
preF=[1]*200005
from collections import Counter
from math import factorial as fac
for i in range(1,len(preF)):
    preF[i]=(preF[i-1]*i)%mod
for _ in range(int(input())):
    n=int(input())
    a=[int(i) for i in input().split()]
    c=Counter(a)
    m=max(a)
    a=sorted(list(set(a)))
    f=preF[n]
    if c[a[-1]]>1:print(f%mod);continue
    if a[-1]-1!=a[-2]:print(0);continue
    print(c[a[-2]]*(f//(c[a[-2]]+1))%mod)
