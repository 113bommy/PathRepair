import sys


def read(line):
    return [int(c) for c in line.strip().split()]


def count_row(grid, row):
    cnt = grid[row][0] == 1
    res = 0
    for j in range(1, len(grid[0])):
        cur, prev = grid[row][j], grid[row][j - 1]
        if cur == 1 and prev == 1:
            cnt += 1
        elif cur == 0 and prev == 1:
            res = max(res, cnt)
            cnt = 0
        elif cur == 1 and prev == 0:
            cnt = 1

    return max(res, cnt)


def main():
    test = sys.stdin.readlines()

    n, _m, _q = read(test[0])
    grid = [read(test[i]) for i in range(1, n + 1)]

    scores = [count_row(grid, i) for i in range(n)]

    for i, j in (read(line) for line in test[n + 1:]):
        i -= 1
        j -= 1
        grid[i][j] = 1 - grid[i][j]
        scores[i] = count_row(grid, i)
        print(max(scores))


if __name__ == "__main__":
    main()