from collections import Counter
from math import factorial
N, A, B = map(int, input().split())
V = sorted(list(map(int, input().split())), reverse=True)

MAX_AVE = sum(V[:A]) / A
C = Counter(V)


def nCr(n, r):
    return factorial(n) / (factorial(r) * factorial(n - r))


Ath_V = V[A - 1]
if Ath_V == max(V):
    ans = 0
    for r in range(A, min(B + 1, C[Ath_V] + 1)):
        ans += nCr(C[Ath_V], r)
    print(MAX_AVE)
    print(ans)

else:
    print(MAX_AVE)
    for i, v in enumerate(V):
        if v == Ath_V:
            used = i
            break
    print(nCr(C[Ath_V], A - used))
