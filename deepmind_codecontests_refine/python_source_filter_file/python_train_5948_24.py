t = input()
index = len(t) // 2
if len(t) % 2 == 0:
    count = 2
    index1 = len(t) // 2 - 1
    s = t[index1] + t[index]
    while count != len(t):
        if count % 2 == 0:
            index1 -= 1
            s += t[index1]
        else:
            index += 1
            s += t[index]
        count += 1
    print(s)
else:
    index1 = index
    count = 1
    s = t[index]
    while count != len(t):
        if count % 2 == 1:
            index1 -= 1
            s += t[index1]
        else:
            index += 1
            s += t[index]
        count += 1
    print(s)
