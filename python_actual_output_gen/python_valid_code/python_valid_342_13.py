N, C, K = map(int, input().split())
T = []
for i in range(N):
    T += [int(input())]

sortT = sorted(T)
pre_ti = sortT[0]
ans = 1
c = 0
for ti in sortT:
    c += 1
    if ti - pre_ti < K and c <= C:
        continue
    c = 1
    ans += 1
    pre_ti = ti

print(ans)
