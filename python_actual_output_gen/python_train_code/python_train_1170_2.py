a, b, f, k = map(int, input().split(' '))
l, r = f, a-f
if b < l or b < r:
    print(-1)
elif k > 1 and b < 2*r:
    print(-1)
elif k > 1 and b < 2*l:
    print(-1)
else:
    remain = b
    cnt = 0
    i = 0
    while i < k:
        remain -= l
        if i < k - 1 and remain < 2 * r:
            remain = b
            cnt += 1
        elif i == k - 1 and remain < r:
            remain = b
            cnt += 1
        remain -= 2 * r
        i += 1
        if i == k:
            break
        if i < k - 1 and remain < 2 * l:
            remain = b
            cnt += 1
        elif i == k - 1 and remain < l:
            remain = b
            cnt += 1
        remain -= l
        i += 1
    print(cnt)
