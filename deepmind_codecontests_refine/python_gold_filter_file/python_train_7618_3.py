n, m = map(int, input().split())
mat = []


for _ in range(n):
    mat.append(list(map(int, input().split())))


# print(mat)

for i in range(n):
    for j in range(m):
        if mat[n-i-2][m-j-2] == 0:
            mat[n-i-2][m-j-2] = min(mat[n-i-2][m-j-1], mat[n-i-1][m-j-2]) - 1

sums = 0
for i in range(n):
    for j in range(m):
        sums += mat[i][j]
# print(mat)
# print(sums)
ok = True
for i in range(n):
    for j in range(m-1):
        if mat[i][j] >= mat[i][j+1]:
            ok = False

for i in range(n-1):
    for j in range(m):
        if mat[i][j] >= mat[i+1][j]:
            ok = False
if ok:
    print(sums)
else:
    print(-1)
