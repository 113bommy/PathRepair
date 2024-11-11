N, M = map(int, input().split())
A = list(map(int, input().split()))
A.sort()
ans = 0
for i in range(M):
    if A[i] < 0:
        ans -= A[i]
print(ans)
