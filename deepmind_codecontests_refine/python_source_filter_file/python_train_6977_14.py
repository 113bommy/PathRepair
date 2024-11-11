_, *lines = open(0).readlines()
H = [[[0]*10 for i in range(3)] for j in range(4)]
for line in lines:
    b, f, r, v = map(int, line.split())
    H[b-1][f-1][r-1] += v
for i, h in enumerate(H):
    if i:
        print("#"*20)
    for r in h:
        print(*r)
