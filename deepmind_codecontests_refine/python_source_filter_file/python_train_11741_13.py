N = int(input())
A = list(map(int, input().split()))

MAX = [1] * (N+1)
ans = [0] * (N+1)
INF = 10**15

if N == 0 and A[0] == 0:
    print(-1)
    exit()

for i in range(1, N+1):
    MAX[i] = min((MAX[i-1] - A[i-1]) * 2, INF)
    if MAX[i] < A[i]:
        print(-1)
        exit()

ans[N] = A[N]

for i in reversed(range(N)):
    ans[i] = min(ans[i+1]+A[i], MAX[i])

print(sum(ans))