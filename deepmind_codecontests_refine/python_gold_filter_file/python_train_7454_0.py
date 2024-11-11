# It's not a python way


def check_line(line):
    line_color = line[0][0]
    for row in line:
        for color in row:
            if color != line_color:
                return False
    return True


def check_flag(flag, n, m):
    is_vertical = len(set(flag[0])) > 1
    row_has_3_colors = len(set(flag[0])) == 3
    col_has_3_colors = len(set([row[0] for row in flag])) == 3
    if not (row_has_3_colors or col_has_3_colors):
        return False

    if is_vertical:
        dimension = m
    else:
        dimension = n

    unproportional = dimension % 3 != 0
    if unproportional:
        return False

    step = dimension // 3
    for k in range(3):
        if is_vertical:
            is_consistent = check_line([flag[row][k*step: (k+1)*step] for row in range(n)])
        else:
            is_consistent = check_line(flag[k * step: (k + 1) * step])
        if not is_consistent:
            return False
    return True


def main():
    n, m = map(int, input().split())
    flag = [None for i in range(n)]
    for i in range(n):
        flag[i] = input()

    flag_is_correct = check_flag(flag, n, m)
    if flag_is_correct:
        print("YES")
    else:
        print("NO")

main()









