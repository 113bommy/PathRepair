def mult(x1, y1, x2, y2):
    return x1*y2 - x2*y1

xa, ya = [int(item) for item in input().split()]
xb, yb = [int(item) for item in input().split()]
xc, yc = [int(item) for item in input().split()]

x1, y1 = xa-xb, ya-yb
x2, y2 = xa-xc, ya-yc

if mult(x1, y1, x2, y2) > 0:
    print("LEFT")
elif mult(x1, y1, x2, y2) < 0:
    print("RIGHT")
else:
    print("TOWARDS")