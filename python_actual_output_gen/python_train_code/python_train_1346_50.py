x,y = list(map(int,input().split(" ")))

for i in range(y):
    if (i+1) % 2 == 1:
        print("#"*x)
    elif (i+1) % 4 == 0:
        print("#" + "."*(x-1))
    else :
        print("."*(x-1) + "#")