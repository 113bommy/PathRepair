import sys

m, n = [int(s) for s in input().split()]
array_1 = []
for i in range(m):
    str = [int(s) for s in input().split()]
    array_1.append(str)
array_2 = []
for i in range(m):
    str = [int(s) for s in input().split()]
    array_2.append(str)

if array_1[0][0] > array_2[0][0]:
    array_1[0][0], array_2[0][0] = array_2[0][0], array_1[0][0]

for i in range(1, m):
    if array_2[i][0] < array_1[i][0] and array_2[i][0] > array_1[i - 1][0]:
        array_1[i][0], array_2[i][0] = array_2[i][0], array_1[i][0]
    if array_1[i][0] <= array_1[i - 1][0] or array_2[i][0] <= array_2[i - 1][0]:
        print("Impossible")
        sys.exit(0)

for i in range(1, n):
    if array_2[0][i] < array_1[0][i] and array_2[0][i] > array_1[0][i - 1]:
        array_1[0][i], array_2[0][i] = array_2[0][i], array_1[0][i]
    if array_1[0][i] <= array_1[0][i - 1] or array_2[0][i] <= array_2[0][i - 1]:
        print("Impossible")
        sys.exit(0)

for i in range(1, m):
    for j in range(1, n):
        if array_2[i][j] < array_1[i][j] and array_2[i][j] > array_1[i - 1][j] and array_2[i][j] > array_1[i][j - 1]:
            array_1[i][j], array_2[i][j] = array_2[i][j], array_1[i][j]
        if array_1[i][j] <= array_1[i - 1][j] or array_2[i][j] <= array_2[i - 1][j]:
            print("Impossible")
            sys.exit(0)
        if array_1[i][j] <= array_1[i][j - 1] or array_2[i][j] <= array_2[i][j - 1]:
            print("Impossible")
            sys.exit(0)

print("Possible")