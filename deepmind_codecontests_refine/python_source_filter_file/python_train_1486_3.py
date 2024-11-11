n, m = list(map(int, input().split()))
g = []
for _ in range(n):
    g.append(input())

if n < m:
    new_g = [[0 for _ in range(m)] for _ in range(n)]
    for i in range(n):
        for j in range(m):
            new_g[i][j] = int(g[i][j])
else:
    new_g = [[0 for _ in range(n)] for _ in range(m)]
    for i in range(n):
        for j in range(m):
            new_g[j][i] = int(g[i][j])
    n, m = m, n
g = new_g


def get_one_count(num):
    ans = 0
    while num > 0:
        ans += (num % 2)
        num //= 2
    return ans


def solve(n, m, g):
    if n >= 4:
        return -1

    if n == 1:
        return 0

    if n == 2:
        prev_mask = {
            0: [1, 2],
            1: [0, 3],
            2: [0, 3],
            3: [1, 2],
        }
        k = 4
    else:
        prev_mask = {
            0: [2, 5],
            1: [3, 4],
            2: [0, 7],
            3: [1, 6],
            4: [1, 6],
            5: [0, 7],
            6: [3, 4],
            7: [2, 5]
        }
        k = 8

    dp = [[0 for _ in range(k)] for _ in range(m)]

    for i in range(0, m):
        cur_state = g[0][i] + g[1][i]*2
        if n == 3:
            cur_state += g[2][i]*4
        for kk in range(k):
            prev_states = prev_mask[cur_state]
            change_num = get_one_count(kk ^ cur_state)
            if i == 0:
                dp[i][kk] = change_num
                continue
            dp[i][kk] = min([dp[i-1][prev_state] for prev_state in prev_states]) + change_num
    return min(dp[m-1])


print(solve(n, m, g))