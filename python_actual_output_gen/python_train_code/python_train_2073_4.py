N,M,Q = list(map(int, input().split()))
C = []
for i in range(Q):
    C.append(list(map(int, input().split())))
    
import itertools
res = 0
ls=list(range(1,M+1))
for a in itertools.combinations_with_replacement(ls, N):
    p = 0
    for c in C:
        if a[c[1]]-a[c[0]]==c[2]:
            p += c[3]
        res = max(res,p)
print(res)