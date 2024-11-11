x = int(input())
for i in range(x):
    y = str(input())
    print((23 - int(y[0:2]))*60 + 60 - int(y[-2:]))