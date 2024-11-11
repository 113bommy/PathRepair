for i in range(int(input())):
    n= int(input())
    x = 0
    while n%3 == 0:
        if n%6 == 0:
            n = n//6
        else:
            n*= 2
            x+= 1
    if n == 1:
        print(x)
    else:
        print(-1)