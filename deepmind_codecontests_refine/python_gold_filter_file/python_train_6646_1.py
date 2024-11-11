N, M = map(int, input().split())
A = [[0 for i in range(M)] for j in range(N)]

for i in range(N):
    A[i] = list(map(int, input().split()))

ans = float('inf')
for i in range(M):
    rank = [0] * M
    for j in range(N):
        rank[A[j][0] - 1] += 1
    ans = min(ans, max(rank))
    remove_idx = rank.index(max(rank)) + 1
    for j in range(N):
        A[j].remove(remove_idx)
print(ans)
