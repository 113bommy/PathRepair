H, W = map(int, input().split())
S = [input() for _ in range(H)]

L = [[0] * W for _ in range(H)]
R = [[0] * W for _ in range(H)]
U = [[0] * W for _ in range(H)]
D = [[0] * W for _ in range(H)]

for h in range(H):
    for w in range(W):
        if S[h][w] == ".":
            L[h][w] = L[h][w-1] + 1
            U[h][w] = U[h-1][w] + 1
        if S[h][W-w-1] == ".":
            R[h][-w-1] = R[h][-w] + 1
        if S[H-h-1][w] == ".":
            D[-h-1][w] = D[-h][w] + 1
ans = 0
for h in range(H):
    for w in range(W):
        ans = max(ans, R[h][w] + L[h][w] + U[h][w] + D[h][w] - 3)
print(ans)
