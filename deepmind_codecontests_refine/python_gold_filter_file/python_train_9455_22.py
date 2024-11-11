N = int(input())
A = sorted(list(map(int, input().split())))

import math

n = A.pop()
P_dif_A = sorted([[abs(a-n/2), a] for a in A])
r = P_dif_A[0][1]

print(n, r)