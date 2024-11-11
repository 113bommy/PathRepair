import bisect
import sys
import math
input = sys.stdin.readline
N, M, V, P = map(int, input().split())
A = list(map(int, input().split()))

A.sort()

K = A[-P]
R = bisect.bisect_left(A, K)
RL = bisect.bisect_right(A, K)
L = bisect.bisect_left(A, K - M)
ans = N - R
table = [0]*N
for i in range(L, R):
    table[i] = K - A[i]
table2 = [0]*N
for i in range(L, R):
    table2[i] = table2[i-1] + table[i]

X = table2[R-1]

for i in range(L, R):
    # print("i:", i, P+i, V > P+i)
    if V > P+i:
        v = V - (P+i)
        D = N-P - i
        # print(A[i], v*M, -(v*M - (X - table2[i])))
        if (-((-(v*M - (X - table2[i]))) // D)) + K <= A[i]+M:
            ans += 1

    else:
        ans += 1

print(ans)
