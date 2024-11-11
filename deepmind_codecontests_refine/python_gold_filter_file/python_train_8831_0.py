H, W = map(int, input().split())
S = [input() for _ in range(H)]

ans = max(H, W)

f = [1] * W
for i in range(1, H):
    f = [(f[j]+1) if (S[i-1][j:j+2] + S[i][j:j+2]).count('#') in [0,2,4] else 1 for j in range(W-1)] + [0]
    stk = []
    for j, v in enumerate(f):
        while len(stk) > 0 and f[stk[-1]] >= v:
            ans = max(ans, f[stk.pop()] * (j - (stk[-1] if len(stk) > 0 else -1)))
        stk.append(j)

print(ans)
