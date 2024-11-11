import sys
def query(x1, y1, x2, y2):
    print("?", x1, y1, x2, y2)
    sys.stdout.flush()
    odp = int(input())
    return odp
n = int(input())
mat = [[2 for c in range(n + 1)] for r in range(n + 1)]
mat[1][1] = 1
mat[n][n] = 0
for d in range(1, n - 1):
    odp = query(d, d, d + 1, d + 1)
    if odp:
        mat[d + 1][d + 1] = mat[d][d]
    else:
        mat[d + 1][d + 1] = 1 - mat[d][d]
d = 1
while True:
    if mat[d][d] != mat[d + 2][d + 2]:
        break
    d += 2
pom1 = query(d, d, d + 2, d)
pom2 = query(d + 1, d, d + 2, d + 1)
if pom1 == 0 and pom2 == 0:
    pom3 = query(d, d, d + 2, d + 1)
    if pom3 == 1:
        mat[d + 1][d] = 1 - mat[d][d]
        mat[d + 2][d] = 1 - mat[d][d]
        mat[d + 2][d + 1] = mat[d][d]
    else:
        mat[d + 1][d] = mat[d][d]
        mat[d + 2][d] = 1 - mat[d][d]
        mat[d + 2][d + 1] = 1 - mat[d][d]
        
if pom1 == 0 and pom2 == 1:
    pom3 = query(d + 1, d, d + 2, d + 2)
    if pom3 == 1:
        mat[d + 2][d + 1] = mat[d + 2][d + 2]
        mat[d + 2][d] = mat[d + 2][d + 2]
        mat[d + 1][d] = mat[d + 2][d + 2]
    else:
        mat[d + 2][d + 1] = 1 - mat[d + 2][d + 2]
        mat[d + 2][d] = mat[d + 2][d + 2]
        mat[d + 1][d] = 1 - mat[d + 2][d + 2]
        
if pom1 == 1 and pom2 == 0:
    pom3 = query(d + 1, d, d + 2, d + 2)
    if pom3 == 1:
        mat[d + 2][d + 1] = 1 - mat[d + 2][d + 2]
        mat[d + 2][d] = 1 - mat[d + 2][d + 2]
        mat[d + 1][d] = mat[d + 2][d + 2]
    else:
        mat[d + 2][d + 1] = mat[d + 2][d + 2]
        mat[d + 2][d] = 1 - mat[d + 2][d + 2]
        mat[d + 1][d] = 1 - mat[d + 2][d + 2]
        
if pom1 == 1 and pom2 == 1:
    pom3 = query(d, d, d + 2, d + 1)
    if pom3 == 1:
        mat[d + 2][d + 1] = mat[d][d]
        mat[d + 2][d] = mat[d][d]
        mat[d + 1][d] = mat[d][d]
    else:
        mat[d + 2][d + 1] = 1 - mat[d][d]
        mat[d + 2][d] = mat[d][d]
        mat[d + 1][d] = 1 - mat[d][d]
###################################################
for r in [d + 1, d + 2]:
    c = d
    while c + 2 <= n:
        if mat[r][c + 2] == 2:
            odp = query(r, c, r, c + 2)
            if odp == 1:
                mat[r][c + 2] = mat[r][c]
            else:
                mat[r][c + 2] = 1 - mat[r][c]
        c += 1
    c = d + 1
    while c - 2 > 0:
        if mat[r][c - 2] == 2:
            odp = query(r, c - 2, r, c)
            if odp == 1:
                mat[r][c - 2] = mat[r][c]
            else:
                mat[r][c - 2] = 1 - mat[r][c]
        c -= 1
for c in range(1, n + 1):
    r = d + 1
    while r + 2 <= n:
        if mat[r + 2][c] == 2:
            odp = query(r, c, r + 2, c)
            if odp == 1:
                mat[r + 2][c] = mat[r][c]
            else:
                mat[r +2][c] = 1 - mat[r][c]
        r += 1
    r = d + 2
    while r - 2 > 0:
        if mat[r - 2][c] == 2:
            odp = query(r - 2, c, r, c)
            if odp == 1:
                mat[r - 2][c] = mat[r][c]
            else:
                mat[r -2][c] = 1 - mat[r][c]
        r -= 1
print("!")
for i in range(1, n + 1):
    slowo = ""
    for j in mat[i][1:]:
        slowo += str(j)
    print(slowo)