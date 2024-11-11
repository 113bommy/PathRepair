N = int(input())
A = [int(input()) for _ in range(N)]
ans = 0
for i in range(N):
    ans += A[i] // 2
    A[i] %= 2
    if N == 1 and i < N-1 and A[i+1] > 0:
        A[i+1] -= 1
        ans += 1
print(ans)