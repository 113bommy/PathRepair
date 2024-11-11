n = int(input())
a = [(0 if i == 0 else n - i + 1) for i in map(int, input().split())]
b = list(map(int, input().split()))
t = True
s = 0
if 1 in b:
    i = 0
    while b[i] != 1:
        b[i] = 0 if b[i] == 0 else i + n - b[i] + 2
        i += 1
    s = i
    while i < n - 1:
        if b[i + 1] == b[i] + 1:
            i += 1
        else:
            break
    if i == n - 1:
        if s == 0:
            print(0)
        elif max(max(a), max(b[::s])) > s:
            t = False
        else:
            print(s)
    else:
        t = False
    if not t:
        for i in range(s, n):
            b[i] = 0 if b[i] == 0 else i + n - b[i] + 2
        print(max(max(a), max(b)))
else:
    for i in range(n):
        b[i] = 0 if b[i] == 0 else i + n - b[i] + 2
    print(max(max(a), max(b)))
