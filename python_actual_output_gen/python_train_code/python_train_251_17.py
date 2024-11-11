
N, M = map(int, input().split())
X = [list(map(int, input().split())) for _ in range(M)]

lb = 10 ** (N - 1) if N > 1 else 0
for n in range(lb, 10 ** N):
    flag = True
    for s, c in X:
        flag &= n // (10 ** (3 - s)) % 10 == c

    if flag:
        print(n)
        break
else:
    print(-1)
