n = int(input())
for i in range(0,n):
    a = int(input())
    x = 0
    while a != 1 and x !=-1:
        x = x+1
        if a%2 == 0:
            a = a/2
        elif a%3 == 0:
            a = 2*a/3
        elif a%5 == 0:
            a = 4*a/5
        else:
            x = -1
    print(x)    