# coding:utf-8

INF = float('inf')


def inpl(): return list(map(int, input().split()))


N, x = inpl()
A = inpl()

min_index = A.index(min(A))
B = A[min_index:] + A[:min_index]

cost = [B[i] for i in range(N)]

ans = INF
for magic in range(N):
    for i in range(N):
        if i - magic >= 0:
            cost[i] = min(cost[i], B[i - magic])

    ans = min(ans, sum(cost) + x * magic)

print(ans)
