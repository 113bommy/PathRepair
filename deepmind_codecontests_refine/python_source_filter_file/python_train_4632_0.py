from statistics import median

N, K, P, X, Y = map(int, input().split())
A = list(map(int, input().split()))

lt = 0

for i in range(K):
    if A[i] < Y:
        lt += 1

ans = [1] * min(N // 2 - lt, N - K)
while len(ans) < N - K:
    ans.append(Y)

if sum(ans+A) <= X and median(ans+A) == Y:
    print(' '.join(map(str, ans)))
else:
    print('-1')


