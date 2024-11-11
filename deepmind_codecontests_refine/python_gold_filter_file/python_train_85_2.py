N, M = map(int, input().split())
ab = [list(map(int, input().split())) for _ in range(N)]
cd = [list(map(int, input().split())) for _ in range(M)]

for i in range(N):
    d = []
    for j in range(M):
        d.append(abs(ab[i][0] - cd[j][0]) + abs(ab[i][1] - cd[j][1]))
    print(d.index(min(d)) + 1)