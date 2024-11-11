n, m, k = map(int, input().split())
lst_lines = [0 for i in range(max(n, m))]
lst_columns = [0 for i in range(max(n, m))]
matrix = []
for i in range(n):
    matrix.append([0 for i in range(m)])
for time in range(k):
    str_or_col, index, color = map(int, input().split())
    if str_or_col == 1:
        lst_lines[index-1] = (color, time)
    else:
        lst_columns[index-1] = (color, time)
for line in range(n):
    if lst_lines[line] != 0:
        lst_line_color = lst_lines[line][0]
        lst_line_time = lst_lines[line][1]
    else:
        lst_line_color = 0
        lst_line_time = -1
    for column in range(m):   
        if lst_columns[column] != 0:
            lst_column_color = lst_columns[column][0]
            lst_column_time = lst_columns[column][1]
            if lst_column_time > lst_line_time:
                matrix[line][column] = lst_column_color
            else:
                matrix[line][column] = lst_line_color
        else:
            matrix[line][column] = lst_line_color
for line in matrix:
    print(' '.join(list(map(str, line))))
