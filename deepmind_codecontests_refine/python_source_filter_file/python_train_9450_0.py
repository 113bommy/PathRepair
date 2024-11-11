N, K = map(int, input().split())
A = list(map(lambda a: int(a) - 1, input().split()))

now = 0
for d in range(N):
    if ((1 << d) & K) > 0:
        now = A[now]
    A = [A[a] for a in A]
print(now + 1)
