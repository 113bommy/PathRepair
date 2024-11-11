import sys

for i in range(int(sys.stdin.readline())):
    temp = list(map(int,sys.stdin.readline().split()))
    x = temp[0]
    y = temp[1]
    a = temp[2]
    b = temp[3]

    if (x-y) % (a+b) == 0:
        print(int((x-y)/(a+b)))
    else:
        print("-1")
