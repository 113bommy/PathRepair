import itertools
H, W, M = map(int, input().split())
Bh = [0]*(H+1)
Bw = [0]*(W+1)
OD = []

for _ in range(M):
    h, w = map(int, input().split())
    Bh[h] += 1
    Bw[w] += 1
    OD.append((h, w))

M1 = max(Bh)
M2 = max(Bw)
l1 = [i for i, x in enumerate(Bh) if x == M1]
l2 = [j for j, x in enumerate(Bw) if x == M2]
for i, j in itertools.product(l1, l2):
    if (i, j) not in OD:
        break
else:
    print(M1+M2-1)
    exit()
print(M1+M2)
