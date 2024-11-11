def ukrashenie(lst):
    flag = False
    if lst[0] == 1:
        flag = True
    if lst[0] == 2:
        if lst[1] == 4 and lst[2] == 4:
            flag = True
        if lst[1] == 2 or lst[2] == 2:
            flag = True
    if lst[0] == 3 and lst[1] == 3 and lst[2] == 3:
        flag = True
    if flag is True:
        return "YES"
    return "NO"


k1, k2, k3 = [int(i) for i in input().split()]
print(ukrashenie(sorted([k1, k2, k3])))


