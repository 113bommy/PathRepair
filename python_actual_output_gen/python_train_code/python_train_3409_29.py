put = lambda: tuple(map(int, input().split()))

a, b = put()
if b / a >= 2:
    print(0)
else:
    used = []
    ans = 0
    if b < a:
        a = b - 1
    if b % 2 == 0:
            up = b // 2
    else:
        up = (b - 1) // 2
    ans = a - up
    print(ans)
