def rows_of_coins(m: int, rows: list):
    # https://codeforces.com/problemset/problem/1555/C

    if m == 1:
        return 0

    if m == 2:
        return min(rows[0][1], rows[1][0])

    arr = [[0] * m, [0] * m]

    arr[1][0] = rows[1][0]
    arr[0][m-1] = rows[0][m-1]
    for i in range(1, m-1):
        arr[1][i] = arr[1][i-1] + rows[1][i]
        arr[0][m-1-i] = arr[0][m-i] + rows[0][m-1-i]

    min_coins = (10**4) * m

    for i in range(2, m):
        cur_min = max(arr[0][i], arr[1][i-2])
        if cur_min < min_coins:
            min_coins = cur_min

    return min(min_coins, arr[0][1], arr[1][-2])


t = int(input())
for i in range(t):
    m = int(input())
    rows = [list(map(int, input().split(' '))), list(map(int, input().split(' ')))]
    print(rows_of_coins(m, rows))
