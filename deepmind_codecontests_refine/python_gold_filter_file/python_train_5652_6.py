from math import log2


def main_f():
    global count
    count = lenth - 1
    i = 0
    for _ in range(count):
        if i < 2 * (lenth // 2):
            if data[i] == data[i + 1] and data[i] == data[i + 2]:
                i += 2
                continue
            r = xor2(data[i], data[i + 1], data[i + 2])
            data[i], data[i + 1], data[i + 2] = r, r, r
            data_r.append([i + 1, i + 2, i + 3])
            i += 2
        else:
            if i == lenth - 1:  # именно поэтому нельзя дальше продолжать работать с i т к он может попасть в верхнюю ветвь
                i = lenth  # иначе будет бесконечно выполняться условие i == lenth - 1 string 18
                j = 0
            if data[j] == data[lenth - 1] and data[j + 1] == data[lenth - 1]:
                j += 2
                continue
            data_r.append([j + 1, j + 2, lenth])
            data[j], data[j + 1] = data[lenth - 1], data[lenth - 1]
            j += 2


def xor2(a, b, c):
    r = a ^ b
    return r ^ c


def xor(a, b, c):
    while True:
        if a == b:
            result = 0
        elif a == 0:
            result = b
        elif b == 0:
            result = a
        elif log2(a) == int(log2(a)) or log2(b) == int(log2(b)):
            result = a + b
        else:
            result = abs(a - b)
        if c == 0:
            return result
        else:
            a = result
            b = c
            c = 0


def res():
    print(len(data_r))
    for el in data_r:
        print(*el)


lenth = int(input())
data = list(map(int, input().split()))
data_r = []
if lenth % 2 == 1:
    main_f()
    if len(set(data)) == 1 and len(data_r) <= lenth:
        print('YES')
        res()
    else:
        print('NO')
else:
    lenth -= 1
    a = data[-1]
    del data[-1]
    main_f()
    if data[-1] == a and len(data_r) <= (lenth + 1):
        print('YES')
        res()
    else:
        print('NO')
