def calc(i_min, t, x, y):
    cnt = 0
    t1 = t
    i = i_min
    min_dist = abs(x[i_min] - xs) + abs(y[i_min] - ys)
    if min_dist <= t:
        cnt += 1
    t1 -= min_dist
    while t1 > 0 and i > 0:
        i -= 1
        dist = abs(x[i + 1] - x[i]) + abs(y[i + 1] - y[i])
        if dist <= t1:
            cnt += 1
        t1 -= dist
    if t1 > 0 and i_min + 1 < len(x):
        dist = abs(x[i_min + 1] - x[0]) + abs(y[i_min + 1] - y[0])
        if t1 >= dist:
            cnt += 1
        t1 -= dist
        i = i_min + 1
        while t1 > 0 and i < len(x) - 1:
            i += 1
            dist = abs(x[i - 1] - x[i]) + abs(y[i - 1] - y[i])
            if dist <= t1:
                cnt += 1
            t1 -= dist

    return cnt


a = list(map(int, input().split()))
x = [a[0]]
y = [a[1]]
ax = a[2]
ay = a[3]
bx = a[4]
by = a[5]
a = list(map(int, input().split()))
xs = a[0]
ys = a[1]
t = a[2]
m = max(t + xs + 1, t + ys + 1)
cur_x = x[0]
cur_y = y[0]
min_dist = abs(xs - x[0]) + abs(ys - y[0])
i_min = 0
while x[-1] <= m and y[-1] <= m:
    new_x = ax * x[-1] + bx
    x.append(new_x)
    new_y = ay * y[-1] + by
    y.append(new_y)
    dist = abs(xs - new_x) + abs(ys - new_y)
    if dist < min_dist:
        min_dist = dist
        i_min = len(x) - 1

res = calc(i_min, t, x, y)
if i_min > 0:
    res = max(res, calc(i_min - 1, t, x, y))
if i_min + 1 < len(x):
    res = max(res, calc(i_min + 1, t, x, y))

print(res)
