for i in range(int(input())):
    xa, ya, xb, yb = map(int, input().split(' '))
    n = int(input())
    ip = []
    for j in range(n):
        xs, ys, xt, yt, o, l = map(int, input().split(' '))
        d = (xb - xa) * (yt - ys) - (yb - ya) * (xt - xs)
        if d == 0:
            continue
        t0 = ((yt - ys) * (xs - xa) - (xt - xs) * (ys - ya)) / d
        t1 = ((yb - ya) * (xs - xa) - (xb - xa) * (ys - ya)) / d
        if (t0 > 0 and t0 < 1) and (t1 > 0 and t1 < 1):
            ip.append((t0, o == l))
    count = 0
    if len(ip) > 0:
        ip.sort(key=lambda x: x[0])
        for j in range(len(ip) - 1):
            if ip[j][1] != ip[j + 1][1]:
                count += 1
    print(count)