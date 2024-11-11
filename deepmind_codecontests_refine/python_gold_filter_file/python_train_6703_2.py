t = int(input())
def get_cnt(num, mod):
    cnt = 0
    while num > 0 and num % mod == 0:
        cnt += 1
        num //= mod
    return cnt
r = range(t)
def solve(m, num):
    path = ''
    n = [[0 for i in r] for i in r]
    for i in r:
        for j in r:
            n[i][j] = get_cnt(m[i][j], num)
    for i in range(1, t):
        n[0][i] += n[0][i - 1]
        n[i][0] += n[i - 1][0]
    for i in range(1, t):
        for j in range(1, t):
            if n[i - 1][j] < n[i][j - 1]:
                n[i][j] += n[i - 1][j]
            else:
                n[i][j] += n[i][j - 1]
    x, y = t - 1, t - 1
    while x or y:
        if x == 0 or (y > 0 and n[x - 1][y] > n[x][y - 1]):
            y -= 1
            path += 'R'
        else:
            x -= 1
            path += 'D'
    return [n[t - 1][t - 1], path[::-1]]

matrix = [[]] * t
zero_point = [0, 0, 0]
for i in r:
    matrix[i] = list(map(int, input().split()))
    for j in r:
        if matrix[i][j] == 0:
            zero_point = [1, i, j]
ans2 = solve(matrix, 2)
ans5 = solve(matrix, 5)
if ans2 < ans5:
    ans = ans2
else:
    ans = ans5
if zero_point[0] == 0 or ans[0] <= 1:
    print(ans[0])
    print(ans[1])
else:
    print(1)
    print('R' * zero_point[2] + 'D' * (t - 1) + 'R' * (t - zero_point[2] - 1))