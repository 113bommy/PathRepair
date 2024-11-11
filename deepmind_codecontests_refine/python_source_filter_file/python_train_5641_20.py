t = int(input())

for i in range(0,t):
    s = 0
    b, p, f = map(int, input().split())
    h, c = map(int, input().split())

    print(b , p, f)
    print(h, c)

    if h > c:
        while (b >= 2) & ((p > 0) | (f > 0)):
            if(p > 0):
                s += h
                b -= 2
                p -= 1
            elif(f > 0):
                s += c
                b -= 2
                f -= 1
            #print(b, p, f)
            #print(h, c)

    else:
        while (b >= 2) & ((p > 0) | (f > 0)):
            if(f > 0):
                s += c
                b -= 2
                f -= 1
            elif(p > 0):
                s += h
                b -= 2
                p -= 1
            #print(b, p, f)
            #print(h, c)

    print(s)
































"""import numpy as np

s = 0
a = np.zeros((3, 3))

for i in range(0, 3):
    for j in range(0, 3):
        a[i][j] = int(input())


s = a[0][0]*a[1][1]*a[2][2] + a[1][0]*a[2][1]*a[0][2] + a[0][1]*a[1][2]*a[2][0] - a[2][0]*a[1][1]*a[0][2] - a[0][0]*a[1][2]*a[2][1] - a[2][2]*a[1][0]*a[0][1]
#              ok
print(s)# y x"""