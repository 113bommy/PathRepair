for _ in range(int(input())):
    x,y,x1,y1 = map(int , input().split())
    if x==x1:
        print(abs(y-y1))
    elif y==y1:
        print(abs(x-x1))
    else:
        print((abs(x-x1)+abs(y-y1))*2)