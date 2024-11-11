a = []
for i in range(8):
    a.append(list(input()))
b = 8
w = 8
for i in range(8):
    for j in range(8):
        if a[i][j] == 'B':
            k = 0
            while i + k != 7:
                k += 1
                if a[i + k][j] == 'W':
                    k = 8
                    break
            b = min(k, b)
        elif a[i][j] == 'W':
            k = 0
            while k != i:
                k += 1
                if a[i - k][j] == 'B':
                    k = 8
                    break
            w = min(k, w)
if w < b:
    print('A')
else:
    print('B')
