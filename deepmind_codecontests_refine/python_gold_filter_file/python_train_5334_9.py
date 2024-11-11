t = int(input())
if t < 1 or t > 10**3:
    print("nonono dude")
    
for i in range(int(t)):
    a, b, c, d = [int(i) for i in input().split()]
    x, y, x_1, y_1, x_2, y_2 = [int(i) for i in input().split()]
    
    if (x_1 == x_2 and (a + b != 0)) or ((y_1 == y_2) and (c + d != 0)):
        print("No")
    elif x_1 <= x + b - a <= x_2 and y_1 <= y + d - c <= y_2:
        print("Yes")
    else:
        print("No")
    