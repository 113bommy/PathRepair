x = int(input())
if x == 1: print(-1)
else:
    for i in range(1,x+1):
        if i % 2 == 0:
            print(i-1, end = " ")
        else:
            print(i + 1, end = " ")