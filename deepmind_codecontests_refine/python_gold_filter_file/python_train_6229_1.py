def main():
    a, b = map(int, input().split())
    s, k = '.#'
    ans = [[k] * 100 for _ in range(50)] + [[s] * 100 for _ in range(50)]
    col = 0
    row = 0
    for _ in range(a - 1):
        ans[row][col] = s
        col += 2
        if col == 100:
            col = 0
            row += 2
    col = 0
    row = 99
    for _ in range(b - 1):
        ans[row][col] = k
        col += 2
        if col == 100:
            col = 0
            row -= 2
    print(100, 100)
    for row in ans:
        print(''.join(row))


if __name__ == '__main__':
    main()
