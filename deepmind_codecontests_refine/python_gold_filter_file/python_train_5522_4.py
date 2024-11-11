x = list(map(int, input().split()))
y = list(map(int, input().split()))
z = [[0, 1, 2, 3], [0, 2, 1, 1], [1, 0, 2, 1], [2, 0, 1, 0], [1, 2, 0, 0], [2, 1, 0, 1]]
succeed = False
for i in range(6):
    match = True
    order = [0, 0, 0]
    for j in range(3):
        if {x[j], x[-j-1]} != {y[z[i][j]], y[-z[i][j]-1]}:
            match = False
            break
        else:
            if x[j] == y[z[i][j]]:
                order[j] = 1
                if x[j] == x[-j-1]:
                    order[j] = 2
    if match:
        if order[0] == 2 or order[1] == 2 or order[2] == 2:
            succeed = True
            break
        if z[i][3] == 0 or z[i][3] == 3:
            if sum(order) % 2:
                succeed = True
                break
        if z[i][3] == 1:
            if not sum(order) % 2:
                succeed = True
                break
if succeed:
    print('Yes')
else:
    print('No')