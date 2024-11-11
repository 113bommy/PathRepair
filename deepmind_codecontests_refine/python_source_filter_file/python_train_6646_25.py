import collections

N, M = map(int, input().split())
A = [list(map(int, input().split())) for i in range(N)]
ans = M  # １種類だけ開催

s = set()
for _ in range(M):
    count = [0]*M
    for i in range(N):
        for x in A[i]:
            if x in s:
                continue
            else:
                count[x-1] += 1
                break
    ans = min(ans, max(count))
    idx = count.index(max(count))
    s.add(idx + 1)

print(ans)
