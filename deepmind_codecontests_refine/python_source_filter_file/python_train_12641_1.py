tr = [[1, 0], [0, 1], [-1, 0], [0, -1]]
tc = [[0, 1], [-1, 0], [0, -1], [1, 0]]
n, m, x, y, z, p = map(int, input().split())
y %= 2
d = (x + z if y else -z) % 4
r0, r1, c0, c1 = tr[d][0], tr[d][1], tc[d][0] * (-1) ** y, tc[d][1] * (-1) ** y
for pi in range(p):
    i, j = map(int, input().split())
    vi = [0, i, n - i + 1][r0] + [0, j, m - j + 1][r1]
    vj = [0, i, n - i + 1][c0] + [0, j, m - j + 1][c1]
    print(vi, vj)