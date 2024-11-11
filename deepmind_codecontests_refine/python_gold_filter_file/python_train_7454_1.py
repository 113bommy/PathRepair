
n, m = list(map(int, input().split()))

res = max(n, m) >= 3

is_horo = True
is_vert = True
if res:
    flag = []
    for i in range(n):
        r = input()
        if len(r) != m:
            res = False
            break
        flag.append(list(r))

    px = flag[0][0]
    for i in range(1, m):
        if flag[0][i] != px:
            is_horo = False
            break

    for i in range(1, n):
        if flag[i][0] != px:
            is_vert = False
            break
    res = is_horo ^ is_vert

compressed = []
if res:
    if is_horo:
        for r in flag:
            px = r[0]
            for c in r[1:]:
                if c != px:
                    res = False
                    break
            compressed.append(px)
    elif is_vert:
        for i in range(m):
            px = flag[0][i]
            for j in range(1, n):
                if flag[j][i] != px:
                    res = False
                    break
            compressed.append(px)

if res and compressed:
    stripe_width = None
    c_stripe = None
    c_width = 0
    widths = []
    seen = set()
    for stripe in compressed:
        if c_stripe is None:
            c_stripe = stripe
            c_width = 1
        elif c_stripe != stripe:
            seen.add(c_stripe)
            widths.append(c_width)
            c_width = 1
            c_stripe = stripe
        else:
            c_width += 1
    widths.append(c_width)
    seen.add(c_stripe)

    if len(widths) != 3 or len(seen) != 3:
        res = False
    else:
        first = widths[0]
        for i in range(1, len(widths)):
            if widths[i] != first:
                res = False
                break

print('YES' if res else 'NO')

