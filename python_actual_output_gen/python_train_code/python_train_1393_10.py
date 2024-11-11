import math as mt
N = int(input())
A = [int(input()) for i in range(N)]
A.sort()
#print(A)
S = 0
P2 = mt.floor(N/2 - 1)
if N % 2 == 0:
    for i in range(0,P2,1):
        S += 2 * (A[N-i-1] - A[i])
    S += A[P2+1] - A[P2]
    print(S)
elif N % 2 == 1:
    for i in range(0,P2,1):
        S += 2 * (A[N-i-1] - A[i])
    S1 = A[N-P2-1] + A[N-P2] - 2 * A[P2]
    S2 = 2 * A[N-1-P2] - A[P2] - A[P2+1]
    if S1 >= S2:
        print(S1)
    else:
        print(S2)
