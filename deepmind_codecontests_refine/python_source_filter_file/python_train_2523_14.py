for ix in range(int(input())):
    x, y = map(int, input().split())
    a, b = map(int, input().split())
    if 2*a<b:
        print(a*(x+y-2)+b)
    else:
        print((min(x,y)*b)+(abs(x-y)*a))