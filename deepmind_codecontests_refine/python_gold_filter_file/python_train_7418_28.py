import sys
t = sys.stdin.readline()
while t:
    t = int(t)
    n = int(input())
    if n <= 30:
        print("NO")
    else:
        x = n-30
        print("YES")
        if n == 44:
            print("{} {} {} {}".format(6,10,15,13))
        elif n == 36:
            print("{} {} {} {}".format(6,10,15,5))
        elif n == 40:
            print("{} {} {} {}".format(6,10,15,9))
        else:
            print("{} {} {} {}".format(6,10,14,x))
    t -= 1
    