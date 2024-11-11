n = int(input())

static_min_x = 10 ** 8
static_max_x = - 10 ** 8
static_min_y = 10 ** 8
static_max_y = - 10 ** 8
rx_max = - 10 ** 8
rx_min = 10 ** 8
lx_max = - 18 ** 8
lx_min = 10 ** 8
uy_max = - 10 ** 8
uy_min = 10 ** 8
dy_max = - 18 ** 8
dy_min = 10 ** 8
for _ in range(n):
    x, y, d = input().split()
    x = int(x)
    y = int(y)
    if d == 'R':
        rx_max = max(rx_max, x)
        rx_min = min(rx_min, x)
        static_max_y = max(static_max_y, y)
        static_min_y = min(static_min_y, y)
    elif d == 'L':
        lx_max = max(lx_max, x)
        lx_min = min(lx_min, x)
        static_max_y = max(static_max_y, y)
        static_min_y = min(static_min_y, y)
    elif d == 'U':
        uy_max = max(uy_max, y)
        uy_min = min(uy_min, y)
        static_max_x = max(static_max_x, x)
        static_min_x = min(static_min_x, x)
    else:
        dy_max = max(dy_max, y)
        dy_min = min(dy_min, y)
        static_max_x = max(static_max_x, x)
        static_min_x = min(static_min_x, x)

def calc_ans(t):
    max_x = max(rx_max + t, lx_max - t, static_max_x)
    min_x = min(rx_min + t, lx_min - t, static_min_x)
    max_y = max(uy_max + t, dy_max - t, static_max_y)
    min_y = min(uy_min + t, dy_min - t, static_min_y)
    return (max_x - min_x) * (max_y - min_y)

ans = calc_ans(0)
ans = min(ans, calc_ans(abs(rx_max - lx_max) / 2.0))
if lx_max > static_max_x:
    ans = min(ans, calc_ans(lx_max - static_max_x))
if static_max_x > rx_max:
    ans = min(ans, calc_ans(static_max_x - rx_max))

ans = min(ans, calc_ans(abs(rx_min - lx_min) / 2.0))
if lx_min > static_min_x:
    ans = min(ans, calc_ans(lx_min - static_min_x))
if static_min_x > rx_min:
    ans = min(ans, calc_ans(static_min_x - rx_min))

ans = min(ans, calc_ans(abs(uy_max - dy_max) / 2.0))
if dy_max > static_max_y:
    ans = min(ans, calc_ans(dy_max - static_max_y))
if static_max_y > uy_max:
    ans = min(ans, calc_ans(static_max_y - uy_max))

ans = min(ans, calc_ans(abs(uy_min - dy_min) / 2.0))
if dy_min > static_min_y:
    ans = min(ans, calc_ans(dy_min - static_min_y))
if static_min_y > uy_min:
    ans = min(ans, calc_ans(static_min_y - uy_min))

print(ans)