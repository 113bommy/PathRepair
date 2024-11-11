h, w = map(int, input().split())
s = [[*map(lambda c:c == ".", input())] for _ in [0] * h]
for i in "LRUD":
    exec(i + "= [[0] * w for _ in [0] * h]")
for i in range(h):
    for j in range(w):
        L[i][j]    = L[i][j-1] + 1 if s[i][j]    else 0
        R[i][-j-1] = R[i][-j]  + 1 if s[i][-j-1] else 0
for j in range(w):
    for i in range(h):
        U[i][j]    = U[i-1][j] + 1 if s[i][j]    else 0
        D[-i-1][j] = D[-i][j]  + 1 if s[-i-1][j] else 0
print(max(L[i][j] + R[i][j] + U[i][j] + D[i][j] - 3 for i in range(h) for j in range(w)))