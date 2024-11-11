import sys, math
input = sys.stdin.readline
a, b, c = map(int, input().split())
if(a == 0):
    if(b == 0):
        if(c == 0):
            print(-1)
        else:
            print(0)
    else:
        print("1\n{:.6f}".format(c / b))
else:
    delta = b * b - 4 * a * c
    if(delta < 0):
        print(0)
    elif(delta == 0):
        print("1\n{:.6f}".format(-b / a))
    else:
        x1 = (-b - math.sqrt(delta)) / (2 * a)
        x2 = (-b + math.sqrt(delta)) / (2 * a)
        print(2)
        print("{:.6f}\n{:.6f}".format(min(x1, x2), max(x1,x2)))