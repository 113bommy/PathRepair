for i in range(int(input())):
    a,b,c,d=map(int,input().split())
    if((abs(a-b))%(c+d)==0):
        print((abs(a-b))/(c+d))
    else:
        print("-1")