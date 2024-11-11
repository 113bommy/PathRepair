x = int(input())
for i in range(x):
    y = str(input())
    print((24 - int(y[0:2]))*60 + 60 - int(y[-2:]))