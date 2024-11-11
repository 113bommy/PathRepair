FIFTY = 50
TWENTY_FIVE = 25
TWELVE = 12
grid = [['X' for _ in range(FIFTY)] for _ in range(FIFTY)]


def construct(n, mark, bg, base_i, base_j):
    for i in range(TWENTY_FIVE):
        for j in range(TWENTY_FIVE):
            grid[base_i + i][base_j + j] = bg

    for i in range(n):
        grid[base_i + 2 * (i // TWELVE)][base_j + 2 * (i % TWELVE)] = mark


def main():
    a, b, c, d = map(int, input().split())
    construct(a - 1, 'A', 'B', 0, 0)
    construct(b - 1, 'B', 'C', TWENTY_FIVE, 0)
    construct(c - 1, 'C', 'D', 0, TWENTY_FIVE)
    construct(d - 1, 'D', 'A', TWENTY_FIVE, TWENTY_FIVE)

    print(FIFTY, FIFTY)
    for row in grid:
        print(''.join(row))


if __name__ == '__main__':
    main()
