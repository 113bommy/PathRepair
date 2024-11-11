H, W, M = map(int, input().split())
h = [0 for i in range(H)]
w = [0 for i in range(W)]
DP = []
for i in range(M):
    hh, ww = map(int, input().split())
    h[hh - 1] += 1
    w[ww - 1] += 1
    DP.append((hh - 1, ww - 1))

hhh = max(h)
www = max(w)
hhhh = [i for i, x in enumerate(h) if x == hhh]
wwww = [i for i, x in enumerate(w) if x == www]
check = 0

for i in hhhh:
    for j in wwww:
        if (i, j) not in DP:
            print(hhh + www)
            exit()
print(hhh + www - 1)
