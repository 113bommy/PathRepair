def Checker(ender):
    global flag
    for i in range(ender):
        if students[i] + 1 != students[i + 1]:
            flag = 1
            break


zapros = int(input())
flag = 0
for q in range(zapros):
    kolvo = int(input())
    students = [int(i) for i in input().split()]
    if kolvo >= 3:
        if students[0] - 1 == students[1] or students[1] - 1 == students[2]:
            students.reverse()
        start = students.index(1)
        if start == 0:
            Checker(kolvo - 1)
        elif start == kolvo - 1:
            Checker(kolvo - 2)
            if students[-2] != kolvo:
                flag = 1
        else:
            for i in range(start, kolvo - 1):
                if students[i] + 1 != students[i + 1]:
                    flag = 1
                    break
            Checker(start - 2)
            if students[start - 1] != kolvo:
                flag = 1
    elif kolvo == 2:
        if (students[0] + 1 != students[1]) and (students[0] - 1 != students[1]):
            flag = 1
    if flag == 0:
        print('YES')
    else:
        print('NO')
    flag = 0
