N=int(input())
S=input()
MOD=10**9+7
x=dict()
for s in S:
    x[s]=s.get(s,0)+1
retval=1
for c in x:
    retval*=(x[c]+1)
print((retval-1)%MOD)