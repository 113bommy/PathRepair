x, y, m = map(int,input().split())
num = 1
if m > max(x,y):
    if x + y > 0:
        while m > x + y:
            if x > y:
                y = x + y
            else:
                x = x + y
            num += 1
        print(num)
    elif x + y > min(x,y):
        if x > y:
                num += abs(y // x) + 1
                y = y % x
        else:
                num += abs(x // y) + 1
                x = x % y
        while m > x + y:
            if x > y:
                y = x + y
            else:
                x = x + y
            num += 1
        print(num)
    else:
        print(-1)
else:
    print(0)
