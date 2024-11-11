n = int(input())
x = list(map(int, input().split()))
sett = set(x)
list_sett = list(sett)
list_sett.sort()
flag = 0
if n == 1:
    print(0)
elif n >= 2:
    if len(sett) == 1:
        print(0)
    elif len(sett) == 2 and (list_sett[1] - list_sett[0]) % 2 == 0:
        print((list(sett)[1] - list_sett[0]) // 2)
    elif len(sett) == 2 and (list_sett[1] - list_sett[0]) % 2 != 0:
        print(list(sett)[1] - list_sett[0])
    elif len(sett) >= 3:
        abc = list_sett[1] - list_sett[0]
        for i in range(2, len(sett)):
            if list_sett[i] - list_sett[i - 1] != abc:
                flag = 1
                break
        if flag == 1:
            print(-1)
        elif flag == 0 and max(list(sett)) - min(list(sett)) <= 2 * abc:
            print(abc)
        else:
            print(-1)
