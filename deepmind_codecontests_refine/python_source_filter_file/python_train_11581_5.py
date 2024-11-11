def solve():
    a = input()
    b = a[::-1]
    j = 0
    while a[j] == b[j] and j * 2 < len(a) - 1:
        j += 1
    c = a[:j]
    b = b[j:len(b) - j]
    a = a[j:len(a) - j]
    a += '#' + a[::-1]
    b += '#' + b[::-1]
    al = [0] * len(a)
    bl = [0] * len(b)

    for i in range(1, len(a)):
        j = al[i - 1]
        while j > 0 and a[i] != a[j]:
            j = bl[j - 1]
        if a[i] == a[j]:
            j += 1
        al[i] = j
    aa = a[0:al[len(a) - 1]]

    for i in range(1, len(b)):
        j = bl[i - 1]
        while j > 0 and b[i] != b[j]:
            j = bl[j - 1]
        if b[i] == b[j]:
            j += 1
        bl[i] = j
    bb = b[0:bl[len(b) - 1]]

    if len(bb) > len(aa):
        aa = bb
    print(c + aa + c[::-1])


n = int(input())
for i in range(n):
    solve()