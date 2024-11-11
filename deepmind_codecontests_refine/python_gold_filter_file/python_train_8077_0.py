a, b = map(int, input().split())

for i in range(1, 1000000):
    if (a < i):
        if ((i % 2) == 0): print("Valera")
        else: print("Vladik")
        break
    a -= i
    c= b;
    b = a
    a =c




