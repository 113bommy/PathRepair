H, W, K = [int(_) for _ in input().split()]
S = [list(input()) for _ in range(H)]
for h in range(H):
    f = None
    for w in range(W):
        if S[h][w] == '#':
            S[h][w] = W * h + w
            if f is None:
                for w2 in range(w):
                    S[h][w2] = S[h][w]
            f = S[h][w]
        elif f is not None:
            S[h][w] = f
f = None
for h in range(H):
    if S[h][0] == '.':
        if f:
            S[h] = S[h - 1][:]
    elif f is None:
        f = True
        for h2 in range(h):
            S[h2] = S[h][:]
v_i = {v: i + 1 for i, v in enumerate(set(sum(S, [])))}
print('\n'.join([' '.join([str(v_i[v]) for v in a]) for a in S]))
