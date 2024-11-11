n, m = map(int, input().split(" "))
og_mat = [list(input()) for x in range(n)]

mat = og_mat.copy()

char = 'B'


new_line = True
to_be_replaced = []
for i in range(len(mat)):
    new_line = True
    for j in range(len(mat[i])):
        if mat[i][j] == '-':
            to_be_replaced.append((i, j))
        if new_line and 0 < i <= m:
            if mat[i-1][j] == 'B':
                mat[i][j] = 'W'
            elif mat[i-1][j] == 'W':
                mat[i][j] = 'B'
        if mat[i][j] == '.' or mat[i][j] == '-':
            mat[i][j] = char
            new_line = False
            if char == 'B':
                char = 'W'
            else:
                char = 'B'


# print("to be " , to_be_replaced)
for i in to_be_replaced:
    mat[i[0]][i[1]] = '-'

for i in range(len(mat)):
    for j in range(len(mat[i])):
        print(mat[i][j], end="")
    print("\n")
