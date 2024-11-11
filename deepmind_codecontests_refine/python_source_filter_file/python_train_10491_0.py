N, K = map(int, input().split())
A = list(map(int, input().split()))
MOD = 10 ** 9 + 7

X = sorted([a for a in A if a > 0])
Y = sorted([a for a in A if a < 0], key=lambda x: abs(x))

if 2 * (min(K, len(Y)) // 2) + len(X) >= K:
    ans = 1
    if K % 2 == 1:
        ans *= X.pop()
        K -= 1

    XX = [(x1 * x2) for x1, x2 in zip(*[iter(X[::-1])] * 2)]
    YY = [(y1 * y2) for y1, y2 in zip(*[iter(Y[::-1])] * 2)]
    ZZ = sorted(XX + YY)

    for i in range(K // 2):
        ans *= ZZ.pop()
        ans %= MOD

    print(ans)

else:
    ans = 1
    Z = sorted(X + Y, key=lambda x: abs(x), reverse=True)
    for i in range(K):
        ans *= Z.pop()
        ans %= MOD
    print(ans)
