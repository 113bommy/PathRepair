import bisect

N = int(input())
A = sorted([int(i) for i in input().split()])

zp = bisect.bisect_left(A, 0)
ans = []

M = A[0]
for i in range(max(zp, 1), N-1):
    ans.append((M, A[i]))
    M -= A[i]

ans.append((A[N-1], M))
M = A[N-1]-M

for i in range(1, min(zp, N-2)):
    ans.append((M, A[i]))
    M -= A[i]


print(M)
for t in ans:
    print(*t)
