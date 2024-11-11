from itertools import product
h, w = map(int, input().split())
S = [input() for _ in range(h)]
L = [[0]*w for _ in range(h)]
R = [[0]*w for _ in range(h)]
U = [[0]*w for _ in range(h)]
D = [[0]*w for _ in range(h)]
for i, j in product(range(h),range(w)):
    l = S[i][j]
    r = S[i][w-1-j]
    u = S[i][j]
    d = S[h-1-i][j]
    if l == ".": L[i][j] = L[i][max(0, j-1)]+1
    if r == ".": R[i][w-1-j] = R[i][min(w-1, w-j)]+1
    if u == ".": U[i][j] = U[max(0, i-1)][j]+1
    if d == ".": D[h-1-i][j] = D[min(h-1, h-i)][j]+1
A = [L[i][j]+R[i][j]+U[i][j]+D[i][j]-3 for i, j in product(range(h), range(w))]
print(max(A))