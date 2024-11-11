import bisect
N, K = map(int, input().split())
A = [int(i) for i in input().split()]

SA = [0]
for i in range(N):
    SA.append(SA[-1]+A[i])

C = []
for i in range(N):
    for j in range(i+1, N+1):
        C.append(SA[j]-SA[i])
C.sort()


ans = 0
for i in range(31, -1, -1):
    B = 1 << i
    ind = bisect.bisect_left(C, B)
    if len(C)-ind >= K:
        ans += B
        C = C[ind:]
    for j in range(len(C)):
        C[j] &= B-1
    C.sort()
    # print(i, B, C)
print(ans)
