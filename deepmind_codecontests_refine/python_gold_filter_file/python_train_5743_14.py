n, m = map(int, input().split())

mat1 = []
mat2 = []

for i in range(n):
    mat1.append(list(map(int, input().split())))

for i in range(n):
    mat2.append(list(map(int, input().split())))


positions = []
positions2 = []

for i in range(n):
    for j in range(m-1):
        #print(mat1[i][j], mat1[i][j+1])
        if mat1[i][j] >= mat1[i][j+1] or mat2[i][j] >= mat2[i][j+1]:
            positions.append([i, j])

for i in range(n-1):
    for j in range(m):
        if mat1[i][j] >= mat1[i+1][j] or mat2[i][j] >= mat2[i+1][j]:
            positions2.append([i, j])

for pos in positions:
    i, j = pos[0], pos[1]
    if mat1[i][j] < mat2[i][j+1] and mat2[i][j] < mat1[i][j+1]:
        continue
    else:
        print("Impossible")
        quit()
#print(positions, positions2)

for pos in positions2:
    i, j = pos[0], pos[1]
    if mat1[i][j] < mat2[i+1][j] and mat2[i][j] < mat1[i+1][j]:
        continue
    else:
        print("Impossible")
        quit()

print("Possible")