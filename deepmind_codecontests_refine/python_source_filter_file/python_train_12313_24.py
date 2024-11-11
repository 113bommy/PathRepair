import math

a, x, y = map(int, input().split())
if abs(x) >= a:
    print(-1)
else:
    if y % a == 0:
        print(-1)
    else:
        s = math.ceil(y/a)
        cnt = s/2 - 1
        if s == 1:
            if abs(x) > a / 2:
                print(-1)
            else:
                print(1)
        elif s == 2:
            if abs(x) > a / 2:
                print(-2)
            else:
                print(2)
        elif s % 2 == 0:
            if abs(x) > a/2:
                print(-1)
            else:
                print(int(s+cnt))
        else:
            if x == 0:
                print(-1)
            else:
                if x < 0:
                    f = s + (s / 2 - 1)
                    print(int(f))
                else:
                    f = s + (s / 2 - 1) + 1
                    print(int(f))
