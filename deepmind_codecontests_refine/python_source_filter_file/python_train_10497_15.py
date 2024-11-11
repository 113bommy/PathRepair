import sys

readline = sys.stdin.readline
MOD = 10 ** 9 + 7
INF = float('INF')
sys.setrecursionlimit(10 ** 5)


def main():
    n, k = map(int, readline().split())
    l = 2 * k
    grid = [[0] * (2 * l) for _ in range(2 * l)]

    for i in range(n):
        x, y, c = input().split()
        x, y = int(x), int(y)
        if c == "W":
            x += k
        mx, my = x % l, y % l
        grid[mx][my] += 1
        grid[mx + k][my] -= 1
        grid[mx][my + k] -= 1
        grid[mx + k][my + k] += 1
        grid[mx + k][my + k] += 1
        grid[mx + 2 * k][my + k] -= 1
        grid[mx + k][my + 2 * k] -= 1
        grid[mx + 2 * k][my + 2 * k] += 1

    for x in range(1, 2 * l):
        for y in range(1, 2 * l):
            grid[x][y] += grid[x - 1][y]

    for x in range(1, 2 * l):
        for y in range(1, 2 * l):
            grid[x][y] += grid[x][y - 1]

    count = [[0] * l for _ in range(l)]

    for x in range(2 * l):
        for y in range(2 * l):
            count[x % l][y % l] += grid[x][y]
    ans = 0
    for x in range(l):
        for y in range(l):
            ans = max(ans, count[x][y])

    print(ans)


if __name__ == '__main__':
    main()
