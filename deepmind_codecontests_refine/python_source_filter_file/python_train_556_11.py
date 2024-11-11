def check_val(mat, row1_num):
    row1_sum = sum(mat[0]) + row1_num
    row2_num = row1_sum - sum(mat[1])
    row3_num = row1_sum - sum(mat[2])

    if (
        (row1_num + row2_num + row3_num != row1_sum) or 
        (mat[0][2] + row2_num + mat[2][0] != row1_sum) or 
        (row1_num + mat[1][0] + mat[2][0] != row1_sum) or 
        (mat[0][1] + row2_num + mat[2][1] != row1_sum) or 
        (mat[2][0] + mat[2][1] + row3_num != row1_sum)
        ):
        return False

    return True

mat = []

for _ in range(3):
    mat.append([int(i) for i in input().split()])

for num in range(1, 100_000):
    if (check_val(mat, num)):
        mat[0][0] = num
        row1_sum = sum(mat[0])

        mat[1][1] = row1_sum - sum(mat[1])
        mat[2][2] = row1_sum - sum(mat[2])

for i in range(3):
    print(*mat[i])
