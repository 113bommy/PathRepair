N = int(input())
X = []
Y = []
for _ in range(N):
    x, y = map(int, input().split())
    X.append(x)
    Y.append(y)

# (x + y) % 2 が全部同じじゃなかったらどう頑張ってもむり
if len(set([(x + y) % 2 for x, y in zip(X, Y)])) != 1:
    print(-1)
    exit()


def directions_str(fx, fy, tx, ty, arm):
    if fx == tx and fy == ty:
        return ''
    if abs(fx - arm - tx) + abs(fy - ty) < arm:
        return 'L' + directions_str(fx=fx - arm, fy=fy, tx=tx, ty=ty, arm=arm // 2)
    if abs(fx + arm - tx) + abs(fy - ty) < arm:
        return 'R' + directions_str(fx=fx + arm, fy=fy, tx=tx, ty=ty, arm=arm // 2)
    if abs(fx - tx) + abs(fy - arm - ty) < arm:
        return 'D' + directions_str(fx=fx, fy=fy - arm, tx=tx, ty=ty, arm=arm // 2)
    if abs(fx - tx) + abs(fy + arm - ty) < arm:
        return 'U' + directions_str(fx=fx, fy=fy + arm, tx=tx, ty=ty, arm=arm // 2)


# 全部 (x + y) % 2 == 1 なら、2^n, 2^(n-1), ..., 2, 1 って腕を作れば (x+y) <= 2^(n+1)-1 まではどこでも行ける。
# 全部 (x + y) % 2 == 0 なら、上記から 1 だけ伸ばせばどこでも行ける。
arms = []
for n in range(39):
    arms.append(2 ** n)
    if 2 ** n > 10 ** 9:
        break
arms.sort(reverse=True)

if (X[0] + Y[0]) % 2 == 1:
    print(len(arms))
    print(' '.join(map(str, arms)))
    for x, y in zip(X, Y):
        print(directions_str(fx=0, fy=0, tx=x, ty=y, arm=arms[0]))
else:
    arms.append(1)
    print(len(arms))
    print(' '.join(map(str, arms)))
    for x, y in zip(X, Y):
        print(directions_str(fx=0, fy=1, tx=x, ty=y, arm=arms[0]) + 'D')
