for _ in range(int(input())):
    x,y=map(int,input().split())
    if x>y:
        print(y*y)
        continue
    a=y//x
    b=y%x
    x=x-b
    y=b
    print((a*a)*x+(a+1)*(a+1)*y)
    
    