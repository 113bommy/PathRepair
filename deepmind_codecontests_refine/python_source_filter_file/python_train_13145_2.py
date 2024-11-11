t = int(input())

for _ in range(t):
    x, y = map(int, input().split(' '))
    c = [int(val) for val in input().split(' ')]

    if x == 0 and y == 0:
        print(0)
    elif x == 0:
        if y > 0:
            print(min(c[1]*y, (c[0]+c[2])*y))
        else:
            print(min(c[4]*-y, (c[3]+c[5])*-y))
    elif y == 0:
        if x > 0:
            print(min(c[5]*x, (c[0]+c[4])*x))
        else:
            print(min(c[2]*-x, (c[1]+c[3])*x))
    elif x > 0:
        if x == y:
            print(min(c[0]*x, (c[1]+c[5])*x))
        elif y > x:
            print(min(c[0]*x+c[1]*(y-x), c[1]*y+c[5]*x, c[0]*y+c[2]*(y-x)))
        elif y < 0:
            print(min(c[5]*x+c[4]*-y, c[5]*(x-y)+c[3]*-y, c[4]*(x-y)+c[0]*x))
        else:
            print(min(c[5]*(x-y)+c[0]*y, c[1]*y+c[5]*x, c[4]*(x-y)+c[0]*x))

    elif x < 0:
        if x == y:
            print(min(c[3]*-x, (c[2]+c[4])*-x))
        elif x > y:
            print(min(c[3]*-x+c[4]*(x-y), c[4]*-y+c[2]*-x, c[3]*-y+c[5]*(x-y)))
        elif y > 0:
            print(min(c[2]*-x+c[1]*y, c[2]*(y-x)+c[0]*y, c[1]*(y-x)+c[3]*-x))
        else:
            print(min(c[2]*(x-y)+c[3]*-y, c[4]*-y+c[2]*-x, c[1]*(y-x)+c[3]*-x))
