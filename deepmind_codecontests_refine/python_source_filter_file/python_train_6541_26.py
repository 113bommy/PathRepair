from itertools import accumulate
N, C = map(int, input().split())
TimeTable = [[0] * (10 ** 5 + 1) for i in range(C + 1)]
for i in range(N):
    s, t, c = map(int, input().split())
    TimeTable[c][s] += 1
    TimeTable[c][t + 1] -= 1

for c in range(C + 1):
    TimeTable[c] = list(accumulate(TimeTable[c]))


ans = 0
for i in range(10 ** 5 + 1):
    cnt = 0
    for c in range(C + 1):
        cnt += min(TimeTable[c][i], 1)
    ans = max(ans, cnt)

print(ans)
