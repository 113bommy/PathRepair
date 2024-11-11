class art:
    w = 0
    l = 0

    def __init__(self, A):
        self.w = int(A[0])
        self.l = int(A[1])


def func():
    a = input()
    sp = a.index(' ')
    arg1 = int(a[:sp])
    arg2 = int(a[sp + 1:])
    return arg1, arg2


manag = [(1, 1), (1, 0), (0, 1), (0, 0)]

ramka = art(func())
art1 = art(func())
art2 = art(func())


def right(w1, l1, w2, l2):
    if (max(w1, w2) <= ramka.w) and (l1 + l2 <= ramka.l):
        return True
    else:
        return False


def bottom(w1, l1, w2, l2):
    if (max(l1, l2) <= ramka.l) and (w1 + w2 <= ramka.w):
        return True
    else:
        return False


YES = False
for i in range(0, 3):
    w1 = art1.w
    w2 = art2.w
    l1 = art1.l
    l2 = art2.l
    if manag[i][0] == 0:
        w1, l1 = l1, w1

    if manag[i][1] == 0:
        w2, l2 = l2, w2

    if (right(w1, l1, w2, l2) == True):
        # print(w1, l1, " in right ", w2, l2)
        YES = True
        break
    if (bottom(w1, l1, w2, l2) == True):
        # print(w1, l1, " in bottom", w2, l2)
        YES = True
        break

if(YES==True):
    print("YES")
else:
    print("NO")
