N = int(input())
A = list(map(int, input().split()))
B = list(map(int, input().split()))

ans = 0
for i in range(N):
    ans += min(A[i] + A[i+1], B[i])
    A[i+1] -= min(max(A[i] - B[i], 0), A[i+1])

print(ans)
