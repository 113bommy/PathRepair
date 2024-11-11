def main():
    m, n = [int(i) for i in input().split()]
    a = [[0] * n for _ in range(m)]
    b = [[int(i) for i in input().split()] for _ in range(m)]
    row_all_true = []
    for i in range(m):
        if all(b[i]):
            row_all_true.append(i)
    col_all_true = []
    for j in range(n):
        if all(b[i][j] for i in range(m)):
            col_all_true.append(j)
    for i in row_all_true:
        for j in col_all_true:
            a[i][j] = 1
    for i in range(m):
        for j in range(n):
            if b[i][j] and (not any(b[i]) or not any(b[k][j] for k in range(m))):
                print("NO")
                return
    print("YES")
    for row in a:
        print(*row)


main()
