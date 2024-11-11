from itertools import combinations

N, K = map(int, input().split())
XY = [tuple(map(int, input().split())) for _ in range(N)]

ans = 10**20
for rect in combinations(XY, r=min(K, 4)):
    X = [x for x, _ in rect]
    Y = [y for _, y in rect]

    miX, mxX = min(X), max(X)
    miY, mxY = min(Y), max(Y)

    cnt = len([x for x, y in XY if miY <= y <= mxY and miX <= x <= mxX])
    if cnt >= K:
        ans = min(ans, (mxX - miX) * (mxY - miY))
print(ans)
