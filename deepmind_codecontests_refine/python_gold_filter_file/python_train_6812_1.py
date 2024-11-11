if __name__ == '__main__':
    n, m, k = map(int, input().split())
    chessboard = tuple(tuple(map(int, input())) for _ in range(n))

    costs = [m * [0] for _ in range(n)]

    for i in range(m):
        costs[0][i] = {i: (-1, "") for i in range(k + 1)}
        costs[0][i][chessboard[0][i] % (k + 1)] = (chessboard[0][i], "")

    for i in range(1, n):
        for j in range(m):
            costs[i][j] = {i: (-1, "") for i in range(k + 1)}

            for mod in range(k + 1):
                next_mod = (chessboard[i][j] + mod) % (k + 1)
                next = (-1, "")

                if j + 1 < m \
                        and costs[i - 1][j + 1][mod][0] >= 0 \
                        and (j == 0 or costs[i - 1][j + 1][mod] > costs[i - 1][j - 1][mod]):
                    next = costs[i - 1][j + 1][mod]
                    next = (next[0] + chessboard[i][j], "R" + next[1])

                elif j - 1 >= 0 and costs[i - 1][j - 1][mod][0] >= 0:
                    next = costs[i - 1][j - 1][mod]
                    next = (next[0] + chessboard[i][j], "L" + next[1])
                costs[i][j][next_mod] = max(costs[i][j][next_mod], next)

    # print(max(costs[m - 1][i][0][0] for i in range(n)))

    i_max = max(range(m), key=lambda i: costs[n - 1][i][0][0])
    print(costs[n - 1][i_max][0][0])
    if costs[n - 1][i_max][0][0] >= 0:
        print(i_max + 1)
        print(costs[n - 1][i_max][0][1])
