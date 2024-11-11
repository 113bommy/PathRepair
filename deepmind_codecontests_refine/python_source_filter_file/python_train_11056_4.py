for _ in range(int(input())):
    x,y = map(int,input().split())
    if(x<4):
        if(x==1 and y==1):
            print("YES")
        elif(x==2 and (y==4 or y==3 or y==1 or y==2)):
            print("YES")
        elif(x == 3 and (y == 1 or y==2 or y == 3)):
            print("YES")
        else:
            print("NO")
    else:
        print("YES")
