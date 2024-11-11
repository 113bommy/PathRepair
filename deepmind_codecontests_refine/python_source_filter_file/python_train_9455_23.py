N = int(input())
A = sorted(list(map(int, input().split())))

import math

n = A[-1]
P_dif_A = sorted([[abs(a-n), a] for a in A])
r = P_dif_A[1][1]

print(n, r)