field = []
for i in range(10):
    s = input().strip()
    field.append(list(s))

def check(i, j):
    ti = i
    tj = j
    if(i + 4 < 10):
        tics = set()
        for it in range(5):
            tics.add(field[ti][tj])
            ti += 1
        if(len(tics) == 1):
            return True
    ti = i
    tj = j
    if(j + 4 < 10):
        tics = set()
        for it in range(5):
            tics.add(field[ti][tj])
            tj += 1
        if(len(tics) == 1):
            return True
    ti = i
    tj = j
    if i + 4 < 10 and j + 4 < 10:
        tics = set()
        for it in range(5):
            tics.add(field[ti][tj])
            ti += 1
            tj += 1
        if(len(tics) == 1):
            return True
    ti = i
    tj = j
    if i - 4 < 10 and j + 4 < 10:
        tics = set()
        for it in range(5):
            tics.add(field[ti][tj])
            ti -= 1
            tj += 1
        if(len(tics) == 1):
            return True
    return False
    

def checkfield():
    for i in range(10):
        for j in range(10):
            if(field[i][j] == 'X'):
                if(check(i, j)):
                    return True
    return False

result = False
for i in range(10):
    for j in range(10):
        if(field[i][j] == '.'):
            field[i][j] = 'X'
            if(checkfield()):
                result = True
                break
            field[i][j] = '.'
    if result:
        break

if result:
    print("YES")
else:
    print("NO")
