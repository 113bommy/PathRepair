def clev(x):
    if x % 4 == 0:
        return x // 4
    elif x % 4 == 1:
        return x // 4 - 1
    elif x % 4 == 2:
        return x // 4
    else:
        return x // 4 - 1


res = [-1, -1, -1, -1, 1, -1, 1, -1, 2, 1, 2, -1, 3, 2, 3, 2, 4, 3, 4, 3, 5]
q = int(input())
for i in range(q):
    n = int(input())
    if n > 20:
        print(clev(n))
    else:
        print(res[n])