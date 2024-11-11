a = list(input().split(' '))
x, y = int(a[0]), int(a[1])
if (y == 0):
    print("No")
elif x == 0:
    if y == 1:
        print("Yes")
    else:
        print("No")
elif (x - y + 1) >= 0 and (x - y + 1)%2 == 0:
    print("Yes")
else:
    print("No")
