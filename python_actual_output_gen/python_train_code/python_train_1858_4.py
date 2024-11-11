nB, nG = map(int, input().split())
b, g = [False] * nB, [False] * nG
for i in list(map(int, input().split()))[1:]:
    b[i] = True
for i in list(map(int, input().split()))[1:]:
    g[i] = True
for i in range(1000):
    b[i % nB] = g[i % nG] = b[i % nB] | g[i % nG]
print('Yes' if False not in b + g else 'No')