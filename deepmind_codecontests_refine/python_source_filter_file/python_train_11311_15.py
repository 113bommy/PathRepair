a, b = map(int, input().split())

while a != 0 and b != 0:
    if a == 1:
        if b % 2 == 0:
            a,b=1,0
        else:
            a,b=1,1
        break
    elif b == 1:
        if a % 2 == 0:
            a,b=0,1
        else:
            a,b=1,1
        break
    if (a >= 2 * b):
        a = a % 2 * b;
    elif (b >= 2 * a):
        b = b % 2 * a;
    else:
        break

print(a, b)
