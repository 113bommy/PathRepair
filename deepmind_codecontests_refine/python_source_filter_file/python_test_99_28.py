for _ in range(int(input())):
    x,n=map(int, input().split( ))
    if n%2==0:
        if x%4==0:
            print(x)
        elif x%4==1:
            print(x-n)
        elif x%4==2:
            print(x+1)
        elif x%4==3:
            print(x+n+1)
    else:
        if x%4==1:
            print(x+n)
        elif x%4==2:
            print(x-1)
        elif x%4==3:
            print(x-n-1)
        elif x%4==0:
            print(x)
