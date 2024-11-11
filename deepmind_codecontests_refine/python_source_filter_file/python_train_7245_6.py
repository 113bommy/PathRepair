

def diagL(coor, arr):
    tmp = coor
    opt = 1
    while tmp - 11  >= 0 and (tmp // 10 - 1) == (tmp - 11) // 10:
        tmp -= 11
        if arr[tmp] == 'X':
            opt += 1
        else:
            break
    tmp = coor
    while  tmp + 11  < 100 and (tmp // 10 + 1) == (tmp + 11) // 10:
        tmp += 11
        if arr[tmp] == 'X':
            opt += 1
        else:
            break
    if opt >= 5:
        return True
    return False


def diagR(coor, arr):
    tmp = coor
    opt = 1
    while tmp - 9  >= 0 and (tmp // 10 - 1) == (tmp - 9) // 10:
        tmp -= 9
        if arr[tmp] == 'X':
            opt += 1
        else:
            break
    tmp = coor
    while tmp + 9  < 100 and (tmp // 10 + 1) == (tmp + 9) // 10:
        tmp += 9
        if arr[tmp] == 'X':
            opt += 1
        else:
            break
    if opt >= 5:
        return True
    return False

def sideX(coor, arr):
    tmp = coor
    opt = 1
    while (tmp - 1) // 10 == coor // 10 :
        tmp -= 1
        if arr[tmp] == 'X':
            opt += 1
        else:
            break
    tmp = coor
    while (tmp + 1) // 10 == coor // 10:
        tmp += 1
        if arr[tmp] == 'X':
            opt += 1
        else:
            break
    if opt >= 5:
        return True
    return False

def sideY(coor, arr):
    tmp = coor
    opt = 1
    while tmp - 10 >= 0 :
        tmp -= 10
        if arr[tmp] == 'X':
            opt += 1
        else:
            break
    tmp = coor
    while tmp + 10 < 100:
        tmp += 10
        if arr[tmp] == 'X':
            opt += 1
        else:
            break
    if opt >= 5:
        return True
    return False
ans = []
for i in range(10):
    a = list(input())
    for k in range(10):
        ans.append(a[k])
a = []
for i in range(100):
    if i == '.':
        a.append(diagL(i, ans))
        a.append(diagR(i, ans))
        a.append(sideX(i, ans))
        a.append(sideY(i, ans))

if any(a):
    print('YES')
else:
    print('NO')