import bisect
N = int(input())
A = [int(input()) for i in range(N)]


S = []
for i in range(N):
    posi = bisect.bisect_left(S,A[i])
    if posi == 0:
        S.insert(0,A[i])
    else:
        S[posi-1] = A[i]

print(len(S))