from collections import Counter
M=10**7
_,*l=map(int,open(0).read().split())
d=[1]*(M)
C=Counter(sorted(l)
s=0
for a,b in C.items():
    if b != 1:d[a]=0
    elif d[a]:s+=1
    for j in range(a,M,a):d[j]=0
print(s)
