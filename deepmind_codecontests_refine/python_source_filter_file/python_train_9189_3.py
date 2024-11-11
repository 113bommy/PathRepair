for _ in range(int(input())):
    x1,y1,x2,y2 = list(map(int,input().split()))
    if(x1==x2 or y1==y2):
        print(abs(x1-x2)+abs(y1-y2))
    else:
        print(2*(abs(x1-x2)+abs(y1-y2)))
