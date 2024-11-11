from itertools import accumulate
from collections import Counter
N,*A = map(int, open('0').read().split())
B = accumulate(A)
c = Counter(B)
ans = c[0]+sum(v*(v-1)//2 for v in c.values())
print(ans)