H, W, M = map(int,input().split())
R = [0] * H
C = [0] * W

L = []

for _ in range(M):
    h, w = map(int,input().split())
    R[h-1] += 1
    C[w-1] += 1
    L.append([h-1, w-1])

r = max(R)
c = max(C)

print(r + c - (R.count(r) * C.count(c) == sum(R[h] + C[w] == r + c for h, w in L))