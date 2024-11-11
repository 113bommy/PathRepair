a = int(input())
b = []
c = []
for i in range(a):
    b.append(int(input()))
    c.append(list(map(int, input().split())))
for i in range(a):
    if b[i] == 1:
        print('T')
    elif b[i] == 2:
        if c[i][0] == c[i][1]:
            print("HL")
        else:
            print('T')
    elif max(c[i]) > sum(c[i]) / 2:
        print('T')
    else:
        if sum(c[i]) % 2 == 0:
            print('Hl')
        else:
            print('T')
