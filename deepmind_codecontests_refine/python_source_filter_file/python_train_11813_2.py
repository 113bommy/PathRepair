r,c = map(int,input().split())
matrix = []
original = [[0 for _ in range (c)] for _ in range (r)]
idex = 0
rowCheck = [0 for _ in range(r)]
columCheck = [0 for _ in range(c)]
ans = ['YES','NO']
for _ in range(r):
    matrix.append(list(map(int,input().split())))
put = 0
row = []
for i in range(r):
    if 0 not in matrix[i]:
        rowCheck[i] = 1
for j in range(c):
    start = 1
    for i in range(r):
        start&=matrix[i][j]
    if start == 1:
        columCheck[j] = 1
for i in range(r):
    if rowCheck[i]:
        for j in range(c):
            if columCheck[j]:
                original[i][j] = 1
rowCheck2 = [0 for _ in range(r)]
columCheck2 = [0 for _ in range(c)]
for i in range(r):
    if 1 in original[i]:
        rowCheck2[i] = 1
for j in range(c):
    start = 0
    for i in range(r):
        start|=original[i][j]
    if start == 1:
        columCheck2[j] = 1
for i in range(r):
    if idex:
        break
    for j in range(c):
        if matrix[i][j]!= rowCheck[i]|columCheck[j]:
            idex = 1
if idex:
    print(ans[idex])
else:
    print(ans[idex])
    for v in original:
        print(*v)