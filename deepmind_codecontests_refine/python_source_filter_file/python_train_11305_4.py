import sys
input = sys.stdin.readline

'''

'''

def pprint(mat):
    for r in mat:
        print("".join(r))

n, k = map(int, input().split())
mat = [["0"] * n for _ in range(n)]
N = n

if n**2 < k:
    print(-1)
    sys.exit()
else:
    num_cells = 2*n-1
    rc = 0
    while num_cells > 0 and num_cells <= k:
        for x in range(rc, N):
            mat[x][rc] = "1"
            mat[rc][x] = "1"

        rc += 1
        k -= num_cells
        n-= 1
        num_cells = 2*n-1

    if k == 0:
        pprint(mat)
        sys.exit()
    elif k % 2 == 0:
        mat[rc+1][rc+1] = "1"
        k -= 1

for x in range(rc, rc + k//2+1):
    mat[x][rc] = "1"
    mat[rc][x] = "1"

pprint(mat)