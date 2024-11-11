nn = int(input())


def nb_cadeau(l, santa):
    ss = 0
    ii = 0
    for el in l:
        ss += el
        ii += 1
        if ss > santa:
            return ii - 1
    return ii


for i in range(nn):
    f = list(map(int, input().split(' ')))
    n = f[0]
    s = f[1]
    items = list(map(int, input().split(' ')))
    if sum(items) <= s:
        print(0)
    else:
        cad = nb_cadeau(items, s)
        if cad > 0:
            print(items.index(max(items[:cad+1])) + 1)
        else:
            print(1)
