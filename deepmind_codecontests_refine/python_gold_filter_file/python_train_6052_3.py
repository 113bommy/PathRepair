s = input()
a = [0, 0]
b = [0, 0, 0, 0]
c = [[1, 1], [1, 3]]
d = [[3, 1], [3, 2], [3, 3], [3, 4]]
for i in s:
    if i == '1':
        if(a == [1, 1]):
            a = [0, 0]
        for i in range(0, 2):
            if(a[i] == 0):
                a[i] = 1
                print(*c[i])
                break
    else:
        if(b == [1, 1, 1, 1]):
            b = [0, 0, 0, 0]
        for i in range(0, 4):
            if(b[i] == 0):
                b[i] = 1
                print(*d[i])
                break
            