import math
x, y = map(int, input().split())
if (x == 2 and y == 4) or (x == 4 and y == 2 or (x==y)):
    print("=")
elif math.log(x)/x > math.log(y)/2:
    print(">")
else:
    print("<")