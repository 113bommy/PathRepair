for _ in range(int(input())):
    x1,y1,x2,y2=map(int,input().split())

    result=abs(x1-x2)+abs(y1-y2)
    if x1==x2 or y1==y2:
        result+=2
    print(result)
