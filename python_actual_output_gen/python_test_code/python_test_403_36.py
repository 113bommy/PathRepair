for _ in range(int(input())):
    x,y,a,b = map(int,input().split())
    if((x+y) % (a+b) != 0):
        print("-1")
    else:
        print(int((y-x)/(a+b)))
    