import math
from collections import Counter


N = int(input())
A = list(map(int, input().split()))
A.sort()

n_pears = 0
counter = Counter(A)

for i in reversed(range(0, len(A))):
    if counter[A[i]] <= 0:
        continue
    counter[A[i]] -= 1
    Aj = 2 * int(math.log2(A[i]) + 1) - A[i]
    if counter[Aj] > 0:
        n_pears += 1
        counter[Aj] -= 1

print(n_pears)