from collections import Counter
from itertools import accumulate
N, M, *A = map(int, open(0).read().split())
B = [b%M for b in accumulate(A)]
C = Counter(B)
ans = C[0]
ans += sum(C[k]*(C[k]-1)//2 for k in C.keys())
print(ans)