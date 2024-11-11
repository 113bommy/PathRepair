t = int(input())
for i in range(t):
    [c, d] = [int(x) for x in input().split()]
    if(c + d % 2 == 1):
        print(-1)
    else:
        if(c == 0 and d == 0):
            print(0)
        elif(c == d):
            print(1)
        else:
            print(2)