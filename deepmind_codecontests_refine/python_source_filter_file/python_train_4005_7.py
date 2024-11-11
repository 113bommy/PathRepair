def GETBIT(x, bit):
    return (x >> bit) & 1

test = int(input())
while test > 0:
    test -= 1
    l, r = map(int, input().split())
    pos = 63
    x = -1
    cnt = 0
    ans = 0
    while pos >= 0:
        if GETBIT(r, pos) == 1:
            if GETBIT(l, pos) == 0:
                x = pos
                break
            cnt += 1
            ans += (1 << pos)
        pos -= 1
    if x == -1:
        print(cnt)
    else:
        rs = cnt
        pre = ans
        while pos >= 0:
            if GETBIT(r, pos) == 1:
                if rs < cnt + pos:
                    rs = cnt + pos
                    ans = pre + (1 << pos) - 1
                cnt += 1
                pre += (1 << pos)
                if rs < cnt:
                    rs = cnt
                    ans = pre
            pos -= 1
        print(ans)