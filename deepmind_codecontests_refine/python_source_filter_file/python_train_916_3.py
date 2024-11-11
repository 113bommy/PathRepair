n = int(input())
A = list(map(int,input().split()))
from collections import Counter
from itertools import accumulate
D = Counter(list(accumulate(A)))
res = D[0]
print(D)
for v in D.values():
    res += v*(v-1)//2
print(res)