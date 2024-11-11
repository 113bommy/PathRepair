a, b, c, d = list(map(int,input().split()))
b -= a
c -= d
arr = []
k = True
if b >= 0 and c >=0:
    if a == 0 and b == 0 and c==1:
        print("YES")
        arr.append(2)
        for i in range (d):
            arr.append(1)
            arr.append(2)
        print(*arr,sep = " ")
        k = False
    elif d == 0 and c == 0 and b == 1:
        print("YES")
        arr.append(1)
        for i in range (a):
            arr.append(0)
            arr.append(1)
        print(*arr, sep = " ")
        k = False
    elif b == c and k:
        print("YES")
        if b == 0:
            for i in range (a):
                arr.append(0)
                arr.append(1)
            for i in range (d):
                arr.append(2)
                arr.append(3)
        else:
            for i in range (a):
                arr.append(1)
                arr.append(0)
            for i in range(b):
                arr.append(1)
                arr.append(2)
            for i in range (d):
                arr.append(3)
                arr.append(2)
        print(*arr, sep = " ")
    elif c - b == 1 and k:
        print("YES")
        if a > 0:
            for i in range (a - 1):
                arr.append(0)
                arr.append(1)
            arr.append(0)
            arr.append(1)
            arr.append(2)
        else:
            arr.append(2)
        for i in range (c - 1):
            arr.append(1)
            arr.append(2)
        for i in range (d):
            arr.append(3)
            arr.append(2)
        print(*arr, sep = " ")
    elif b - c == 1 and k:
        print("YES")
        for i in range (a):
            arr.append(1)
            arr.append(0)
        for i in range (b - 1):
            arr.append(1)
            arr.append(2)
        arr.append(1)
        if d > 0:
            arr.append(2)
            for i in range (d - 1):
                arr.append(3)
                arr.append(2)
            arr.append(3)
        print(*arr, sep = " ")
    else:
        print ("NO")
else:
    if b == -1 and d == 0 and c == 0:
        print("YES")
        for i in range (a-1):
            arr.append(0)
            arr.append(1)
        arr.append(0)
        print(*arr,sep = " ")
    elif a == 0 and b == 0 and c == -1:
        print("YES")
        for i in range (d-1):
            arr.append(3)
            arr.append(2)
        arr.append(3)
        print(*arr,sep = " ")
    else:
        print("NO")