import math
t = int(input())
for i in range(t):
    a, b = map(int,input().split())
    a, b = max(a, b), min(a, b)
    if a == b:
        print("0 0")
    elif b == 0:
        print(a, "0")
    elif b <= a/2:
        print(a-b, a-b*2)
    else:
        if a%(a-b) == 0:
            print(a-b, 0)
        else:
            print(a-b, min(b%(a-b), (a-b)-b%(a-b)))