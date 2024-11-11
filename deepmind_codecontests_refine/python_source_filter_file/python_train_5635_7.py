def ii():
    return int(input())
def mi():
    return map(int, input().split())
def li():
    return list(mi())

for t in range(ii()):
    n, k = mi()
    if n == 1:
        ans = 'YES 0' if k == 1 else 'NO'
    elif n == 2:
        if k <= 2:
            ans = 'YES 1'
        elif k == 3 or k > 5:
            ans = 'NO'
        else:
            ans = 'YES 0'
    elif n <= 30 and k > (4 ** n - 1) // 3:
        ans = 'NO'
    else:
        c, x = 0, n
        p2 = 2
        while 1:
            if c + p2 - 1 > k:
                break
            c += p2 - 1
            x -= 1
            p2 *= 2
        ans = 'YES %d' % (x,)
    print(ans)
