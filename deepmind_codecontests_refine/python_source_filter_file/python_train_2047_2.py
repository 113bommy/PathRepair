n, m, k = [int(i) for i in input().split(' ')]

ans_x, ans_y = 0, 0

if k < n:
    ans_x, ans_y = k + 1, 1
else:
    res = k - n
    line = int(res / (m-1))
    raw = res - line * (m-1) + 2
    ans_x = n - line
    if line % 2 == 0:
        ans_y = raw
    else:
        ans_y = m + 2 - raw

print('{} {}'.format(ans_x, ans_y))